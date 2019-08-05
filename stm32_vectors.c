/*****************************************************************************
 * STM32 mass vector table definitions                                       *
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

#if defined(STM32F030)
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

#elif defined(STM32F031)
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
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);

#elif defined(STM32F042)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_VDDIO2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_CRS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TSC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CEC_CAN_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_IRQHandler(void);

#elif defined(STM32F051)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TSC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_COMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
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
	void __attribute__ ((weak, alias("Default_Handler"))) CEC_IRQHandler(void);

#elif defined (STM32F070x6)
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
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_IRQHandler(void);

#elif defined (STM32F070xB)
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
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
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
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_IRQHandler(void);

#elif defined (STM32F072)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_VDDIO2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_CRS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TSC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_COMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
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
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CEC_CAN_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_IRQHandler(void);

#elif defined (STM32F091)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_VDDIO2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_CRS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TSC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_COMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
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
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_8_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CEC_CAN_IRQHandler(void);

#elif defined(STM32F10X_LD)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_HP_CAN1_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_LP_CAN1_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTCAlarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBWakeUp_IRQHandler(void);

#elif defined(STM32F10X_LD_VL)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_TIM15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTCAlarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CEC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);

#elif defined(STM32F10X_MD)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_HP_CAN_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_LP_CAN_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTCAlarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBWakeup_IRQHandler(void);

#elif defined(STM32F10X_MD_VL)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_TIM15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTCAlarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CEC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);

#elif defined(STM32F10X_HD)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_HP_CAN1_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_LP_CAN1_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTCAlarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBWakeUp_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_BRK_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_UP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FSMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SDIO_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel4_5_IRQHandler(void);

#elif defined(STM32F10X_HD_VL)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_TIM15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTCAlarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CEC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM12_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM13_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel4_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel5_IRQHandler(void);

#elif defined(STM32F10X_XL)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_HP_CAN1_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_LP_CAN1_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_TIM9_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_TIM10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM11_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTCAlarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBWakeUp_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_BRK_TIM12_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_UP_TIM13_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_TRG_COM_TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FSMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SDIO_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel4_5_IRQHandler(void);

#elif defined(STM32F10X_CL)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTCAlarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ETH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ETH_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_IRQHandler(void);

#elif defined(STM32F30X)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_STAMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_TS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC1_2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_HP_CAN1_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_LP_CAN1_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_TIM15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_Alarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBWakeUp_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_BRK_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_UP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) COMP1_3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) COMP4_6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) COMP7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C3_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C3_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_HP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USB_LP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBWakeUp_RMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM20_BRK_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM20_UP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM20_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM20_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FPU_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI4_IRQHandler(void);

#elif defined(STM32F405xx)||defined(STM32F407xx)||defined(STM32F415xx)||defined(STM32F417xx)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMP_STAMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_TIM9_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_TIM10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM11_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_Alarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_BRK_TIM12_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_UP_TIM13_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_TRG_COM_TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SDIO_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ETH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ETH_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C3_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C3_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_EP1_OUT_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_EP1_IN_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DCMI_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CRYP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HASH_RNG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FPU_IRQHandler(void);

#elif defined(STM32F427xx)||defined(STM32F429xx)||defined(STM32F437xx)||defined(STM32F439xx)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMP_STAMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_TIM9_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_TIM10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM11_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_Alarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_BRK_TIM12_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_UP_TIM13_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_TRG_COM_TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SDIO_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ETH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ETH_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN2_SCE_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C3_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C3_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_EP1_OUT_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_EP1_IN_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DCMI_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CRYP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HASH_RNG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FPU_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART8_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SAI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LTDC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LTDC_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2D_IRQHandler(void);

#elif defined(GD32F450)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDGT_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMPER_STAMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCU_CTC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA0_Channel0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA0_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA0_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA0_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA0_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA0_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA0_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN0_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN0_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN0_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN0_EWMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI5_9_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER0_BRK_TIMER8_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER0_UP_TIMER9_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER0_TRG_CMT_TIMER10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER0_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C0_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C0_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI10_15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_Alarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBFS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER7_BRK_TIMER11_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER7_UP_TIMER12_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER7_TRG_CMT_TIMER13_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER7_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA0_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SDIO_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER5_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIMER6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ENET_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ENET_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_TX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CAN1_EWMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBFS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBHS_EP1_Out_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBHS_EP1_In_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBHS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USBHS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DCI_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TRNG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FPU_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TLI_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TLI_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) IPA_IRQHandler(void);

#elif defined(STM32H743xx)
	void __attribute__ ((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PVD_AVD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TAMP_STAMP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FLASH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FDCAN1_IT0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FDCAN2_IT0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FDCAN1_IT1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FDCAN2_IT1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_BRK_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_UP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_TRG_COM_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RTC_Alarm_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_BRK_TIM12_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_UP_TIM13_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_TRG_COM_TIM14_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM8_CC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA1_Stream7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SDMMC1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ETH_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ETH_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FDCAN_CAL_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2_Stream7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) USART6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C3_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C3_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_EP1_OUT_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_EP1_IN_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_HS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DCMI_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) RNG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) FPU_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UART8_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPI6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SAI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LTDC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LTDC_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMA2D_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SAI2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) QUADSPI_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CEC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C4_EV_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) I2C4_ER_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SPDIF_RX_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_EP1_OUT_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_EP1_IN_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) OTG_FS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMAMUX1_OVR_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HRTIM1_Master_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HRTIM1_TIMA_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HRTIM1_TIMB_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HRTIM1_TIMC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HRTIM1_TIMD_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HRTIM1_TIME_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HRTIM1_FLT_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DFSDM1_FLT0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DFSDM1_FLT1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DFSDM1_FLT2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DFSDM1_FLT3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SAI3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SWPMI1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM15_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM16_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) TIM17_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) MDIOS_WKUP_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) MDIOS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) JPEG_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) MDMA_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SDMMC2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HSEM1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ADC3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DMAMUX2_OVR_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BDMA_Channel0_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BDMA_Channel1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BDMA_Channel2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BDMA_Channel3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BDMA_Channel4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BDMA_Channel5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BDMA_Channel6_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BDMA_Channel7_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) COMP1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM2_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM3_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPTIM5_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) LPUART1_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) CRS_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) ECC_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SAI4_IRQHandler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) WAKEUP_PIN_IRQHandler(void);

#else
	#error "unsupported or unknown MCU"
#endif

extern const int __main_stack_end__;		// import main stack end (from linker script)
extern void Reset_Handler(void);	// import the address of Reset_Handler()

void (* const vectors[])(void) __attribute__ ((used, section(".isr_vector_table"))) =
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

#if defined(STM32F030)
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

#elif defined(STM32F031)
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
	ADC1_IRQHandler,
	TIM1_BRK_UP_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
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

#elif defined(STM32F042)
	WWDG_IRQHandler,
	PVD_VDDIO2_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_CRS_IRQHandler,
	EXTI0_1_IRQHandler,
	EXTI2_3_IRQHandler,
	EXTI4_15_IRQHandler,
	TSC_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_3_IRQHandler,
	DMA1_Channel4_5_IRQHandler,
	ADC1_IRQHandler,
	TIM1_BRK_UP_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
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
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	0,
	CEC_CAN_IRQHandler,
	USB_IRQHandler,

#elif defined(STM32F051)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_1_IRQHandler,
	EXTI2_3_IRQHandler,
	EXTI4_15_IRQHandler,
	TSC_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_3_IRQHandler,
	DMA1_Channel4_5_IRQHandler,
	ADC1_COMP_IRQHandler,
	TIM1_BRK_UP_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM6_DAC_IRQHandler,
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
	0,
	CEC_IRQHandler,

#elif defined (STM32F070x6)
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
	USART2_IRQHandler,
	0,
	0,
	USB_IRQHandler,

#elif defined (STM32F070xB)
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
	TIM6_DAC_IRQHandler,
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
	USART3_4_IRQHandler,
	0,
	USB_IRQHandler,

#elif defined (STM32F072)
	WWDG_IRQHandler,
	PVD_VDDIO2_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_CRS_IRQHandler,
	EXTI0_1_IRQHandler,
	EXTI2_3_IRQHandler,
	EXTI4_15_IRQHandler,
	TSC_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_3_IRQHandler,
	DMA1_Channel4_7_IRQHandler,
	ADC1_COMP_IRQHandler,
	TIM1_BRK_UP_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM6_DAC_IRQHandler,
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
	USART3_4_IRQHandler,
	CEC_CAN_IRQHandler,
	USB_IRQHandler,

#elif defined (STM32F091)
	WWDG_IRQHandler,
	PVD_VDDIO2_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_CRS_IRQHandler,
	EXTI0_1_IRQHandler,
	EXTI2_3_IRQHandler,
	EXTI4_15_IRQHandler,
	TSC_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler,
	DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler,
	ADC1_COMP_IRQHandler,
	TIM1_BRK_UP_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM6_DAC_IRQHandler,
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
	USART3_8_IRQHandler,
	CEC_CAN_IRQHandler,

#elif defined(STM32F10X_LD)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	USB_HP_CAN1_TX_IRQHandler,
	USB_LP_CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_IRQHandler,
	TIM1_UP_IRQHandler,
	TIM1_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	0,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	0,
	0,
	SPI1_IRQHandler,
	0,
	USART1_IRQHandler,
	USART2_IRQHandler,
	0,
	EXTI15_10_IRQHandler,
	RTCAlarm_IRQHandler,
	USBWakeUp_IRQHandler,

#elif defined(STM32F10X_LD_VL)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	0,
	0,
	0,
	0,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM15_IRQHandler,
	TIM1_UP_TIM16_IRQHandler,
	TIM1_TRG_COM_TIM17_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	0,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	0,
	0,
	SPI1_IRQHandler,
	0,
	USART1_IRQHandler,
	USART2_IRQHandler,
	0,
	EXTI15_10_IRQHandler,
	RTCAlarm_IRQHandler,
	CEC_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,

#elif defined(STM32F10X_MD)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	ADC1_2_IRQHandler,
	USB_HP_CAN_TX_IRQHandler,
	USB_LP_CAN_RX0_IRQHandler,
	CAN_RX1_IRQHandler,
	CAN_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_IRQHandler,
	TIM1_UP_IRQHandler,
	TIM1_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTCAlarm_IRQHandler,
	USBWakeup_IRQHandler,

#elif defined(STM32F10X_MD_VL)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	0,
	0,
	0,
	0,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM15_IRQHandler,
	TIM1_UP_TIM16_IRQHandler,
	TIM1_TRG_COM_TIM17_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTCAlarm_IRQHandler,
	CEC_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,

#elif defined(STM32F10X_HD)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	USB_HP_CAN1_TX_IRQHandler,
	USB_LP_CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_IRQHandler,
	TIM1_UP_IRQHandler,
	TIM1_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTCAlarm_IRQHandler,
	USBWakeUp_IRQHandler,
	TIM8_BRK_IRQHandler,
	TIM8_UP_IRQHandler,
	TIM8_TRG_COM_IRQHandler,
	TIM8_CC_IRQHandler,
	ADC3_IRQHandler,
	FSMC_IRQHandler,
	SDIO_IRQHandler,
	TIM5_IRQHandler,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Channel1_IRQHandler,
	DMA2_Channel2_IRQHandler,
	DMA2_Channel3_IRQHandler,
	DMA2_Channel4_5_IRQHandler,

#elif defined(STM32F10X_HD_VL)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	0,
	0,
	0,
	0,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM15_IRQHandler,
	TIM1_UP_TIM16_IRQHandler,
	TIM1_TRG_COM_TIM17_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTCAlarm_IRQHandler,
	CEC_IRQHandler,
	TIM12_IRQHandler,
	TIM13_IRQHandler,
	TIM14_IRQHandler,
	0,
	0,
	0,
	0,
	TIM5_IRQHandler,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Channel1_IRQHandler,
	DMA2_Channel2_IRQHandler,
	DMA2_Channel3_IRQHandler,
	DMA2_Channel4_5_IRQHandler,
	DMA2_Channel5_IRQHandler,

#elif defined(STM32F10X_XL)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	USB_HP_CAN1_TX_IRQHandler,
	USB_LP_CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM9_IRQHandler,
	TIM1_UP_TIM10_IRQHandler,
	TIM1_TRG_COM_TIM11_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTCAlarm_IRQHandler,
	USBWakeUp_IRQHandler,
	TIM8_BRK_TIM12_IRQHandler,
	TIM8_UP_TIM13_IRQHandler,
	TIM8_TRG_COM_TIM14_IRQHandler,
	TIM8_CC_IRQHandler,
	ADC3_IRQHandler,
	FSMC_IRQHandler,
	SDIO_IRQHandler,
	TIM5_IRQHandler,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Channel1_IRQHandler,
	DMA2_Channel2_IRQHandler,
	DMA2_Channel3_IRQHandler,
	DMA2_Channel4_5_IRQHandler,

#elif defined(STM32F10X_CL)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	CAN1_TX_IRQHandler,
	CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_IRQHandler,
	TIM1_UP_IRQHandler,
	TIM1_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTCAlarm_IRQHandler,
	OTG_FS_WKUP_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	TIM5_IRQHandler,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Channel1_IRQHandler,
	DMA2_Channel2_IRQHandler,
	DMA2_Channel3_IRQHandler,
	DMA2_Channel4_IRQHandler,
	DMA2_Channel5_IRQHandler,
	ETH_IRQHandler,
	ETH_WKUP_IRQHandler,
	CAN2_TX_IRQHandler,
	CAN2_RX0_IRQHandler,
	CAN2_RX1_IRQHandler,
	CAN2_SCE_IRQHandler,
	OTG_FS_IRQHandler,

#elif defined(STM32F30X) //STM32F303xB/C/D/E, STM32F358xC and STM32F398xE //STM32F303x6/8 and STM32F328x8 ??
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMPER_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_TS_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	ADC1_2_IRQHandler,
	USB_HP_CAN1_TX_IRQHandler,
	USB_LP_CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM15_IRQHandler,
	TIM1_UP_TIM16_IRQHandler,
	TIM1_TRG_COM_TIM17_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTC_Alarm_IRQHandler,
	USBWakeUp_IRQHandler,
	TIM8_BRK_IRQHandler,
	TIM8_UP_IRQHandler,
	TIM8_TRG_COM_IRQHandler,
	TIM8_CC_IRQHandler,
	ADC3_IRQHandler,
	FMC_IRQHandler, // D/E only
	0,
	0,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Channel1_IRQHandler,
	DMA2_Channel2_IRQHandler,
	DMA2_Channel3_IRQHandler,
	DMA2_Channel4_IRQHandler,
	DMA2_Channel5_IRQHandler,
	ADC4_IRQHandler,
	0,
	0,
	COMP1_3_IRQHandler,
	COMP4_6_IRQHandler,
	COMP7_IRQHandler,
	0,
	0,
	0,
	0,
	0,
	I2C3_EV_IRQHandler, // D/E only
	I2C3_ER_IRQHandler, // D/E only
	USB_HP_IRQHandler,
	USB_LP_IRQHandler,
	USBWakeUp_RMP_IRQHandler,
	TIM20_BRK_IRQHandler, // D/E only
	TIM20_UP_IRQHandler, // D/E only
	TIM20_TRG_COM_IRQHandler, // D/E only
	TIM20_CC_IRQHandler, // D/E only
	FPU_IRQHandler,
	0,
	0,
	SPI4_IRQHandler, // D/E only

#elif defined(STM32F405xx)||defined(STM32F407xx)||defined(STM32F415xx)||defined(STM32F417xx)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMP_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Stream0_IRQHandler,
	DMA1_Stream1_IRQHandler,
	DMA1_Stream2_IRQHandler,
	DMA1_Stream3_IRQHandler,
	DMA1_Stream4_IRQHandler,
	DMA1_Stream5_IRQHandler,
	DMA1_Stream6_IRQHandler,
	ADC_IRQHandler,
	CAN1_TX_IRQHandler,
	CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM9_IRQHandler,
	TIM1_UP_TIM10_IRQHandler,
	TIM1_TRG_COM_TIM11_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTC_Alarm_IRQHandler,
	OTG_FS_WKUP_IRQHandler,
	TIM8_BRK_TIM12_IRQHandler,
	TIM8_UP_TIM13_IRQHandler,
	TIM8_TRG_COM_TIM14_IRQHandler,
	TIM8_CC_IRQHandler,
	DMA1_Stream7_IRQHandler,
	FMC_IRQHandler,
	SDIO_IRQHandler,
	TIM5_IRQHandler,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Stream0_IRQHandler,
	DMA2_Stream1_IRQHandler,
	DMA2_Stream2_IRQHandler,
	DMA2_Stream3_IRQHandler,
	DMA2_Stream4_IRQHandler,
	ETH_IRQHandler,
	ETH_WKUP_IRQHandler,
	CAN2_TX_IRQHandler,
	CAN2_RX0_IRQHandler,
	CAN2_RX1_IRQHandler,
	CAN2_SCE_IRQHandler,
	OTG_FS_IRQHandler,
	DMA2_Stream5_IRQHandler,
	DMA2_Stream6_IRQHandler,
	DMA2_Stream7_IRQHandler,
	USART6_IRQHandler,
	I2C3_EV_IRQHandler,
	I2C3_ER_IRQHandler,
	OTG_HS_EP1_OUT_IRQHandler,
	OTG_HS_EP1_IN_IRQHandler,
	OTG_HS_WKUP_IRQHandler,
	OTG_HS_IRQHandler,
	DCMI_IRQHandler,
	CRYP_IRQHandler,
	HASH_RNG_IRQHandler,
	FPU_IRQHandler,

#elif defined(STM32F427xx)||defined(STM32F429xx)||defined(STM32F437xx)||defined(STM32F439xx)
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMP_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Stream0_IRQHandler,
	DMA1_Stream1_IRQHandler,
	DMA1_Stream2_IRQHandler,
	DMA1_Stream3_IRQHandler,
	DMA1_Stream4_IRQHandler,
	DMA1_Stream5_IRQHandler,
	DMA1_Stream6_IRQHandler,
	ADC_IRQHandler,
	CAN1_TX_IRQHandler,
	CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM9_IRQHandler,
	TIM1_UP_TIM10_IRQHandler,
	TIM1_TRG_COM_TIM11_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTC_Alarm_IRQHandler,
	OTG_FS_WKUP_IRQHandler,
	TIM8_BRK_TIM12_IRQHandler,
	TIM8_UP_TIM13_IRQHandler,
	TIM8_TRG_COM_TIM14_IRQHandler,
	TIM8_CC_IRQHandler,
	DMA1_Stream7_IRQHandler,
	FMC_IRQHandler,
	SDIO_IRQHandler,
	TIM5_IRQHandler,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Stream0_IRQHandler,
	DMA2_Stream1_IRQHandler,
	DMA2_Stream2_IRQHandler,
	DMA2_Stream3_IRQHandler,
	DMA2_Stream4_IRQHandler,
	ETH_IRQHandler,
	ETH_WKUP_IRQHandler,
	CAN2_TX_IRQHandler,
	CAN2_RX0_IRQHandler,
	CAN2_RX1_IRQHandler,
	CAN2_SCE_IRQHandler,
	OTG_FS_IRQHandler,
	DMA2_Stream5_IRQHandler,
	DMA2_Stream6_IRQHandler,
	DMA2_Stream7_IRQHandler,
	USART6_IRQHandler,
	I2C3_EV_IRQHandler,
	I2C3_ER_IRQHandler,
	OTG_HS_EP1_OUT_IRQHandler,
	OTG_HS_EP1_IN_IRQHandler,
	OTG_HS_WKUP_IRQHandler,
	OTG_HS_IRQHandler,
	DCMI_IRQHandler,
	CRYP_IRQHandler,
	HASH_RNG_IRQHandler,
	FPU_IRQHandler,
	UART7_IRQHandler,
	UART8_IRQHandler,
	SPI4_IRQHandler,
	SPI5_IRQHandler,
	SPI6_IRQHandler,
	SAI1_IRQHandler,
	LTDC_IRQHandler,
	LTDC_ER_IRQHandler,
	DMA2D_IRQHandler,

#elif defined(GD32F450)
	WWDGT_IRQHandler,
	LVD_IRQHandler,
	TAMPER_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FMC_IRQHandler,
	RCU_CTC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA0_Channel0_IRQHandler,
	DMA0_Channel1_IRQHandler,
	DMA0_Channel2_IRQHandler,
	DMA0_Channel3_IRQHandler,
	DMA0_Channel4_IRQHandler,
	DMA0_Channel5_IRQHandler,
	DMA0_Channel6_IRQHandler,
	ADC_IRQHandler,
	CAN0_TX_IRQHandler,
	CAN0_RX0_IRQHandler,
	CAN0_RX1_IRQHandler,
	CAN0_EWMC_IRQHandler,
	EXTI5_9_IRQHandler,
	TIMER0_BRK_TIMER8_IRQHandler,
	TIMER0_UP_TIMER9_IRQHandler,
	TIMER0_TRG_CMT_TIMER10_IRQHandler,
	TIMER0_CC_IRQHandler,
	TIMER1_IRQHandler,
	TIMER2_IRQHandler,
	TIMER3_IRQHandler,
	I2C0_EV_IRQHandler,
	I2C0_ER_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	SPI0_IRQHandler,
	SPI1_IRQHandler,
	USART0_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	EXTI10_15_IRQHandler,
	RTC_Alarm_IRQHandler,
	USBFS_WKUP_IRQHandler,
	TIMER7_BRK_TIMER11_IRQHandler,
	TIMER7_UP_TIMER12_IRQHandler,
	TIMER7_TRG_CMT_TIMER13_IRQHandler,
	TIMER7_CC_IRQHandler,
	DMA0_Channel7_IRQHandler,
	EXMC_IRQHandler,
	SDIO_IRQHandler,
	TIMER4_IRQHandler,
	SPI2_IRQHandler,
	UART3_IRQHandler,
	UART4_IRQHandler,
	TIMER5_DAC_IRQHandler,
	TIMER6_IRQHandler,
	DMA1_Channel0_IRQHandler,
	DMA1_Channel1_IRQHandler,
	DMA1_Channel2_IRQHandler,
	DMA1_Channel3_IRQHandler,
	DMA1_Channel4_IRQHandler,
	ENET_IRQHandler,
	ENET_WKUP_IRQHandler,
	CAN1_TX_IRQHandler,
	CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_EWMC_IRQHandler,
	USBFS_IRQHandler,
	DMA1_Channel5_IRQHandler,
	DMA1_Channel6_IRQHandler,
	DMA1_Channel7_IRQHandler,
	USART5_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	USBHS_EP1_Out_IRQHandler,
	USBHS_EP1_In_IRQHandler,
	USBHS_WKUP_IRQHandler,
	USBHS_IRQHandler,
	DCI_IRQHandler,
	0,
	TRNG_IRQHandler,
	FPU_IRQHandler,
	UART6_IRQHandler,
	UART7_IRQHandler,
	SPI3_IRQHandler,
	SPI4_IRQHandler,
	SPI5_IRQHandler,
	0,
	TLI_IRQHandler,
	TLI_ER_IRQHandler,
	IPA_IRQHandler,

#elif defined(STM32H743xx)
	WWDG_IRQHandler,
	PVD_AVD_IRQHandler,
	TAMP_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Stream0_IRQHandler,
	DMA1_Stream1_IRQHandler,
	DMA1_Stream2_IRQHandler,
	DMA1_Stream3_IRQHandler,
	DMA1_Stream4_IRQHandler,
	DMA1_Stream5_IRQHandler,
	DMA1_Stream6_IRQHandler,
	ADC_IRQHandler,
	FDCAN1_IT0_IRQHandler,
	FDCAN2_IT0_IRQHandler,
	FDCAN1_IT1_IRQHandler,
	FDCAN2_IT1_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_IRQHandler,
	TIM1_UP_IRQHandler,
	TIM1_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTC_Alarm_IRQHandler,
	0,
	TIM8_BRK_TIM12_IRQHandler,
	TIM8_UP_TIM13_IRQHandler,
	TIM8_TRG_COM_TIM14_IRQHandler,
	TIM8_CC_IRQHandler,
	DMA1_Stream7_IRQHandler,
	FMC_IRQHandler,
	SDMMC1_IRQHandler,
	TIM5_IRQHandler,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Stream0_IRQHandler,
	DMA2_Stream1_IRQHandler,
	DMA2_Stream2_IRQHandler,
	DMA2_Stream3_IRQHandler,
	DMA2_Stream4_IRQHandler,
	ETH_IRQHandler,
	ETH_WKUP_IRQHandler,
	FDCAN_CAL_IRQHandler,
	0,
	0,
	0,
	0,
	DMA2_Stream5_IRQHandler,
	DMA2_Stream6_IRQHandler,
	DMA2_Stream7_IRQHandler,
	USART6_IRQHandler,
	I2C3_EV_IRQHandler,
	I2C3_ER_IRQHandler,
	OTG_HS_EP1_OUT_IRQHandler,
	OTG_HS_EP1_IN_IRQHandler,
	OTG_HS_WKUP_IRQHandler,
	OTG_HS_IRQHandler,
	DCMI_IRQHandler,
	0,
	RNG_IRQHandler,
	FPU_IRQHandler,
	UART7_IRQHandler,
	UART8_IRQHandler,
	SPI4_IRQHandler,
	SPI5_IRQHandler,
	SPI6_IRQHandler,
	SAI1_IRQHandler,
	LTDC_IRQHandler,
	LTDC_ER_IRQHandler,
	DMA2D_IRQHandler,
	SAI2_IRQHandler,
	QUADSPI_IRQHandler,
	LPTIM1_IRQHandler,
	CEC_IRQHandler,
	I2C4_EV_IRQHandler,
	I2C4_ER_IRQHandler,
	SPDIF_RX_IRQHandler,
	OTG_FS_EP1_OUT_IRQHandler,
	OTG_FS_EP1_IN_IRQHandler,
	OTG_FS_WKUP_IRQHandler,
	OTG_FS_IRQHandler,
	DMAMUX1_OVR_IRQHandler,
	HRTIM1_Master_IRQHandler,
	HRTIM1_TIMA_IRQHandler,
	HRTIM1_TIMB_IRQHandler,
	HRTIM1_TIMC_IRQHandler,
	HRTIM1_TIMD_IRQHandler,
	HRTIM1_TIME_IRQHandler,
	HRTIM1_FLT_IRQHandler,
	DFSDM1_FLT0_IRQHandler,
	DFSDM1_FLT1_IRQHandler,
	DFSDM1_FLT2_IRQHandler,
	DFSDM1_FLT3_IRQHandler,
	SAI3_IRQHandler,
	SWPMI1_IRQHandler,
	TIM15_IRQHandler,
	TIM16_IRQHandler,
	TIM17_IRQHandler,
	MDIOS_WKUP_IRQHandler,
	MDIOS_IRQHandler,
	JPEG_IRQHandler,
	MDMA_IRQHandler,
	0,
	SDMMC2_IRQHandler,
	HSEM1_IRQHandler,
	0,
	ADC3_IRQHandler,
	DMAMUX2_OVR_IRQHandler,
	BDMA_Channel0_IRQHandler,
	BDMA_Channel1_IRQHandler,
	BDMA_Channel2_IRQHandler,
	BDMA_Channel3_IRQHandler,
	BDMA_Channel4_IRQHandler,
	BDMA_Channel5_IRQHandler,
	BDMA_Channel6_IRQHandler,
	BDMA_Channel7_IRQHandler,
	COMP1_IRQHandler,
	LPTIM2_IRQHandler,
	LPTIM3_IRQHandler,
	LPTIM4_IRQHandler,
	LPTIM5_IRQHandler,
	LPUART1_IRQHandler,
	0,
	CRS_IRQHandler,
	ECC_IRQHandler,
	SAI4_IRQHandler,
	0,
	0,
	WAKEUP_PIN_IRQHandler
#else
	#error "unsupported or unknown MCU"
#endif
};
