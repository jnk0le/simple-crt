/*****************************************************************************
 * Minimal linker script for STM32L010x8                                     *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
 * License: CC0                                                              *
 *****************************************************************************/

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm");
OUTPUT_ARCH(arm);

ENTRY(Reset_Handler);

MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
	EEPROM (rx) : ORIGIN = 0x08080000, LENGTH = 256
	RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
}

__flash_start__ = ORIGIN(FLASH);
__flash_size__ = LENGTH(FLASH);
__flash_end__ = __flash_start__ + __flash_size__;

__ram_start__ = ORIGIN(RAM);
__ram_size__ = LENGTH(RAM);
__ram_end__ = __ram_start__ + __ram_size__;

__min_stack_size__ = DEFINED(__min_stack_size__) ? __min_stack_size___ : 256;
__min_heap_size__ = DEFINED(__min_heap_size__) ? __min_heap_size__ : 0;

SECTIONS
{
	.isr_vector_table : ALIGN(4) {
		PROVIDE(__isr_vector_table_start__ = .);
		KEEP(*(.isr_vector_table));
		PROVIDE(__isr_vector_table_end__ = .);
	} > FLASH

	.text : ALIGN(4) {
		PROVIDE(__text_start__ = .);
		
		*(.text* .gnu.linkonce.t*);
		
		KEEP(*(.init))
		KEEP(*(.fini))
		
		PROVIDE(__text_end__ = .);
	} > FLASH

	.rodata : ALIGN(4) {
		*(.rodata* .gnu.linkonce.r*);
	} > FLASH

	.tables : ALIGN(4) {
		PROVIDE(__preinit_array_start = .);
		KEEP(*(SORT(.preinit_array*))) 
		KEEP(*(.preinit_array))
		PROVIDE(__preinit_array_end = .);
	
		PROVIDE(__init_array_start = .);
		KEEP(*(SORT(.init_array*)))
		PROVIDE(__init_array_end = .);
		
		PROVIDE(__fini_array_start = .);
 		KEEP(*(SORT(.fini_array*)))
		PROVIDE(__fini_array_end = .);
	
		*(vtable)
		*(.ARM.extab* .gnu.linkonce.armextab*)
		*(.ARM.exidx* .gnu.linkonce.armexidx*)
		*(.eh_frame*)
	} > FLASH

	.eeprom : {
		*(.eeprom*)
	} > EEPROM

	.data : ALIGN(4) {
		PROVIDE(__data_start__ = .);
		*(.data* .gnu.linkonce.d.*)
		PROVIDE(__data_end__ = .);
	} > RAM AT > FLASH

	PROVIDE(__data_init_start__ = LOADADDR(.data));

	.bss : ALIGN(4) {
		PROVIDE(__bss_start__ = .);
		*(.bss* .gnu.linkonce.b.*)
		*(COMMON)		
		PROVIDE(__bss_end__ = .);
	} > RAM

	.noinit (NOLOAD) : ALIGN(4) {
		PROVIDE(__noinit_start__ = .);
		*(.noinit*) 
		PROVIDE(__noinit_end__ = .);
	} > RAM

	.heapstack_check (NOLOAD) : ALIGN(4) {
		__heap_start__ = .;
		. = . + __min_heap_size__;
		. = . + __min_stack_size__;
		. = ALIGN(8);
	} > RAM

	__heap_end__ = __ram_end__ - __min_stack_size__;
	__main_stack_end__ =  __ram_end__;
}