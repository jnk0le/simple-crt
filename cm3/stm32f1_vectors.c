/*****************************************************************************
 * STM32F1 vector table definitions                                          *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

	__attribute__((weak)) void Default_Handler(void); // [-Wmissing-prototypes]
	__attribute__((weak)) void Default_Handler(void)
	{
		while(1) asm volatile("bkpt #0");
	}

	void __attribute__ ((weak, alias("Default_Handler"))) NMI_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) HardFault_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SVC_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) PendSV_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) SysTick_Handler(void);

	void __attribute__ ((weak, alias("Default_Handler"))) MemManage_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) BusFault_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) UsageFault_Handler(void);
	void __attribute__ ((weak, alias("Default_Handler"))) DebugMon_Handler(void);

	// common irq handlers
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

#if defined(STM32F10X_LD)
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
#else
	#error "unsupported or unknown MCU"
#endif

	extern const int __main_stack_end__;   // import main stack end (from linker script)
	extern void Reset_Handler(void);       // import the address of Reset_Handler()

	void (*const __irq_vector_table[])(void) __attribute__((used, section(".isr_vector_table"))) =
	{
		(void (*)(void))&__main_stack_end__,
		Reset_Handler,
		NMI_Handler,
		HardFault_Handler,
		MemManage_Handler,
		BusFault_Handler,
		UsageFault_Handler,
		0,
		0,
		0,
		0,
		SVC_Handler,
		DebugMon_Handler,
		0,
		PendSV_Handler,
		SysTick_Handler,

		// common irq handlers
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

	#if defined(STM32F10X_LD)
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

	#else
		#error "unsupported or unknown MCU"
	#endif
	};

#if !defined(__ARM_ARCH_7M__)
	#error "wrong architecture"
#endif
