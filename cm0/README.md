stm32f030f4 is using `STM32F030x6` definition as per the newest 2016 headers (formerly divided into F030 and F030xC only)

Vector names are made consistent with `*_IRQn` in newest device headers

### combotable

It is an isr vector table combined with startup code.
The code and constants can be fitted into empty blocks in-between isr adresses.
Hot loops are kept unscattered to not lose too much performance.

Do not use combotablecrt with xxx_vetors.c. It should fail with `multiple definition of `vectors'; ` message anyway.

`Default_Handler` can't be made an overloadable weak symbol as in C implementation. (`.weak` doesn't work)
Its space also need to be somehow allocated.