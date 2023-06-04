/*****************************************************************************
 * isr vector table combined with startup code for stm32f070x6               *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

//assumptions:
// - initialized sections are 4 byte aligned (init in 4 byte steps)
// - .bss is right after .data in RAM
// - .preinit_array is right after .data LMA in FLASH
// - .init_array is right after .preinit_array
// - main() doesn't return

.syntax unified
.thumb

.section .isr_vector_table, "ax", %progbits

	// general allocation strategy:
	// r0 - tmp
	// r2 - working mem ptr (.data + .bss)
	// r3 - .data final condition
	// r4 - .bss final condition
	// r5 - LMA data
	// r6 - final cond for static initializers

.global vectors // consistent with c version, should not compile if xxx_vectors.c gets also pulled in
vectors:

	.long __main_stack_end__
	.long Reset_Handler
	.long NMI_Handler
	.long HardFault_Handler

	// 28 bytes available here
2:	ldmia r5!, {r0}
	stmia r2!, {r0}
1:	cmp r2, r3
	bne 2b

	ldr r4, bss_end
	movs r0, #0

#if !defined(__CRT_NO_STATIC_INITIALIZERS)
	ldr r6, init_array_end
	b 3f // branch to cmp first, bss init fits into 8B space

6:	ldmia r5!, {r0}
	blx r0
5:	cmp r5, r6
	bne 6b

	bl main
#else
	b 3f // branch to cmp first, bss init fits into 8B space

5:	bl main

	//padding
	nop
	nop
	nop
	nop
	nop
#endif

	.long SVC_Handler

	// 8 bytes available here
.thumb_func
.global Reset_Handler
Reset_Handler:
	ldr r5, data_init_start
	ldr r2, data_start
	ldr r3, data_end
	b 1b // branch to cmp first and escape from scattered space

	.long PendSV_Handler
	.long SysTick_Handler

	// device irq's

	.long WWDG_IRQHandler

	// 4 bytes available here
.balign 4
data_init_start: 
	.long __data_init_start__

	.long RTC_IRQHandler
	.long FLASH_IRQHandler
	.long RCC_IRQHandler
	.long EXTI0_1_IRQHandler
	.long EXTI2_3_IRQHandler
	.long EXTI4_15_IRQHandler

	// 4 bytes available here
.balign 4
data_start: 
	.long __data_start__

	.long DMA1_Channel1_IRQHandler
	.long DMA1_Channel2_3_IRQHandler
	.long DMA1_Channel4_5_IRQHandler
	.long ADC1_IRQHandler
	.long TIM1_BRK_UP_TRG_COM_IRQHandler
	.long TIM1_CC_IRQHandler

	// 4 bytes available here
.balign 4
data_end: 
	.long __data_end__

	.long TIM3_IRQHandler

	// 8 bytes available here // TIM6_IRQHandler on x8 + TIM7_IRQHandler on xC
4:	stmia r2!, {r0}
3:	cmp r2, r4
	bne 4b
	b 5b  // branch to cmp first and escape from scattered space

	.long TIM14_IRQHandler

	// 4 bytes available here // TIM15_IRQHandler on x8
.balign 4
#if !defined(__CRT_NO_STATIC_INITIALIZERS)
init_array_end:
	.long __init_array_end
#else
	.long 0
#endif

	.long TIM16_IRQHandler
	.long TIM17_IRQHandler
	.long I2C1_IRQHandler

	// 4 bytes available here // I2C2_IRQHandler on x8
.balign 4
bss_end: 
	.long __bss_end__

	.long SPI1_IRQHandler

	// 4 bytes available here // SPI2_IRQHandler on x8

.thumb_func
Default_Handler:
	bkpt #0
	b Default_Handler

	.long USART1_IRQHandler
	.long USART2_IRQHandler
	.long 0
	.long 0
	.long USB_IRQHandler

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

	.weak      USART2_IRQHandler
	.thumb_set USART2_IRQHandler,Default_Handler

	.weak      USB_IRQHandler
	.thumb_set USB_IRQHandler,Default_Handler

#if !defined(STM32F070x6)
	#error "unsupported or unknown MCU"
#endif
