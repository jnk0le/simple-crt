/*****************************************************************************
 * cortex-m85 startup code, temporarily cursed for RA8 starting from SRAM, not optimized    *
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
//.text
.section .forced_reset_from_sram, "ax", %progbits

.thumb_func
.global Reset_Handler
.balign 4
Reset_Handler:
	// startup from sram is a little messy
	ldr sp, =__main_stack_end__ // stack

	// load irq handlers to itcm, as the gdb just resumes exec to sram
	ldr r1, =__isr_vector_table_start__
	//ldr r2, =__isr_vector_table_end__
	//ldr r3, =__isr_vector_table_init_start__

	ldr r5, =0xE000ED08 // SCB->VTOR
	str r1, [r5]

	/*b 2f
1:	ldr r0, [r3], #4
	str r0, [r1], #4
2:	cmp r1, r2
	bne 1b*/

	// initialize entire dtcm to clear out ECC errors (can extend bss)
	ldr r0, =0xdeadbeef
	ldr r1, =__dtcm_start__
	ldr r2, =__dtcm_end__

1:	str r0, [r1], #4
2:	cmp r1, r2
	bne 1b

	//copypaste from cm4

	adr r0, mem_init_symbols

	ldmia r0!, {r1-r6}

//#if defined (__VFP_FP__) && !defined(__SOFTFP__)
	ldr r0, [r1] // cannot be pipelined after literal loads anyway
	orr r0, #(0b11 << 20)|(0b11 << 22) // enable CP10 and CP11 coprocessors (FPU)
	str r0, [r1]
//#endif
	dsb
	isb

	b 2f // need to skip in case of empty section
	nop // padding for loop

1:	ldr r0, [r5], #4
	str r0, [r2], #4
2:	cmp r2, r3
	bne 1b

	movs r0, #0

	b 2f // need to skip in case of empty section
1:	str r0, [r2], #4
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

	b .

.balign 4
mem_init_symbols:
	.long 0xE000ED88 // r1
	.long __data_start__ // r2
	.long __data_end__ // r3
	.long __bss_end__ // r4
	.long __data_init_start__ // r5
	.long __init_array_end // r6
