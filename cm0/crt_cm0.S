/*****************************************************************************
 * cortex-m0 minimum startup code                                            *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
 * License: CC0                                                              *
 *****************************************************************************/

.syntax unified
.thumb

.text
.thumb_func
.global Reset_Handler

Reset_Handler:
	ldr r2, =__data_init_start__
	ldr r3, =__data_start__
	ldr r4, =__data_end__

	b 2f // section size is not known during compilation so it have to be used in case of empty section
1:	ldmia r2!, {r0}
	stmia r3!, {r0}
2:	cmp r3, r4
	bne 1b // go forward if r2 is equal to r3

	movs r0, #0
	//ldr r3, =__bss_start__ // reuse __data_end__ in r2 as __bss_start__
	// .bss have to be placed right after the .data section
	ldr r4, =__bss_end__

	b 2f // section size is not known during compilation so it have to be used in case of empty section
1:	stmia r3!, {r0}
2:	cmp r3, r4
	bne 1b

#ifndef __CRT_NO_STATIC_INITIALIZERS
	// newlib implementation doesn't work with -nostartfiles
	//bl __libc_init_array
	bl __run_init_array
#endif

	bl main

#if !defined(__CRT_NO_STATIC_INITIALIZERS)&&!defined(__CRT_NORETURN_FROM_MAIN)
	//bl __libc_fini_array
	bl __run_fini_array
#endif

	b .
