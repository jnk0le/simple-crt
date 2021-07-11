board scripts for stlink v2 clone
![stlinkv2](stlinkv2.jpg)


default scripts expect rst pin to work, which is not the case for those clones.


use with openocd ("config options" in eclipse)

```
-f "board/f0_stlinkv2.cfg"
```

to select one stlink by serial id

```
 -c "hla_serial 00112233445566778899AAFF"
```