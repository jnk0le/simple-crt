/*****************************************************************************
 * Minimal linker script for STM32F407xE with data, bss and stack in CCM     *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
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
	.isr_vector_table : ALIGN(4) {
		__isr_vector_table_start__ = .;
		KEEP(*(.isr_vector_table))
		__isr_vector_table_end__ = .;
	} > FLASH

	.text : ALIGN(4) {
		__text_start__ = .;
		
		*(.text .text.* .gnu.linkonce.t.*)
		
		KEEP(*(.init))
		KEEP(*(.fini))
		
		__text_end__ = .;
	} > FLASH

	.rodata : ALIGN(4) {
		*(.rodata .rodata.* .gnu.linkonce.r.*)
	} > FLASH

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
	} > FLASH

	.data : ALIGN(4) {
		__data_start__ = .;
		*(.data* .data.* .gnu.linkonce.d.*)
		__data_end__ = .;
	} > CCM AT > FLASH

	__data_init_start__ = LOADADDR(.data);

	.bss : ALIGN(4) {
		__bss_start__ = .;
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)
		__bss_end__ = .;
	} > CCM

	.noinit (NOLOAD) : ALIGN(4) {
		__noinit_start__ = .;
		*(.noinit .noinit.*)
		__noinit_end__ = .;
	} > CCM

	__heap_end__ = __ram_end__;

	/*.ram_data : ALIGN(4) {
		__ram_data_start__ = .;
		*(.ram.data .ram.data.*)
		__ram_data_end__ = .;
	} > RAM AT > FLASH
	
	__ram_data_init_start__ = LOADADDR(.data);
	
	.ram_bss : ALIGN(4) {
		__ram_bss_start__ = .;
		*(.ram.bss .ram.bss.*)
		__ram_bss_end__ = .;
	} > RAM
	*/

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
}
