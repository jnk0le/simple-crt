/*****************************************************************************
 * isr vector table combined with startup code for stm32l010x4, x6, x8, xB   *
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

.global __irq_vector_table // consistent with c version, should not compile if xxx_vectors.c gets also pulled in
__irq_vector_table:
	.long __main_stack_end__
	.long Reset_Handler
	.long NMI_Handler
	.long HardFault_Handler

	// 28 bytes available here
2:	ldmia r5!, {r0}
	stmia r2!, {r0}
1:	cmp r2, r3
	bne 2b

	movs r0, #0
	b 3f // branch to cmp first, bss init fits into 8B space
	
#if !defined(__CRT_NO_STATIC_INITIALIZERS)

6:	ldmia r5!, {r0}
	blx r0
5:	cmp r5, r6
	bne 6b
	
	bl main
	
	// padding
	b .
	nop
#else
5:	bl main
	
	// padding
	b .
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
	adr r0, mem_init_symbols
	ldmia r0!, {r2,r3,r4,r5}
#if !defined(__CRT_NO_STATIC_INITIALIZERS)
	ldr r6, init_array_end
	b 2b
#else
	b 2b // branch to cmp first and escape from scattered space
	nop // padding
#endif

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

#if defined(STM32L010x4)
	.long DMA1_Channel4_5_IRQHandler
#else
	.long DMA1_Channel4_5_6_7IRQHandler
#endif
	
	.long ADC1_COMP_IRQHandler
	.long LPTIM1_IRQHandler
	
	// 4 bytes available here
.balign 4
#if !defined(__CRT_NO_STATIC_INITIALIZERS)
init_array_end:
	.long __init_array_end
#else
	.long 0
#endif
	
	.long TIM2_IRQHandler

	// 16 bytes available here
.balign 4
mem_init_symbols:
	.long __data_start__ // r2
	.long __data_end__ // r3
	.long __bss_end__ // r4
	.long __data_init_start__ // r5

	.long TIM21_IRQHandler
	.long 0

#if defined(STM32L010xB)
	.long TIM22_IRQHandler
#else
	.long 0
#endif
	.long I2C1_IRQHandler

	// 4 bytes available here

.thumb_func
Default_Handler:
	bkpt #0
	b Default_Handler

	.long SPI1_IRQHandler

	// 8 bytes available here
4:	stmia r2!, {r0}
3:	cmp r2, r4
	bne 4b
	b 5b  // branch to cmp first and escape from scattered space

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

#if defined(STM32L010x4)
	.weak      DMA1_Channel4_5_IRQHandler
	.thumb_set DMA1_Channel4_5_IRQHandler,Default_Handler
#else
	.weak      DMA1_Channel4_5_6_7IRQHandler
	.thumb_set DMA1_Channel4_5_6_7IRQHandler,Default_Handler
#endif

	.weak      ADC1_COMP_IRQHandler
	.thumb_set ADC1_COMP_IRQHandler,Default_Handler

	.weak      LPTIM1_IRQHandler
	.thumb_set LPTIM1_IRQHandler,Default_Handler

	.weak      TIM2_IRQHandler
	.thumb_set TIM2_IRQHandler,Default_Handler

	.weak      TIM21_IRQHandler
	.thumb_set TIM21_IRQHandler,Default_Handler

#if defined(STM32L010xB)
	.weak      TIM22_IRQHandler
	.thumb_set TIM22_IRQHandler,Default_Handler
#endif

	.weak      I2C1_IRQHandler
	.thumb_set I2C1_IRQHandler,Default_Handler

	.weak      SPI1_IRQHandler
	.thumb_set SPI1_IRQHandler,Default_Handler

	.weak      USART2_IRQHandler
	.thumb_set USART2_IRQHandler,Default_Handler

	.weak      LPUART1_IRQHandler
	.thumb_set LPUART1_IRQHandler,Default_Handler

#if !defined(STM32L010x4)&&!defined(STM32L010x6)&&!defined(STM32L010x8)&&!defined(STM32L010xB)
	#error "unsupported or unknown MCU"
#endif
