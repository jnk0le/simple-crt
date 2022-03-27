Vector names are made consistent with `*_IRQn` in newest device headers

STM32F407xE_ccm.ld puts all sections and stack in ccm giving small perf gain as 
cortex m4 can't pipeline memory transfers spanning across SRAM1 and SRAM2 (or SRAM1 and CCM)

