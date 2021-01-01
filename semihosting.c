#include "semihosting.h"

void semihost_putc(char c)
{
	call_host(SEMIHOSTING_SYS_WRITEC, &c);
}

void semihost_puts(const char* buff)
{
	call_host(SEMIHOSTING_SYS_WRITE0, (void*)buff);
}

int semihost_write(int file, const char* buf, int len)
{
	int tmp;
	int param[3];

	param[0] = file;
	param[1] = (int)buf;
	param[2] = len;

	tmp = call_host(SEMIHOSTING_SYS_WRITE, param);
	// returns number of bytes not written in case of error

	if(tmp == -1) // illegal but some debuggers are known to return -1
		return -1;
	else
		return len - tmp; // return number of bytes written
}

int semihost_open_special(int mode)
{
	int tmp;
	int param[3];

	param[0] = (int)":tt";
	param[1] = mode;
	param[2] = sizeof(":tt") - 1;

	tmp = call_host(SEMIHOSTING_SYS_OPEN, param);

	if(tmp == -1)
		return -1;
	else
		return tmp;
}
