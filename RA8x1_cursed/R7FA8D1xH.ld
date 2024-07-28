/*****************************************************************************
 * Minimal linker script for RA8D1xH, temporarily cursed for debugging from SRAM    *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

OUTPUT_FORMAT("elf32-littlearm");
OUTPUT_ARCH(arm);

ENTRY(Reset_Handler);

MEMORY
{
	FLASH (rx) : ORIGIN = 0x02000000, LENGTH = 2048K
	DATA_FLASH (rx) : ORIGIN = 0x27000000, LENGTH = 12K
	
	ITCM (rwx) : ORIGIN = 0x00000000, LENGTH = 64K
	DTCM (rw) : ORIGIN = 0x20000000, LENGTH = 64K
	
	SRAM (rwx) : ORIGIN = 0x22000000, LENGTH = 896K
	
	/* SRAM is merged from 2 memory regions
	SRAM_ECC    - 384k - 0x22000000
	SRAM_PARITY - 512k - 0x22060000*/
	
	SRAM_STB (rwx) : ORIGIN = 0x26000000, LENGTH = 1K
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

__sram_start__ = ORIGIN(SRAM);
__sram_size__ = LENGTH(SRAM);
__sram_end__ = __sram_start__ + __sram_size__;

__sram_stb_start__ = ORIGIN(SRAM_STB);
__sram_stb_size__ = LENGTH(SRAM_STB);
__sram_stb_end__ = __sram_stb_start__ + __sram_stb_size__;


__min_stack_size__ = DEFINED(__min_stack_size__) ? __min_stack_size___ : 1024;
__min_heap_size__ = DEFINED(__min_heap_size__) ? __min_heap_size__ : 4096;

SECTIONS
{
	.forced_reset_from_sram : ALIGN(4) {
		KEEP(*(.forced_reset_from_sram*))
	} > SRAM

	.text : ALIGN(4) {
		__text_start__ = .;
		*(.text .text.* .gnu.linkonce.t.*)
		__text_end__ = .;
	} > SRAM

	.rodata : ALIGN(4) {
		*(.rodata .rodata.* .gnu.linkonce.r.*)
	} > SRAM

	.data : ALIGN(4) {
		__data_start__ = .;
		*(.data .data.* .gnu.linkonce.d.*)
		. = ALIGN(4);
		__data_end__ = .;
	} > DTCM AT > SRAM

	__data_size__ = SIZEOF(.data);
	__data_init_start__ = LOADADDR(.data);

	.tables : ALIGN(4) {
		__preinit_array_start = .;
		KEEP(*(SORT(.preinit_array*)))
		__preinit_array_end = .;

		__init_array_start = .;
		KEEP(*(SORT(.init_array*)))
		__init_array_end = .;

		__fini_array_start = .;
 		KEEP(*(SORT(.fini_array*)))
		__fini_array_end = .;

		*(vtable)
		*(.ARM.extab* .gnu.linkonce.armextab*)
		*(.ARM.exidx* .gnu.linkonce.armexidx*)
		*(.eh_frame*)
	} > SRAM

	.isr_vector_table : ALIGN(4) {
		__isr_vector_table_start__ = .;
		KEEP(*(.isr_vector_table))
		__isr_vector_table_end__ = .;
	} > ITCM AT > SRAM
	
	__isr_vector_table_init_start__ = LOADADDR(.data);

	.bss : ALIGN(4) {
		__bss_start__ = .;
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > DTCM

	__bss_size__ = SIZEOF(.bss);

	.noinit (NOLOAD) : ALIGN(4) {
		__noinit_start__ = .;
		*(.noinit .noint*)
		__noinit_end__ = .;
	} > DTCM

	.stack (NOLOAD) : ALIGN(8) {
		__main_stack_start__ = .;
	} > DTCM

	__main_stack_end__ = __dtcm_end__;
	
	ASSERT((__main_stack_start__ + __min_stack_size__) <= __dtcm_end__, "not enough space for stack")



	.heap (NOLOAD) : ALIGN(4) {
		__heap_start__ = .;
	} > SRAM

	__heap_end__ = __sram_end__;

	ASSERT((__heap_start__ + __min_heap_size__) <= __sram_end__, "not enough space for heap")
}