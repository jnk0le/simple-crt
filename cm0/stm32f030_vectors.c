/*****************************************************************************
 * STM32F030 vector table definitions                                       *
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

#if defined(STM32F030x6)
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
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);

#elif defined(STM32F030x8)
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
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);

#elif defined(STM32F030xC)
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
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_6_IRQHandler(void);
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
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		SVC_Handler,
		0,
		0,
		PendSV_Handler,
		SysTick_Handler,

	#if defined(STM32F030x6)
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
		TIM1_BRK_UP_TRG_COM_IRQHandler,
		TIM1_CC_IRQHandler,
		0,
		TIM3_IRQHandler,
		0,
		0,
		TIM14_IRQHandler,
		0,
		TIM16_IRQHandler,
		TIM17_IRQHandler,
		I2C1_IRQHandler,
		0,
		SPI1_IRQHandler,
		0,
		USART1_IRQHandler,
	#elif defined(STM32F030x8)
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
		TIM1_BRK_UP_TRG_COM_IRQHandler,
		TIM1_CC_IRQHandler,
		0,
		TIM3_IRQHandler,
		0,
		0,
		TIM14_IRQHandler,
		TIM15_IRQHandler,
		TIM16_IRQHandler,
		TIM17_IRQHandler,
		I2C1_IRQHandler,
		I2C2_IRQHandler,
		SPI1_IRQHandler,
		SPI2_IRQHandler,
		USART1_IRQHandler,
		USART2_IRQHandler,
	#elif defined(STM32F030xC)
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
		TIM1_BRK_UP_TRG_COM_IRQHandler,
		TIM1_CC_IRQHandler,
		0,
		TIM3_IRQHandler,
		TIM6_IRQHandler,
		TIM7_IRQHandler,
		TIM14_IRQHandler,
		TIM15_IRQHandler,
		TIM16_IRQHandler,
		TIM17_IRQHandler,
		I2C1_IRQHandler,
		I2C2_IRQHandler,
		SPI1_IRQHandler,
		SPI2_IRQHandler,
		USART1_IRQHandler,
		USART2_IRQHandler,
		USART3_6_IRQHandler,
	#else
		#error "unsupported or unknown MCU"
	#endif
	};


#if !defined(__ARM_ARCH_6M__)
	#error "wrong architecture"
#endif