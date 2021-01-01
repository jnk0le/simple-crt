// reimplementation of __libc_init_array that doesn't require bloated startfiles

#ifndef __CRT_NO_STATIC_INITIALIZERS

	extern void (*__preinit_array_start[]) (void);
	extern void (*__preinit_array_end[]) (void);
	extern void (*__init_array_start[]) (void);
	extern void (*__init_array_end[]) (void);
	extern void (*__fini_array_start[]) (void);
	extern void (*__fini_array_end[]) (void);

	//extern void _init();
	//extern void _fini();

	void __run_init_array(void);
	void __run_init_array(void)
	{
		int count, i;

		count = __preinit_array_end - __preinit_array_start;
		for (i = 0; i < count; i++)
			__preinit_array_start[i]();

		//_init();

		count = __init_array_end - __init_array_start;
		for (i = 0; i < count; i++)
			__init_array_start[i]();
	}

	void __run_fini_array(void);
	void __run_fini_array(void)
	{
		int count, i;

		count = __fini_array_end - __fini_array_start;
		for (i = count - 1; i >= 0; i--)
			__fini_array_start[i]();

		//_fini();
	}

#endif // __CRT_NO_STATIC_INITIALIZERS
