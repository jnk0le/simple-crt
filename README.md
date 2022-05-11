# simple crt
Absolute minimum and optimized startup/newlib-stub/semihosting code for use with e.g. eclipse embedded cdt (mcu on eclipse) /w gcc.

for use with 

```
-fno-exceptions (temporarily)
-nostartfiles
--specs=nano.specs
--specs=nosys.specs
```

`-nostdlib`/`-nodefaultlibs` is not required. Bloat will be pulled only when appropriate "standard" function is used. 
(adding compiler option to use float with newlib printf/scanf will casue bloat even when printf/scanf is not used)

Device headers can be ripped from e.g. vendor generators or CMSIS packs available to download in eclispe iot.

To define different stack/heap limitations
```
-Wl,--defsym,__min_stack_size__=1024
-Wl,--defsym,__min_heap_size__=4096
```
note that space "reserved" for stack/heap is counted as used by variables.

To disable c++ static initializers (and premature out 96 bytes)
`__CRT_NO_STATIC_INITIALIZERS` have to be globally (or at last within crt files) defined through
compiler flags (project preporties -> preprocessor -> defined symbols (-D))
`__CRT_NORETURN_FROM_MAIN` will remove deinitializers only. (crashbranch remains)

To properly print sizes of each memory segment (e.g. stm32h7)
```
-Wl,--print-memory-usage
```

Virgin openocd+gdb doesn't support live variable view and SWO/ITM.

### semihosting

Implemented according to the spec: https://developer.arm.com/documentation/100863/0300/

To use semihosting, it must be enabled in gdb by `monitor arm semihosting enable`
or "enable arm semihosting" option in eclipse debug startup configuration

Newlib implementation of `printf("")` is caching output until '\n' character (or buffer exahaustion ??? allocates 1kB through malloc)
`fprintf(stderr,"")` is printing out one character at a time which is extremly slow through semihosting.

stdio.h assumes hardcoded stdin/stdout/stderr handlers to 0,1,2 but obtaining it through proper way by 
opening special ":tt" file assigns a bigger numbers. For me both ways work.

Default stderr handle and ":tt" opened with "a" option print in red font (in my eclipse).

In case of reading from stdin (openocd console in eclipse, pops up by default) followig message will appear after entering line:
`Warn : keep_alive() was not invoked in the 1000 ms timelimit. GDB alive packet not sent! (4688 ms). Workaround: increase "set remotetimeout" in GDB`
of course setting remotetimeout to a larger value doesn't do anything.

Trying to stop program during waiting for stdin will cause a lot of error windows, those can be ok'd through without affecting further execution though.

to avoid it:
- pause first
- write something to console and press enter
- terminate as usual

To redirect default handlers to ":tt" assignments one of the following macros
```
WRITE_REDIRECT_TO_SPECIAL_PATH_TT_STDOUT
WRITE_REDIRECT_TO_SPECIAL_PATH_TT_STDERR
READ_REDIRECT_TO_SPECIAL_PATH_TT_STDIN
```
have to be globally (or at least within semihosting.h) defined.

`WRITE_REDIRECT_TO_SPECIAL_PATH_TT_STDERR` will redirect printf stdout to stderr (red font, but faster)

