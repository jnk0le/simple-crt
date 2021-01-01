# simple crt
Absolute minimum startup/stub/semihosting code for use with e.g. eclipse iot (mcu on eclipse).

for use with 

`-fno-exceptions` (temporarily)
`-nostartfiles`
`--specs=nano.specs`
`--specs=nosys.specs`

`-nostdlib`/`-nodefaultlibs` is not required. Bloat will be pulled only when appropriate "standard" function is used. 
(adding compiler option to use float with newlib printf/scanf can casue bloat even when printf/scanf is not used)

Device headers can be ripped from e.g. vendor generators or CMSIS packs in eclispe iot.

To define different stack/heap limitations
```
-Wl,--defsym,__min_stack_size__=1024
-Wl,--defsym,__min_heap_size__=4096
```

To disable c++ static initializers (and premature out 96 bytes)
`__CRT_NO_STATIC_INITIALIZERS` have to be globally defined through
compiler flags (project preporties -> preprocessor -> defined symbols (-D))

Virgin openocd+gdb doesn't support live variable view and SWO/ITM.

### semihosting

Implemented according to the spec: https://developer.arm.com/documentation/100863/0300/

To use semihosting, it must be enabled in gdb by `monitor arm semihosting enable`
or "enable arm semihosting" option in eclipse debug startup configuration

Newlib implementation of `printf("")` is caching output until '\n' character (or buffer exahaustion ??? allocates 1kB through malloc)
fprintf(stderr,"") is printing out one character at a time which is extremly slow through semihosting.

stdio.h assumes hardcoded stdin/stdout/stderr handlers to 0,1,2 but obtaining it through proper way by 
opening special ":tt" file assigns a bigger numbers. For me both ways work.

Default stderr handle and ":tt" opened with "a" option print in red font in ide.

To redirect default handlers to ":tt" assignments one of the following macros
```
#define PRINTF_TO_SPECIAL_PATH_TT_STDOUT
#define PRINTF_TO_SPECIAL_PATH_TT_STDERR
```
have to be globally defined.

PRINTF_TO_SPECIAL_PATH_TT_STDERR will redirect printf stdout to stderr (red font, but faster)

