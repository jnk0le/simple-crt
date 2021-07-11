/*****************************************************************************
 * isr vector table combined with startup code for stm32f030x4 and f030x6    *
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

	// ldr r3, =__bss_start__ // reuse __data_end__ in r2 as __bss_start__
	// .bss have to be placed right after the .data section
	ldr r5, bss_end
	b 3f // zeroing

6: // bl are 4byte
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
	ldr r2, data_init_start
	ldr r3, data_start
	ldr r4, data_end
	b 2b // branch to cmp first and escape from scattered space

	.long PendSV_Handler
	.long SysTick_Handler

	// device irq's

	.long WWDG_IRQHandler

	// 4 bytes available here
data_init_start: 
	.long __data_init_start__

	.long RTC_IRQHandler
	.long FLASH_IRQHandler
	.long RCC_IRQHandler
	.long EXTI0_1_IRQHandler
	.long EXTI2_3_IRQHandler
	.long EXTI4_15_IRQHandler

	// 4 bytes available here
data_start: 
	.long __data_start__

	.long DMA1_Channel1_IRQHandler
	.long DMA1_Channel2_3_IRQHandler
	.long DMA1_Channel4_5_IRQHandler
	.long ADC1_IRQHandler
	.long TIM1_BRK_UP_TRG_COM_IRQHandler
	.long TIM1_CC_IRQHandler

	// 4 bytes available here
data_end: 
	.long __data_end__

	.long TIM3_IRQHandler

	// 8 bytes available here // TIM6_IRQHandler on x8 + TIM7_IRQHandler on xC
4:	stmia r3!, {r0}
5:	cmp r3, r5
	bne 4b
	b 6b

	.long TIM14_IRQHandler

	// 4 bytes available here // TIM15_IRQHandler on x8
3:	movs r0, #0
	b 5b // branch to cmp first and escape from scattered space

	.long TIM16_IRQHandler
	.long TIM17_IRQHandler
	.long I2C1_IRQHandler

	// 4 bytes available here // I2C2_IRQHandler on x8
bss_end: 
	.long __bss_end__

	.long SPI1_IRQHandler

	// 4 bytes available here // SPI2_IRQHandler on x8

.thumb_func
Default_Handler:
#if defined(DEBUG)
	bkpt #0
#else
	nop // padding
#endif
	b Default_Handler

	.long USART1_IRQHandler
	// USART2_IRQHandler on x8
	// USART3_6_IRQHandler on xC

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

	.weak      ADC1_IRQHandler
	.thumb_set ADC1_IRQHandler,Default_Handler

	.weak      TIM1_BRK_UP_TRG_COM_IRQHandler
	.thumb_set TIM1_BRK_UP_TRG_COM_IRQHandler,Default_Handler

	.weak      TIM1_CC_IRQHandler
	.thumb_set TIM1_CC_IRQHandler,Default_Handler

	.weak      TIM3_IRQHandler
	.thumb_set TIM3_IRQHandler,Default_Handler

	.weak      TIM14_IRQHandler
	.thumb_set TIM14_IRQHandler,Default_Handler

	.weak      TIM16_IRQHandler
	.thumb_set TIM16_IRQHandler,Default_Handler

	.weak      TIM17_IRQHandler
	.thumb_set TIM17_IRQHandler,Default_Handler

	.weak      I2C1_IRQHandler
	.thumb_set I2C1_IRQHandler,Default_Handler

	.weak      SPI1_IRQHandler
	.thumb_set SPI1_IRQHandler,Default_Handler

	.weak      USART1_IRQHandler
	.thumb_set USART1_IRQHandler,Default_Handler

#if !defined(STM32F030x6)
	#error "unsupported or unknown MCU"
#endif
