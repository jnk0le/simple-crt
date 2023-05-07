ch32v003 startup code

Vector names are made consistent with WCH code (and `*_IRQn` in headers for peripheral interrupts)

### combotable

It is an isr vector table combined with startup code.
The code and constants can be fitted into empty blocks in-between isr adresses.
Hot loops are kept unscattered to not lose too much performance.