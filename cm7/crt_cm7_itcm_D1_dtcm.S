/*****************************************************************************
 * cortex-m7 minimum startup code including itcm initialization              *
 * vector table is copied and remapped into itcm                             *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

// assumptions:
// - initialized sections are 8 byte aligned (including the section end symbol)
// - actual vector table is placed at the beginning of .itcm.text
// - .bss is right after .data in RAM
// - .dtcm_bss is right after .dtcm_data
// - .dtcm.data LMA is right after .data LMA in FLASH
// - .itcm.text LMA is right after .dtcm.data LMA in FLASH
// - .preinit_array is right after .itcm.text LMA
// - .init_array is right after .preinit_array
// - .fini_array is right after .init_array
// - data/bss SRAM, DTCM and ITCM are enabled from reset
// - ITCM is fixed at 0x00000000
// - DTCM is fixed at 0x20000000
// - .itcm.text and .dtcm.data start at beginning of ITCM/DTCM
// - main() is not expected to return

.syntax unified
.thumb

.section .startup_vector, "ax", %progbits

// minimal vector table for startup and catching hardfault/nmi
.global __startup_vector
__startup_vector:
	.long __main_stack_end__
	.long Reset_Handler
	.long NMI_Handler
	.long HardFault_Handler
	// the rest must be enabled, so they won't fire before vtor is remapped

.text // reset handler can be anywhere

.thumb_func
.global Reset_Handler
.balign 4
Reset_Handler:
	adr r0, mem_init_symbols

	ldmia r0!, {r2-r10}

	// current allocation:
	// r0 - tmp
	// r1 - tmp
	// r2 - working mem ptr (.data + .bss)
	// r3 - .data final condition
	// r4 - .bss final condition
	// r5 - LMA data (all)
	// r6 - CPACR (always loaded)
	// r7 - .dtcm.data final condition
	// r8 -	.dtcm.bss final condition
	// r9 - .itcm.text final condition
	// r10 - final cond for static initializers

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

	mov.w r3, #0x20000000 // __dtcm_data_start__

	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r0,r1}
	stmia r3!, {r0,r1}
2:	cmp r3, r7
	bne 1b

	movs r0, #0
	movs r1, #0

	b 2f // need to skip in case of empty section
1:	stmia r2!, {r0,r1}
2:	cmp r2, r4
	bne 1b

	b 2f // need to skip in case of empty section
1:	stmia r3!, {r0,r1}
2:	cmp r3, r8
	bne 1b

	// zero init rest of DTCM/SRAM for ECC?

	// current allocation:
	// r0 - 0
	// r1 - 0 - itcm working mem ptr (base is fixed at 0x00000000)
	// r2 -
	// r3 - tmp
	// r4 - tmp
	// r5 - LMA data
	// r6 - CPACR (0xE000ED88)
	// r7 -
	// r8 -
	// r9 - .itcm.text final condition
	// r10 - final cond for static initializers

	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r3,r4}
	stmia r1!, {r3,r4}
2:	cmp r1, r9
	bne 1b

	// zero init rest of ITCM for ECC?

	// set SCB->VTOR (at 0xE000ED08) to itcm table
	// remap before calling into the user code
	str r0, [r6, #-0x80]

	isb // just in case

	b 2f // need to skip in case of empty section
1:	ldmia r5!, {r0}
	blx r0
2:	cmp r5, r10
	bne 1b

	bl main

	b . // loop here, in case main returns

.balign 4
mem_init_symbols:
	.long __data_start__ // r2
	.long __data_end__ // r3
	.long __bss_end__ // r4
	.long __data_init_start__ // r5
	.long 0xE000ED88 // r6
	.long __dtcm_data_end__ // r7
	.long __dtcm_bss_end__ // r8
	.long __itcm_text_end__ // r9
	.long __init_array_end // r10

