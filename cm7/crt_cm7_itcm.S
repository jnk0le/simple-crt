/*****************************************************************************
 * cortex-m7 minimum startup code including itcm initialization              *
 * vector table is copied and remapped into itcm                             *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

//assumptions:
// - initialized sections are 8 byte aligned (init in 8 byte steps)
// - .bss is right after .data in RAM
// - .itcm.text is right after .data LMA in FLASH
// - .preinit_array is right after .itcm.text LMA
// - .init_array is right after .preinit_array
// - .fini_array is right after .init_array
// - data/bss SRAM and itcm are enabled from reset
// - itcm is fixed at 0x00000000

.syntax unified
.thumb
.text

.thumb_func
.global Reset_Handler
.balign 4
Reset_Handler:
	adr r0, mem_init_symbols

#if defined(__CRT_NO_STATIC_INITIALIZERS)
	ldmia r0!, {r2-r9}
#else
	#if defined(__CRT_NORETURN_FROM_MAIN)
		ldmia r0!, {r2-r10}
	#else
		ldmia r0!, {r2-r11}
	#endif
#endif

	// current allocation:
	// r0 - tmp
	// r1 - tmp
	// r2 - working mem ptr (.data + .bss)
	// r3 - .data final condition
	// r4 - .bss final condition
	// r5 - LMA data
	// r6 - CPACR (always loaded)
	// r7 - vector table to copy (usually 0x08000000)
	// r8 - final cond for itcm vector table
	// r9 - .itcm.text final conditipn
	// r10 - final cond for static initializers
	// r11 - final cond for static deinitializers

#if defined (__VFP_FP__) && !defined(__SOFTFP__)
	ldr r0, [r6]
	orr r0, r0, #(0xF << 20) // Set bits 20-23 to enable CP10 and CP11 coprocessors
	str r0, [r6]
#endif

	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r0,r1}
	stmia r2!, {r0,r1}
2:	cmp r2, r3
	bne 1b

	movs r0, #0
	movs r1, #0

	b 2f // need to skip in case of empty section
1:	stmia r2!, {r0,r1}
2:	cmp r2, r4
	bne 1b

	// current allocation:
	// r0 - 0
	// r1 - 0 - itcm working mem ptr (base is fixed at 0x00000000)
	// r2 -
	// r3 - tmp
	// r4 - tmp
	// r5 - LMA data
	// r6 - CPACR
	// r7 - vector table to copy (usually 0x08000000)
	// r8 - final cond for itcm vector table
	// r9 - .itcm.text final conditipn
	// r10 - final cond for static initializers
	// r11 - final cond for static deinitializers

	b 2f // need to skip in case of empty section
1:	ldmia r7!, {r3,r4}
	stmia r1!, {r3,r4}
2:	cmp r1, r8
	bne 1b

	// set SCB->VTOR (at 0xE000ED08) to itcm table
	str r0, [r6, #-0x80]

	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r3,r4}
	stmia r1!, {r3,r4}
2:	cmp r1, r9
	bne 1b

#ifndef __CRT_NO_STATIC_INITIALIZERS
	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r0}
	blx r0
2:	cmp r5, r10
	bne 1b
#endif

	bl main

#if !defined(__CRT_NO_STATIC_INITIALIZERS)&&!defined(__CRT_NORETURN_FROM_MAIN)
	// main returned, r5, r11 are preserved

	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r0}
	blx r0
2:	cmp r5, r11
	bne 1b

	b .
#endif
	
.balign 4
mem_init_symbols:
	.long __data_start__ // r2
	.long __data_end__ // r3
	.long __bss_end__ // r4
	.long __data_init_start__ // r5
	.long 0xE000ED88 // r6
	.long __isr_vector_table_start__ // r7
	.long __itcm_isr_vector_table_end__ // r8
	.long __itcm_text_end__ // r9
#if !defined(__CRT_NO_STATIC_INITIALIZERS)
	.long __init_array_end // r10
#if !defined(__CRT_NORETURN_FROM_MAIN)
	.long __fini_array_end // r11
#endif
#endif
