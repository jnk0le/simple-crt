/*****************************************************************************
 * Minimal linker script for STM32F407xE with data, bss and stack in CCM     *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/
 
OUTPUT_FORMAT("elf32-littlearm");
OUTPUT_ARCH(arm);

ENTRY(Reset_Handler);

MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 512K
	RAM (rw) : ORIGIN = 0x20000000, LENGTH = 128K /* rwx? */
	
	/* RAM is merged from 2 memory regions
	SRAM1 (rwx) : ORIGIN = 0x20000000, LENGTH = 112K
	SRAM2 (rw) : ORIGIN = 0x2001C000, LENGTH = 16K*/
	
	CCM (rw) : ORIGIN = 0x10000000, LENGTH = 64K
	SRAM_BCKUP (rw) : ORIGIN = 0x40024000, LENGTH = 4K
}

__flash_start__ = ORIGIN(FLASH);
__flash_size__ = LENGTH(FLASH);
__flash_end__ = __flash_start__ + __flash_size__;

__ram_start__ = ORIGIN(RAM);
__ram_size__ = LENGTH(RAM);
__ram_end__ = __ram_start__ + __ram_size__;

__ccm_start__ = ORIGIN(CCM);
__ccm_size__ = LENGTH(CCM);
__ccm_end__ = __ccm_start__ + __ccm_size__;

__min_stack_size__ = DEFINED(__min_stack_size__) ? __min_stack_size___ : 1024;
__min_heap_size__ = DEFINED(__min_heap_size__) ? __min_heap_size__ : 4096;

SECTIONS
{
	.text : ALIGN(4) {
		__text_start__ = .;
		KEEP(*(.isr_vector_table))
		*(.text .text.* .gnu.linkonce.t.*)
		*(.rodata .rodata.* .gnu.linkonce.r.*)
		. = ALIGN(4); 
		*(vtable)
		. = ALIGN(4); /* must align to keep .data LMA 4 byte aligned */
		__text_end__ = .;
	} > FLASH

	.data : ALIGN_WITH_INPUT {
		__data_start__ = .;
		*(.data* .data.* .gnu.linkonce.d.*)
		. = ALIGN(4);
		__data_end__ = .;
	} > CCM AT > FLASH

	__data_size__ = SIZEOF(.data);
	__data_init_start__ = LOADADDR(.data);

	.init_tables : ALIGN_WITH_INPUT {
		__preinit_array_start = .;
		KEEP(*(SORT(.preinit_array*)))
		__preinit_array_end = .;

		__init_array_start = .;
		KEEP(*(SORT(.init_array*)))
		__init_array_end = .;
	} > FLASH

	/* ALIGN_WITH_INPUT doesn't work here, but starting address can be forced to the data end symbol */
	.bss (__data_end__) (NOLOAD) : ALIGN(4) {
		__bss_start__ = .;
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > CCM

	__bss_size__ = SIZEOF(.bss);

	.noinit (NOLOAD) : ALIGN(4) {
		__noinit_start__ = .;
		*(.noinit .noinit.*)
		__noinit_end__ = .;
	} > CCM

	__heap_end__ = __ram_end__;

	.ram_noinit (NOLOAD) : ALIGN(4) {
		__ram_noinit_start__ = .;
		*(.ram.noinit .ram.noinit.*)
		__ram_noinit_end__ = .;
	} > RAM

	.heap (NOLOAD) : ALIGN(4) {
		__heap_start__ = .;
	} > RAM

	__heap_end__ = __ram_end__;

	ASSERT((__heap_start__ + __min_heap_size__) <= __ram_end__, "not enough space for heap")

	.stack (NOLOAD) : ALIGN(8) {
		__main_stack_start__ = .;
	} > CCM

	__main_stack_end__ =  __ccm_end__;

	ASSERT((__main_stack_start__ + __min_stack_size__) <= __ccm_end__, "not enough space for stack")

	.bkp_noinit (NOLOAD) : ALIGN(4) {
		__bkp_noinit_start__ = .;
		*(.bkp.noinit .bkp.noinit.*)
		__bkp_noinit_end__ = .;
	} > SRAM_BCKUP

	/DISCARD/ : {
		.fini_array*
		*(.ARM.extab* .gnu.linkonce.armextab*)
		*(.ARM.exidx* .gnu.linkonce.armexidx*)
		*(.eh_frame*)
	}
}
