/*****************************************************************************
 * cortex-m7 minimum startup code                                            *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
 * License: CC0                                                              *
 *****************************************************************************/

.syntax unified
.thumb

.text
.balign 2
.thumb_func
.global Reset_Handler
Reset_Handler:

#if defined (__VFP_FP__) && !defined(__SOFTFP__)
	// SCB->CPACR |= (3UL << 20) | (3UL << 22);
	ldr r1, =0xE000ED88 // Load CPACR addr
	ldr r0, [r1]
	orr r0, r0, #(0xF << 20) // Set bits 20-23 to enable CP10 and CP11 coprocessors
	str r0, [r1]
#endif

	ldr r2, =__data_init_start__
	ldr r3, =__data_start__
	ldr r4, =__data_end__

	b 2f // section size is not known during compilation so it have to be used in case of empty section
1:	ldrd r0,r1, [r2], #8
	strd r0,r1, [r3], #8
2:	cmp r3, r4
	bne 1b

	//ldr r3, =__bss_start__  // reuse __data_end__ as __bss_start__
	// .bss have to be placed right after the .data section
	ldr r4, =__bss_end__

	movs r0, #0
	movs r1, #0

	b 2f // section size is not known during compilation so it have to be used in case of empty section
1:	strd r0,r1, [r3], #8
2:	cmp r3, r4
	bne 1b

	ldr r1, =__itcm_isr_vector_table_start__
	ldr r3, =__isr_vector_table_start__
	ldr r4, =__isr_vector_table_end__

	b 2f // section size is not known during compilation so it have to be used in case of empty section
1:	ldrd r5,r6, [r3], #8
	strd r5,r6, [r1], #8
2:	cmp r3, r4
	bne 1b

	//ldr r1, =__itcm_text_start__ // reuse __itcm_isr_vector_table_end__ as __itcm_text_start__
	//ldr r2, =__itcm_text_init_start__ // reuse __data_init_end__ as __itcm_init_start__
	// .itcm_text have to be stored right after .data in flash
	ldr r3, =__itcm_text_end__

	b 2f // section size is not known during compilation so it have to be used in case of empty section
1:	ldrd r5,r6, [r2], #8
	strd r5,r6, [r1], #8
2:	cmp r1, r3
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
