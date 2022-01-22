/*****************************************************************************
 * cortex-m3 minimum startup code                                            *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
 * License: CC0                                                              *
 *****************************************************************************/

.syntax unified
.thumb

.text
.thumb_func
.global Reset_Handler
.align 2

Reset_Handler:
	adr r0, mem_init_symbols
	ldmia r0!, {r2,r3,r4,r5}

	// 2 cycles faster but less dense, loops not 64bit aligned
	//ldr r2, =__data_init_start__
	//ldr r3, =__data_start__
	//ldr r4, =__data_end__
	//ldr r5, =__bss_end__

	b 2f // section size is not known during compilation so it have to be used in case of empty section
	nop // padding for literal table, align both loops entry to 4 bytes

1:	ldr r0, [r2], #4
	str r0, [r3], #4
2:	cmp r3, r4
	bne 1b

	movs r0, #0

	// reuse __data_end__ in r3 as __bss_start__
	// .bss have to be placed right after the .data section

	b 2f // section size is not known during compilation so it have to be used in case of empty section
1:	str r0, [r3], #4
2:	cmp r3, r5
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

mem_init_symbols:
	.long __data_init_start__ // r2
	.long __data_start__ // r3
	.long __data_end__ // r4
	.long __bss_end__ // r5
