/*****************************************************************************
 * STM32H7 vector table definitions                                       *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
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

#if defined(STM32H743xx)
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
#endif

	extern const int __main_stack_end__;   // import main stack end (from linker script)
	extern void Reset_Handler(void);       // import the address of Reset_Handler()

	void (*const vectors[])(void) __attribute__((used, section(".isr_vector_table"))) =
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

	#if defined(STM32H743xx)
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
		WAKEUP_PIN_IRQHandler,
	#else
		#error "unsupported or unknown MCU"
	#endif
	};
	
#if !defined(__ARM_ARCH_7EM__)&&!defined(__ARM_ARCH_7M__)
	#error "wrong architecture"
#endif
