#if defined(__cplusplus)
	extern "C" {
#endif

	// semihosting implemented according to the spec:
	// https://developer.arm.com/documentation/100863/0300/

	enum SemihostOperation
	{
		SEMIHOSTING_SYS_OPEN = 0x01,
		SEMIHOSTING_SYS_CLOSE = 0x02,
		SEMIHOSTING_SYS_WRITEC = 0x03,
		SEMIHOSTING_SYS_WRITE0 = 0x04,
		SEMIHOSTING_SYS_WRITE = 0x05,
		SEMIHOSTING_SYS_READ = 0x06,
		SEMIHOSTING_SYS_READC = 0x07,
		SEMIHOSTING_SYS_ISERROR = 0x08,
		SEMIHOSTING_SYS_ISTTY = 0x09,
		SEMIHOSTING_SYS_SEEK = 0x0A,
		SEMIHOSTING_SYS_REMOVE = 0x0E,
		SEMIHOSTING_SYS_RENAME = 0x0F,
		SEMIHOSTING_SYS_CLOCK = 0x10,
		SEMIHOSTING_SYS_FLEN = 0x0C,
		SEMIHOSTING_SYS_TMPNAM = 0x0D,
		SEMIHOSTING_SYS_TIME = 0x11,
		SEMIHOSTING_SYS_SYSTEM = 0x12,
		SEMIHOSTING_SYS_ERRNO = 0x13,
		SEMIHOSTING_SYS_GET_CMDLINE = 0x15,
		SEMIHOSTING_SYS_HEAPINFO = 0x16,
		SEMIHOSTING_EnterSVC = 0x17,
		SEMIHOSTING_ReportException = 0x18,
		SEMIHOSTING_SYS_ELAPSED = 0x30,
		SEMIHOSTING_SYS_TICKFREQ = 0x31,
	};

	// stdin / stdout / stderr
	#define SEMIHOSTING_FOPEN_MODE_R 0
	#define SEMIHOSTING_FOPEN_MODE_W 4
	#define SEMIHOSTING_FOPEN_MODE_A 8

	static inline int call_host(int reason, void* param);
	static inline int call_host(int reason, void* param)
	{
	#if defined(__ARM_ARCH_6M__)||defined(__ARM_ARCH_7M__)||defined(__ARM_ARCH_7EM__)|| \
		defined(__ARM_ARCH_8M_BASE__)||defined(__ARM_ARCH_8M_MAIN__)||defined(__ARM_ARCH_8_1M_MAIN__)

		register long result asm("r0") = reason;
		register void* r1 asm("r1") = param;

		asm volatile(
			"bkpt #0xab \n\t"
			: [R0] "+r" (result) // return in same register
			: [R1] "r" (r1)
			: "memory"
		);
	#elif defined(__riscv)
		register long result asm("a0") = reason;
		register void* a1 asm("a1") = param;

		asm volatile(
			".option push \n\t"
			".option norvc \n\t"
			"slli x0, x0, 0x1f \n\t"
			"ebreak \n\t"
			"srai x0, x0, 0x7 \n\t"
			".option pop \n\t"
			: [A0] "+r" (result) // return in same register
			: [A1] "r" (a1)
			: "memory"
		);
	#else
		#error "unknown architecture"
	#endif

		return result;
	}

	void semihost_putc(char c);
	void semihost_puts(const char* buff);

	int semihost_write(int file, const char* buff, int len); // return number of bytes written or error code
	int semihost_read(int file, const char* buff, int len); // return number of bytes read or error code

	int semihost_open_special(int mode);

#if defined(__cplusplus)
	}
#endif
