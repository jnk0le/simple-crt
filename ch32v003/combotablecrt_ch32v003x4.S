/*****************************************************************************
 * isr vector table combined with startup code for ch32v003x4                *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

//assumptions:
// - application starts at 0x00000000 (default after proper system reset)
// - reset handler is entered by system reset only
// - only the "system" botloader can be used (the one at 0x1ffff000)
// - initialized sections are 4 byte aligned (init in 4 byte steps)
// - __global_pointer$ == __bss_end__ (covers entire SRAM)
// - .bss is right after .data in RAM
// - .preinit_array is right after .data LMA in FLASH
// - .init_array is right after .preinit_array
// - RAM is <= 2KiB
// - main() doesn't return
// - vectored interrupts with HPE and preemption enabled (can be changed later)
// - static destructors are not used

.section .isr_vector_table, "ax", %progbits
.option push
.option norelax

	// general allocation strategy:
	// s0 - LMA data
	// s1 - final cond
	// a0 - tmp
	// a1 - working mem ptr (.data + .bss)
	// a2 - zero (c.sw for .bss and c.lw from vect table)

.global __irq_vector_table
__irq_vector_table:
	// "system" irqs consistent with wch defs, which are mostly copypaste from arm
	// 8 bytes here

	// reset state of `mtvec` is 0 so it can be recycled for zeroing a2
	// while setting up the MODE bits
	// this should also "solve" the interrupt hole
	csrrwi a2, mtvec, (0x00000000 | 0b11) // address entries + vectored mode

	c.lw s0, 60(a2) // __data_init_start__ // of course it doesn't accept labels
	c.j 1f // continue preparing loop

	.word NMI_Handler
	.word HardFault_Handler

	// 32 bytes here
1:
.option norvc
	lui a1, %hi(__data_start__) // 0x20000000
	addi s1, a1, %lo(__data_end__) // __data_end__
.option rvc

	c.j 2f // need to skip in case of empty section
3:	c.lw a0, (s0)
	c.addi s0, 4
	c.sw a0, (a1)
	c.addi a1, 4
2:	bne a1, s1, 3b

.option norvc
	addi s1, s1, %lo(__bss_size__) // __bss_end__
.option rvc

	// Prepare stack ahead of calling constructors.
	// Stack top uses annoying constant so we need a workaround for <8 byte sequence.
	// Will sacrifice 4 bytes of stack in case of 0 bytes in data+bss.
	// It is a rare case where the entire stack space is not going to be used anyway.
	// The alternative is addi + c.addi but that will always be 6 byte sequence due to the
	// way, linker symbols work (limited/no compiler optimizations, cannot conditionally compile on them)
.option norvc
	addi sp, s1, %lo(__ch32v003_bsstostack_offset__)
.option rvc

	c.j 4f // zero skip in bss loop directly

	.word SysTick_Handler

	// 4 bytes here
	// 52 bytes from base
#if !defined(__CRT_NO_STATIC_INITIALIZERS)
	.word __init_array_end
#else
	.word 0
#endif

	.word SW_Handler

	// 4 bytes here
	// 60 bytes from base
	.word __data_init_start__

	// device irqs, consistent with irqn from header as well stock defs
	.word WWDG_IRQHandler
	.word PVD_IRQHandler
	.word FLASH_IRQHandler
	.word RCC_IRQHandler
	.word EXTI7_0_IRQHandler
	.word AWU_IRQHandler
	.word DMA1_Channel1_IRQHandler
	.word DMA1_Channel2_IRQHandler
	.word DMA1_Channel3_IRQHandler
	.word DMA1_Channel4_IRQHandler
	.word DMA1_Channel5_IRQHandler
	.word DMA1_Channel6_IRQHandler
	.word DMA1_Channel7_IRQHandler
	.word ADC_IRQHandler
	.word I2C1_EV_IRQHandler
	.word I2C1_ER_IRQHandler
	.word USART1_IRQHandler
	.word SPI1_IRQHandler
	.word TIM1_BRK_IRQHandler
	.word TIM1_UP_IRQHandler
	.word TIM1_TRG_COM_IRQHandler
	.word TIM1_CC_IRQHandler
	.word TIM2_IRQHandler

.option pop

5:	c.sw a2, (a1)
	c.addi a1, 4
4:	bne a1, s1, 5b


.option push
.option norelax
	c.mv gp, s1 // __global_pointer$ @ __bss_end__
.option pop

#if !defined(__CRT_NO_STATIC_INITIALIZERS)
	// call static constructors (c++ and attribute ones), only s0, s1 are preserved
	c.lw s1, 52(a2) // __init_array_end // of course it doesn't accept labels

	c.j 6f // need to skip in case of empty section
7:	c.lw a0, (s0)
	c.addi s0, 4
	c.jalr a0
6:	bne s0, s1, 7b
#endif

	// INTSYSCR - enable interrupt nesting and HPE
	csrwi 0x804, 0b11

	// enable irq
	li t0, 0x88 // must write MIE with MPIE otherwise no effect
	csrw mstatus, t0 // use csrw to cleanup upper bits

	call main

	// default handler serves also as a trap in case main returns
Default_Handler:
1:	c.ebreak
	c.j 1b

	.weak NMI_Handler
	.set NMI_Handler, Default_Handler

	.weak HardFault_Handler
	.set HardFault_Handler, Default_Handler

	.weak SysTick_Handler
	.set SysTick_Handler, Default_Handler

	.weak SW_Handler
	.set SW_Handler, Default_Handler

	.weak WWDG_IRQHandler
	.set WWDG_IRQHandler, Default_Handler

	.weak PVD_IRQHandler
	.set PVD_IRQHandler, Default_Handler

	.weak FLASH_IRQHandler
	.set FLASH_IRQHandler, Default_Handler

	.weak RCC_IRQHandler
	.set RCC_IRQHandler, Default_Handler

	.weak EXTI7_0_IRQHandler
	.set EXTI7_0_IRQHandler, Default_Handler

	.weak AWU_IRQHandler
	.set AWU_IRQHandler, Default_Handler

	.weak DMA1_Channel1_IRQHandler
	.set DMA1_Channel1_IRQHandler, Default_Handler

	.weak DMA1_Channel2_IRQHandler
	.set DMA1_Channel2_IRQHandler, Default_Handler

	.weak DMA1_Channel3_IRQHandler
	.set DMA1_Channel3_IRQHandler, Default_Handler

	.weak DMA1_Channel4_IRQHandler
	.set DMA1_Channel4_IRQHandler, Default_Handler

	.weak DMA1_Channel5_IRQHandler
	.set DMA1_Channel5_IRQHandler, Default_Handler

	.weak DMA1_Channel6_IRQHandler
	.set DMA1_Channel6_IRQHandler, Default_Handler

	.weak DMA1_Channel7_IRQHandler
	.set DMA1_Channel7_IRQHandler, Default_Handler

	.weak ADC_IRQHandler
	.set ADC_IRQHandler, Default_Handler

	.weak I2C1_EV_IRQHandler
	.set I2C1_EV_IRQHandler, Default_Handler

	.weak I2C1_ER_IRQHandler
	.set I2C1_ER_IRQHandler, Default_Handler

	.weak USART1_IRQHandler
	.set USART1_IRQHandler, Default_Handler

	.weak SPI1_IRQHandler
	.set SPI1_IRQHandler, Default_Handler

	.weak TIM1_BRK_IRQHandler
	.set TIM1_BRK_IRQHandler, Default_Handler

	.weak TIM1_UP_IRQHandler
	.set TIM1_UP_IRQHandler, Default_Handler

	.weak TIM1_TRG_COM_IRQHandler
	.set TIM1_TRG_COM_IRQHandler, Default_Handler

	.weak TIM1_CC_IRQHandler
	.set TIM1_CC_IRQHandler, Default_Handler

	.weak TIM2_IRQHandler
	.set TIM2_IRQHandler, Default_Handler

#if !defined(CH32V003x4)
	#error "unsupported or unknown MCU"
#endif
