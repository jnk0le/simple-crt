/*****************************************************************************
 * Minimal linker script for STM32H743                                       *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

/*
	uses minimal vector table for startup and catching hardfault/nmi
	actual vector table is placed in ITCM, startup code must initialize it (including VTOR)
	critical routines can be placed in .itcm.text
	.data and .bss are placed in D1
	DTCM can be allocated by ".dtcm.data" and ".dtcm.bss" sections
	buffers can be allocated in D2, D3 by ".Dx.noinit" sections
	heap is placed in D1
	stack is placed in DTCM
*/

OUTPUT_FORMAT("elf32-littlearm");
OUTPUT_ARCH(arm);

ENTRY(Reset_Handler);

MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 2048K
	
	/* flash mem can be used in dual banked mode at no perf penalty
	FLASH_B0 (rx) : ORIGIN = 0x08000000, LENGTH = 1024K
	FLASH_B1 (rx) : ORIGIN = 0x08100000, LENGTH = 1024K*/
	
	ITCM (rwx) : ORIGIN = 0x00000000, LENGTH = 64K
	DTCM (rw) : ORIGIN = 0x20000000, LENGTH = 128K
	
	SRAM_D1 (rwx) : ORIGIN = 0x24000000, LENGTH = 512K
	SRAM_D2 (rwx) : ORIGIN = 0x30000000, LENGTH = 288K
	
	/* D2 is merged from 3 memory regions
	SRAM1 - D2 - 128k - 0x30000000
	SRAM2 - D2 - 128k - 0x30020000
	SRAM3 - D2 - 32k - 0x30040000*/
	
	SRAM_D3 (rwx) : ORIGIN = 0x38000000, LENGTH = 64K
	SRAM_BCKUP (rwx) : ORIGIN = 0x38800000, LENGTH = 4K
}

__flash_start__ = ORIGIN(FLASH);
__flash_size__ = LENGTH(FLASH);
__flash_end__ = __flash_start__ + __flash_size__;

__itcm_start__ = ORIGIN(ITCM);
__itcm_size__ = LENGTH(ITCM);
__itcm_end__ = __itcm_start__ + __itcm_size__;

__dtcm_start__ = ORIGIN(DTCM);
__dtcm_size__ = LENGTH(DTCM);
__dtcm_end__ = __dtcm_start__ + __dtcm_size__;

__d1_start__ = ORIGIN(SRAM_D1);
__d1_size__ = LENGTH(SRAM_D1);
__d1_end__ = __d1_start__ + __d1_size__;

__d2_start__ = ORIGIN(SRAM_D2);
__d2_size__ = LENGTH(SRAM_D2);
__d2_end__ = __d2_start__ + __d2_size__;

__d3_start__ = ORIGIN(SRAM_D3);
__d3_size__ = LENGTH(SRAM_D3);
__d3_end__ = __d3_start__ + __d3_size__;

__min_stack_size__ = DEFINED(__min_stack_size__) ? __min_stack_size___ : 1024;
__min_heap_size__ = DEFINED(__min_heap_size__) ? __min_heap_size__ : 4096;

SECTIONS
{
	.text : ALIGN(4) {
		__text_start__ = .;
		KEEP(*(.startup_vector)) /* minimal startup vector to catch hardfault/nmi */
		*(.text .text.* .gnu.linkonce.t.*)
		. = ALIGN(4);
		__text_end__ = .;
	} > FLASH

	.rodata : ALIGN(4) {
		*(.rodata .rodata.* .gnu.linkonce.r.*)
		. = ALIGN(4);
	} > FLASH

	.data : ALIGN(8) {
		__data_start__ = .;
		*(.data .data.* .gnu.linkonce.d.*)
		. = ALIGN(8); /* will copy it by 8 bytes per round */
		__data_end__ = .;
	} > SRAM_D1 AT > FLASH

	__data_size__ = SIZEOF(.data);
	__data_init_start__ = LOADADDR(.data);

	.dtcm_data : ALIGN(8) {
		__dtcm_data_start__ = .;
		*(.dtcm.data .dtcm.data.*)
		*(.ramfunc .ramfunc.*)
		. = ALIGN(8); /* will copy it by 8 bytes per round */
		__dtcm_data_end__ = .;
	} > DTCM AT > FLASH

	__dtcm_data_size__ = SIZEOF(.dtcm_data);
	__dtcm_data_init_start__ = LOADADDR(.dtcm_data);

	.itcm_text : ALIGN(8) {
		__itcm_text_start__ = .;
		KEEP(*(.isr_vector_table))
		*(.itcm.text .itcm.text.*)
		. = ALIGN(8); /* will copy it by 8 bytes per round */
		__itcm_text_end__ = .;
	} > ITCM AT > FLASH

	__itcm_text_init_start__ = LOADADDR(.itcm_text);

	.tables : ALIGN(4) {
		__preinit_array_start = .;
		KEEP(*(SORT(.preinit_array*)))
		__preinit_array_end = .;

		__init_array_start = .;
		KEEP(*(SORT(.init_array*)))
		__init_array_end = .;

		*(vtable)
		*(.ARM.extab* .gnu.linkonce.armextab*)
		*(.ARM.exidx* .gnu.linkonce.armexidx*)
		*(.eh_frame*)
	} > FLASH

	/DISCARD/ : {
		.fini_array*
	}

	.bss : ALIGN(8) {
		__bss_start__ = .;
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)
		. = ALIGN(8); /* will clear it by 8 bytes per round */
		__bss_end__ = .;
	} > SRAM_D1

	__bss_size__ = SIZEOF(.bss);

	.dtcm_bss : ALIGN(8) {
		__dtcm_bss_start__ = .;
		*(.dtcm.bss .dtcm.bss.*)
		. = ALIGN(8); /* will clear it by 8 bytes per round */
		__dtcm_bss_end__ = .;
	} > DTCM

	__dtcm_bss_size__ = SIZEOF(.dtcm_bss);

	.noinit (NOLOAD) : ALIGN(4) {
		__noinit_start__ = .;
		*(.noinit .noint*)
		*(.D1.noinit .D1.noinit*)
		. = ALIGN(4);
		__noinit_end__ = .;
	} > SRAM_D1

	.dtcm_noinit (NOLOAD) : ALIGN(4) {
		__dtcm_noinit_start__ = .;
		*(.dtcm.noinit .dtcm.noinit*)
		. = ALIGN(4);
		__dtcm_noinit_end__ = .;
	} > DTCM

	.stack (NOLOAD) : ALIGN(8) {
		__main_stack_start__ = .;
	} > DTCM

	__main_stack_end__ = __dtcm_end__;

	ASSERT((__main_stack_start__ + __min_stack_size__) <= __dtcm_end__, "not enough space for stack")

	.heap (NOLOAD) : ALIGN(4) {
		__heap_start__ = .;
	} > SRAM_D1

	__heap_end__ = __d1_end__;

	ASSERT((__heap_start__ + __min_heap_size__) <= __d1_end__, "not enough space for heap")

	.D2_noinit (NOLOAD) : ALIGN(4) {
		__d2_noinit_start__ = .;
		*(.D2.noinit .D2.noinit.*)
		. = ALIGN(4);
		__d2_noinit_end__ = .;
	} > SRAM_D2

	.D3_noinit (NOLOAD) : ALIGN(4) {
		__d3_noinit_start__ = .;
		*(.D3.noinit .D3.noinit.*)
		. = ALIGN(4);
		__d3_noinit_end__ = .;
	} > SRAM_D3

	.bkp_noinit (NOLOAD) : ALIGN(4) {
		__bkp_noinit_start__ = .;
		*(.bkp.noinit .bkp.noinit.*)
		. = ALIGN(4);
		__bkp_noinit_end__ = .;
	} > SRAM_BCKUP
}