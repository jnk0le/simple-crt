/*****************************************************************************
 * universal cortex-m0 minimum startup code                                  *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

//assumptions:
// - initialized sections are 4 byte aligned (init in 4 byte steps)
// - .bss is right after .data in RAM
// - .preinit_array is right after .data LMA in FLASH
// - .init_array is right after .preinit_array
// - .fini_array is right after .init_array

.syntax unified
.thumb

.text
.thumb_func
.global Reset_Handler
.balign 2

	// general allocation strategy:
	// r0 - tmp
	// r2 - working mem ptr (.data + .bss)
	// r3 - .data final condition
	// r4 - .bss final condition
	// r5 - LMA data
	// r6 - final cond for static initializers

Reset_Handler:
	adr r0, mem_init_symbols

#if defined(__CRT_NO_STATIC_INITIALIZERS)
	ldmia r0!, {r2-r5}
#else
	#if !defined(__CRT_NORETURN_FROM_MAIN)
		ldmia r0!, {r2-r7}
	#else
		ldmia r0!, {r2-r6}
	#endif
#endif

	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r0}
	stmia r2!, {r0}
2:	cmp r2, r3
	bne 1b

	movs r1, #0

	b 2f // need to skip in case of empty section
1:	stmia r2!, {r1}
2:	cmp r2, r4
	bne 1b

#ifndef __CRT_NO_STATIC_INITIALIZERS
	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r0}
	blx r0
2:	cmp r5, r6
	bne 1b
#endif

	bl main

#if !defined(__CRT_NORETURN_FROM_MAIN)
	// main returned, r5, r7 are preserved

	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r0}
	blx r0
2:	cmp r5, r7
	bne 1b

	b .
#endif

.balign 4
mem_init_symbols:
	.long __data_start__ // r2
	.long __data_end__ // r3
	.long __bss_end__ // r4
	.long __data_init_start__ // r5
	.long __init_array_end // r6
#if !defined(__CRT_NORETURN_FROM_MAIN)
	.long __fini_array_end // r7
#endif
