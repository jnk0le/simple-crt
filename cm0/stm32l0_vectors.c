/*****************************************************************************
 * STM32L0 vector table definitions                                          *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
 * License: CC0                                                              *
 *****************************************************************************/

	__attribute__((weak)) void Default_Handler(void); // [-Wmissing-prototypes]
	__attribute__((weak)) void Default_Handler(void)
	{
	#ifdef DEBUG
		while(1) asm volatile("bkpt #0");
	#else
		while(1);
	#endif
	}

	void __attribute__ ((weak, alias("Default_Handler"))) NMI_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HardFault_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SVC_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PendSV_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SysTick_Handler(void);

#if defined(__ARM_ARCH_7M__)||defined(__ARM_ARCH_7EM__)
	void __attribute__ ((weak, alias("Default_Handler"))) MemManage_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BusFault_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UsageFault_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DebugMon_Handler(void);
#endif

#if defined(STM32L010x4)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM21_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPUART1_IRQHandler(void);

#elif defined(STM32L010x6)||defined(STM32L010x8)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_5_6_7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM21_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPUART1_IRQHandler(void);
		
#elif defined(STM32L010xB)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_5_6_7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM21_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM22_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPUART1_IRQHandler(void);

#elif defined(STM32L011xx)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_COMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM21_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPUART1_IRQHandler(void);
#else
	#error "unsupported or unknown MCU"
#endif


	extern const int __main_stack_end__;   // import main stack end (from linker script)
	extern void Reset_Handler(void);       // import the address of Reset_Handler()

	void (*const vectors[])(void) __attribute__((used, section(".isr_vector_table"))) =
	{
		(void (*)(void))&__main_stack_end__,
		Reset_Handler,
		NMI_Handler,
		HardFault_Handler,
	#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
		MemManage_Handler,
		BusFault_Handler,
		UsageFault_Handler,
	#else
		0,
		0,
		0,
	#endif
		0,
		0,
		0,
		0,
		SVC_Handler,
	#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
		DebugMon_Handler,
	#else
		0,
	#endif
		0,
		PendSV_Handler,
		SysTick_Handler,

#if defined(STM32L010x4)
		WWDG_IRQHandler,
		0,
		RTC_IRQHandler,
		FLASH_IRQHandler,
		RCC_IRQHandler,
		EXTI0_1_IRQHandler,
		EXTI2_3_IRQHandler,
		EXTI4_15_IRQHandler,
		0,
		DMA1_Channel1_IRQHandler,
		DMA1_Channel2_3_IRQHandler,
		DMA1_Channel4_5_IRQHandler,
		ADC1_IRQHandler,
		LPTIM1_IRQHandler,
		0,
		TIM2_IRQHandler,
		0,
		0,
		0,
		0,
		TIM21_IRQHandler,
		0,
		0,
		I2C1_IRQHandler,
		0,
		SPI1_IRQHandler,
		0,
		0,
		USART2_IRQHandler,
		LPUART1_IRQHandler,
#elif defined(STM32L010x6)||defined(STM32L010x8)
		WWDG_IRQHandler,
		0,
		RTC_IRQHandler,
		FLASH_IRQHandler,
		RCC_IRQHandler,
		EXTI0_1_IRQHandler,
		EXTI2_3_IRQHandler,
		EXTI4_15_IRQHandler,
		0,
		DMA1_Channel1_IRQHandler,
		DMA1_Channel2_3_IRQHandler,
		DMA1_Channel4_5_6_7_IRQHandler,
		ADC1_IRQHandler,
		LPTIM1_IRQHandler,
		0,
		TIM2_IRQHandler,
		0,
		0,
		0,
		0,
		TIM21_IRQHandler,
		0,
		0,
		I2C1_IRQHandler,
		0,
		SPI1_IRQHandler,
		0,
		0,
		USART2_IRQHandler,
		LPUART1_IRQHandler,
#elif defined(STM32L010xB)
		WWDG_IRQHandler,
		0,
		RTC_IRQHandler,
		FLASH_IRQHandler,
		RCC_IRQHandler,
		EXTI0_1_IRQHandler,
		EXTI2_3_IRQHandler,
		EXTI4_15_IRQHandler,
		0,
		DMA1_Channel1_IRQHandler,
		DMA1_Channel2_3_IRQHandler,
		DMA1_Channel4_5_6_7_IRQHandler,
		ADC1_IRQHandler,
		LPTIM1_IRQHandler,
		0,
		TIM2_IRQHandler,
		0,
		0,
		0,
		0,
		TIM21_IRQHandler,
		0,
		TIM22_IRQHandler,
		I2C1_IRQHandler,
		0,
		SPI1_IRQHandler,
		0,
		0,
		USART2_IRQHandler,
		LPUART1_IRQHandler,
#elif defined(STM32L011xx)
		WWDG_IRQHandler,
		PVD_IRQHandler,
		RTC_IRQHandler,
		FLASH_IRQHandler,
		RCC_IRQHandler,
		EXTI0_1_IRQHandler,
		EXTI2_3_IRQHandler,
		EXTI4_15_IRQHandler,
		0,
		DMA1_Channel1_IRQHandler,
		DMA1_Channel2_3_IRQHandler,
		DMA1_Channel4_5_IRQHandler,
		ADC1_COMP_IRQHandler,
		LPTIM1_IRQHandler,
		0,
		TIM2_IRQHandler,
		0,
		0,
		0,
		0,
		TIM21_IRQHandler,
		0,
		0,
		I2C1_IRQHandler,
		0,
		SPI1_IRQHandler,
		0,
		0,
		USART2_IRQHandler,
		LPUART1_IRQHandler,
#else
	#error "unsupported or unknown MCU"
#endif

