/*****************************************************************************
 * isr vector table combined with startup code for stm32l011x3 and l011x4    *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
 * License: CC0                                                              *
 *****************************************************************************/

.syntax unified
.thumb

.section .isr_vector_table, "ax", %progbits

.global vectors // consistent with c version, should not compile if xxx_vectors.c gets also pulled in
vectors:

	.long __main_stack_end__
	.long Reset_Handler
	.long NMI_Handler
	.long HardFault_Handler

	// 28 bytes available here
1:	ldmia r2!, {r0}
	stmia r3!, {r0}
2:	cmp r3, r4
	bne 1b

	movs r0, #0
	b 4f // branch to cmp first and escape from scattered space

5: // bl are 4byte
#ifndef __CRT_NO_STATIC_INITIALIZERS
	bl __run_init_array
	bl main
#else
	bl main // just call main faster
	nop // padding
	nop // padding
#endif

#if !defined(__CRT_NO_STATIC_INITIALIZERS)&&!defined(__CRT_NORETURN_FROM_MAIN)
	bl __run_fini_array
#else
	nop // padding
	nop // padding
#endif

	b .
	nop // padding

	.long SVC_Handler

	// 8 bytes available here
.thumb_func
.global Reset_Handler

Reset_Handler:
	adr r0, mem_init_symbols
	ldmia r0!, {r2,r3,r4,r5}
	b 2b // branch to cmp first and escape from scattered space
	nop // padding

	.long PendSV_Handler
	.long SysTick_Handler

	// device irq's

	.long WWDG_IRQHandler
	.long PVD_IRQHandler
	.long RTC_IRQHandler
	.long FLASH_IRQHandler
	.long RCC_IRQHandler
	.long EXTI0_1_IRQHandler
	.long EXTI2_3_IRQHandler
	.long EXTI4_15_IRQHandler
	.long 0
	.long DMA1_Channel1_IRQHandler
	.long DMA1_Channel2_3_IRQHandler
	.long DMA1_Channel4_5_IRQHandler
	.long ADC1_COMP_IRQHandler
	.long LPTIM1_IRQHandler
	.long 0
	.long TIM2_IRQHandler

	// 16 bytes available here
mem_init_symbols:
	.long __data_init_start__ // r2
	.long __data_start__ // r3
	.long __data_end__ // r4
	.long __bss_end__ // r5

	.long TIM21_IRQHandler
	.long 0
	.long 0
	.long I2C1_IRQHandler

	// 4 bytes available here

.thumb_func
Default_Handler:
	bkpt #0
	b Default_Handler

	.long SPI1_IRQHandler

	// 8 bytes available here

3:	stmia r3!, {r0}
4:	cmp r3, r5
	bne 3b
	b 5b

	.long USART2_IRQHandler
	.long LPUART1_IRQHandler

	// weak assignments to Default_Handler

	.weak      NMI_Handler
	.thumb_set NMI_Handler,Default_Handler

	.weak      HardFault_Handler
	.thumb_set HardFault_Handler,Default_Handler

	.weak      SVC_Handler
	.thumb_set SVC_Handler,Default_Handler

	.weak      PendSV_Handler
	.thumb_set PendSV_Handler,Default_Handler

	.weak      SysTick_Handler
	.thumb_set SysTick_Handler,Default_Handler

	.weak      WWDG_IRQHandler
	.thumb_set WWDG_IRQHandler,Default_Handler

	.weak      PVD_IRQHandler
	.thumb_set PVD_IRQHandler,Default_Handler

	.weak      RTC_IRQHandler
	.thumb_set RTC_IRQHandler,Default_Handler

	.weak      FLASH_IRQHandler
	.thumb_set FLASH_IRQHandler,Default_Handler

	.weak      RCC_IRQHandler
	.thumb_set RCC_IRQHandler,Default_Handler

	.weak      EXTI0_1_IRQHandler
	.thumb_set EXTI0_1_IRQHandler,Default_Handler

	.weak      EXTI2_3_IRQHandler
	.thumb_set EXTI2_3_IRQHandler,Default_Handler

	.weak      EXTI4_15_IRQHandler
	.thumb_set EXTI4_15_IRQHandler,Default_Handler

	.weak      DMA1_Channel1_IRQHandler
	.thumb_set DMA1_Channel1_IRQHandler,Default_Handler

	.weak      DMA1_Channel2_3_IRQHandler
	.thumb_set DMA1_Channel2_3_IRQHandler,Default_Handler

	.weak      DMA1_Channel4_5_IRQHandler
	.thumb_set DMA1_Channel4_5_IRQHandler,Default_Handler

	.weak      ADC1_COMP_IRQHandler
	.thumb_set ADC1_COMP_IRQHandler,Default_Handler

	.weak      LPTIM1_IRQHandler
	.thumb_set LPTIM1_IRQHandler,Default_Handler

	.weak      TIM2_IRQHandler
	.thumb_set TIM2_IRQHandler,Default_Handler

	.weak      TIM21_IRQHandler
	.thumb_set TIM21_IRQHandler,Default_Handler

	.weak      I2C1_IRQHandler
	.thumb_set I2C1_IRQHandler,Default_Handler

	.weak      SPI1_IRQHandler
	.thumb_set SPI1_IRQHandler,Default_Handler

	.weak      USART2_IRQHandler
	.thumb_set USART2_IRQHandler,Default_Handler

	.weak      LPUART1_IRQHandler
	.thumb_set LPUART1_IRQHandler,Default_Handler

#if !defined(STM32L011xx)
	#error "unsupported or unknown MCU"
#endif
