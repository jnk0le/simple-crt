// newlib syscalls stubs
// to be used with --specs=nosys.specs

#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#include "semihosting.h"

extern char __heap_start__; // linker definition
extern char __heap_end__; // linker definition

__attribute__((weak)) caddr_t _sbrk(int incr);
__attribute__((weak)) caddr_t _sbrk(int incr)
{
	static char* heap_top = &__heap_start__;
	char* tmp_address;

	tmp_address = heap_top;

#ifdef __ARM_ARCH_6M__ // cortex-m0 requires word alignment
	incr = ((incr+3) & ~3);
#endif

	if(heap_top + incr > (char*)&__heap_end__)
	{
		errno = ENOMEM; // errno is also used inside of malloc
		return (caddr_t)-1;
	}

	heap_top += incr;
	return (caddr_t)tmp_address;
}

__attribute__((weak)) int _write(int file, char *ptr, int len);
__attribute__((weak)) int _write(int file, char *ptr, int len)
{
#if defined(WRITE_REDIRECT_TO_SPECIAL_PATH_TT_STDOUT)||defined(WRITE_REDIRECT_TO_SPECIAL_PATH_TT_STDERR)
	static int handle = 0;

	if(handle == 0)
	{
	#ifdef WRITE_REDIRECT_TO_SPECIAL_PATH_TT_STDOUT
		handle = semihost_open_special(SEMIHOSTING_FOPEN_MODE_W);
	#elif defined(WRITE_REDIRECT_TO_SPECIAL_PATH_TT_STDERR)
		handle = semihost_open_special(SEMIHOSTING_FOPEN_MODE_A);
	#endif
	}
	file = handle;
#endif

	return semihost_write(file, ptr, len);
}

__attribute__((weak)) int _read(int file, char *ptr, int len);
__attribute__((weak)) int _read(int file, char *ptr, int len)
{
#ifdef READ_REDIRECT_TO_SPECIAL_PATH_TT_STDIN
	static int handle = 0;

	if(handle == 0) //SYS_OPEN opens only non zero handles, so there is no collision with default stdin
		handle = semihost_open_special(SEMIHOSTING_FOPEN_MODE_R);
#endif

	return semihost_read(file, ptr, len);
}
