Cursed RA8 startup files, designated for openocd debugging which is intentionally unsupported by Renesas
due to decision of their "marketing team".\
Supports RA8D1 (aka R7FA8D1BHEC aka A8D1BHEC) chip, should work also for RA8M1, RA8T1 and variants.

As in openocd, there is no flash loader for RA8, only preloading code to SRAM is possible.

## initial preparation

You will need "renesas flash programmer" tool:

https://www.renesas.com/us/en/software-tool/renesas-flash-programmer-programming-gui#overview

Connect it through USB ("USB-OTG" port on RT-Thread vision board) or SCI (uart).

Current version is of course bugged.\
Target device has to be reset after each operation (e.g. flashing or reading) or you will
get "Error(E3000105): The device is not responding." on subsequent action/access attempt

After resetting you need to hold BOOT key until connected by the tool.\
If you have already created "project" then connection is established by selecting operations like
flashing (start button) or reading device information etc.

First step is to libarate the uC from any present applications and reset it to factory default.\
Otherwise your application/debugging will freeze or enter undebuggable hardfault.

To do this you need to select "Initialize Device" in "Target Device" menu

Now device is in factory state in which the debugging is (of course) not possible.\
To unbrick, flash in the `RA8_factory_unbrick.hex` file using the same tool.

## IDAU

RT-Thread vison board comes with all areas programmed to flat mode (all secure). I belive
that the virgin chips also come with flat mode.

Therefore no action is required in those cases.

It seems that the IDAU is more limited than the one on RA6 as there is only code and data secure area (no SRAM, or NSC),
even though all datasheets talk about SRAM and peripheral IDAU regions.
https://www.mouser.com/pdfDocs/r01an7087eu0100-ra8-mcu-quick-design-guide.pdf

To read current idau zones you need to select "Read Flash Options" in "Target Device" menu.

To program new zones,\
in "Flash Options" tab, in "Boundary" set:
- "Set Option" to "Set"
- "Code Secure Size [KB]" to "16352"
- "Data Secure Size [KB]" to "63"

then in "Operation Settings" tab, "Command" area:
- set "Program Flash Options"
- uncheck everything else

then in "Operation" tab click start.

## trustzone support

Don't use.\
Core starts up in secure mode and should stay in it.

## openocd/gdb conf

openocd params for RT-Thread vision board builtin debugger is:
```
-f "interface/cmsis-dap.cfg" -f "C:\path\to\your\file\R7FA8D1.cfg"
```

In my case gdb "magically" knows to jump to 0x22000000 after loading.\
I would recommend to not rely on this and instruct the debugger to jump 
there by: `set $pc=0x22000000`, or use "Set program counter at (hex)" box 
in eclipse (Debug Configurations -> Startup)

It is recommended to use "Debug in RAM" option (in eclipse: Debug Configurations -> Startup)

## cortex-m85 setup

On cortex-m85 fpu/helium (CP10,CP11), branch predictor, LOB and I/D caches have to be enabled to achieve advertised performance.
Current startup code enables only FPU/helium.\
https://community.arm.com/arm-community-blogs/b/architectures-and-processors-blog/posts/armv8_2d00_m-based-processor-software-development-hints-and-tips

```
	__DSB();
	__ISB();
	SCB->CCR |= SCB_CCR_IC_Msk | SCB_CCR_DC_Msk | SCB_CCR_LOB_Msk | SCB_CCR_BP_Msk;
	__DSB();
	__ISB();
```

ECC in ITCM and DTCM memories is enabled by default and cannot be disabled by `MEMSYSCTL->{I,D}TCMCR` enable bits.
(SRAM ECC is disabled by default)

If stack is to be allocated inside DTCM, then the entire area must be initialized (zeroed) to avoid ECC errors
(precise bus faults), when the code allocates byte or halfword buffers on stack.
(e.g `printf("test %d", 1234)` is doing that)

ITCM must be initialized by doubleword (8 byte) stores to clear ECC errors.

### errata `3190818` and `3175626`

Enabling DCACHE (on r0p2 cm85) will result in subsequent crash (e.g. preceding printf reexecuted
infinitely, printing out message with additional garbage)

Particularly fix for `3175626` must be applied as execution from sram won't work without it.

Applying fix for `3190818` didn't make observable difference in my case.\
Same fix is applied to another erratum (`2705514`).

Renesas errata is written in chinglish, so condition "b" and "c" mean that SRAM banks cannot be simultaneously
acccessed by core and DMA when using writeback cache.

```
	MEMSYSCTL->MSCR |= MEMSYSCTL_MSCR_FORCEWT_Msk; // errata 3175626
	ICB->ACTLR |= (1 << 16); // errata 3190818
	__DSB();
	__ISB();
	SCB->CCR |= SCB_CCR_IC_Msk | SCB_CCR_DC_Msk;
	__DSB();
	__ISB();
```

## notes

- expected `$_CPUTAPID` is ignored by openocd, debug session reads `SWD DPIDR 0x6ba02477`

- if openocd experiences ECC error while reading memory, then the debugger doesn't show anything in there.
(openocd console will show "Error: Failed to read memory at 0x20000000")

- vector table covers only the standard ARM irqs 

- `R7FA8D1BH.h` file has `IRQn_Type` typedef readded, (only standard ARM irqs), stock renesans headers are
missing it which causes errors.

- svd files can be extracted from renesas DFP packages

- to debug NVIC registers use `Generic_V8M.svd` file (extracted from https://github.com/ARM-software/CMSIS_5/issues/844#issuecomment-1217164658)
It's missing some bits and many descriptions are of course, an exact inverse of actual behaviour.

- instruction level breakpoints, and C level breakpoints outside main(), are broken and will prevent any further
execution (by singlestepping or "continue") when reached.\
It is possible to "unlock" by forcing `pc` to next instruction address. The instruction at offending breakpoint 
will not commit its results.\
Only `bkpt #0` (available as `__BKPT()`) instruction works as expected.
