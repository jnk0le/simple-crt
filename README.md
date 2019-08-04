# simple crt
 
To define different stack/heap limitations
```
-Wl,--defsym,__min_stack_size__=1024
-Wl,--defsym,__min_heap_size__=4096
```

To disable c++ static initializers (and premature out 96 bytes) `__CRT_NO_STATIC_INITIALIZERS` have to be globally defined through compiler flags (project preporties -> preprocessor -> defined symbols (-D))