/*****************************************************************************
 * R7FA8D1 vector table definitions                                          *
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

	void __attribute__ ((weak, alias("Default_Handler"))) SecureFault_Handler(void);
	//?????


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
		SecureFault_Handler,
		0,
		0,
		0,
		SVC_Handler,
		DebugMon_Handler,
		0,
		PendSV_Handler,
		SysTick_Handler,

		//????
	};

#if !defined(__ARM_ARCH_8M_MAIN__)&&!defined(__ARM_ARCH_8_1M_MAIN__)
	#error "wrong architecture"
#endif
