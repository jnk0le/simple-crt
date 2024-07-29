Cursed RA8 startup files, designated for openocd debugging which is intentionally unsupported by Renesas
due to decision of their "marketing team".\
Supports RA8D1 (aka R7FA8D1BHEC aka A8D1BHEC) chip, should work also for RA8M1, RA8T1 and variants.

As in openocd, there is no flash loader for RA8, only preloading code to SRAM is possible.

## initial preparation

You will need "renesas flash programmer" tool:

https://www.renesas.com/us/en/software-tool/renesas-flash-programmer-programming-gui#overview

Current version is of course bugged.\
Device has to be reset after each operation (e.g. flashing or reading) or you will
get "Error(E3000105): The device is not responding." on subsequent action/access attempt

After resetting you need to hold BOOT key until connected by the tool.\
If you have already created "project" then connection is established by selecting operations like
flashing (start button) or reading device information etc.

First step is to libarate the uC from any present applications (e.g. RT-thread vision board has such)
and reset it to factory default.\
Otherwise your debugged application/debugging will freeze, usually at `main()`
breakpoint or enter undebuggable hardfault.

To do this you need to select "Initialize Device" in "Target Device" menu

Now device is in fatory state in which the debugging is (of course) not possible.\
To unbrick, flash in the `RA8_factory_unbrick.hex` file using the same tool.

## idau BS

TBD, printf helloworld works so far

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

## notes

- expected `$_CPUTAPID` is ignored by openocd, debug session reads "SWD DPIDR 0x6ba02477"

- debugger has issues with reading DTCM/ITCM (all aliases), only disassembler shows something in there

- vector table covers only the standard ARM irqs 

- `R7FA8D1BH.h` file has `IRQn_Type` typedef readded, (only standard ARM irqs), stock renesans headers are
missing it which causes errors.