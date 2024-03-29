ch32v003 startup code

Vector names are made consistent with WCH code (and `*_IRQn` in headers for peripheral interrupts)

svd file is necessary for eclipse peripheral view (debug configurations -> svd path)

Startup code initializes `mtvec` to vectored address entries and `INTSYSCR` to enable
interrupt nesting as well as HPE.
To properly utilize HPE feature, you need a custom build toolchain with `"WCH-Interrupt-fast"` attribute.
e.g. https://github.com/hydrausb3/riscv-none-elf-gcc-xpack/releases/tag/12.2.0-1 \
Otherwise you can use regular `__attribute__((interrupt))` (can disable HPE in `INTSYSCR` later).

The best case scenario would be "standarization" of something like
[prestacked annotation](https://github.com/riscv-non-isa/riscv-c-api-doc/pull/53)
so outdated custom builds of toolchains are no longer needed.

Debugging requires custom fork of openocd. e.g. https://github.com/jnk0le/openocd-wch/releases/ (for windows builds)

### combotable

It is an isr vector table combined with startup code.
The code and constants can be fitted into empty blocks in-between isr adresses.
Hot loops are kept unscattered to not lose too much performance.