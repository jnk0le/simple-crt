/*****************************************************************************
 * Minimal linker script for STM32F030xC                                     *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

OUTPUT_FORMAT("elf32-littlearm");
OUTPUT_ARCH(arm);

ENTRY(Reset_Handler);

MEMORY
{
	FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
	RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 32K
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
	.text : ALIGN(4) {
		__text_start__ = .;
		KEEP(*(.isr_vector_table))
		*(.text .text.* .gnu.linkonce.t.*)
		*(.rodata .rodata.* .gnu.linkonce.r.*)
		__text_end__ = .;
	} > FLASH

	/* .data LMA must be placed before static constructors */
	.data : ALIGN(4) {
		__data_start__ = .;
		*(.ramfunc .ramfunc.*)
		*(.data .data.* .gnu.linkonce.d.*)
		. = ALIGN(4);
		__data_end__ = .;
	} > RAM AT > FLASH

	__data_size__ = SIZEOF(.data);
	__data_init_start__ = LOADADDR(.data);

	.tables : ALIGN(4) {
		__preinit_array_start = .;
		KEEP(*(SORT(.preinit_array*)))
		__preinit_array_end = .;

		__init_array_start = .;
		KEEP(*(SORT(.init_array*)))
		__init_array_end = .;

		*(vtable)
	} > FLASH

	/DISCARD/ : {
		.fini_array*
		*(.ARM.extab* .gnu.linkonce.armextab*)
		*(.ARM.exidx* .gnu.linkonce.armexidx*)
		*(.eh_frame*)
	}

	.bss (NOLOAD) : ALIGN(4) {
		__bss_start__ = .;
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > RAM

	__bss_size__ = SIZEOF(.bss);

	.noinit (NOLOAD) : ALIGN(4) {
		__noinit_start__ = .;
		*(.noinit .noinit.*)
		__noinit_end__ = .;
	} > RAM

	.heapstack (NOLOAD) : ALIGN(4) {
		__heap_start__ = .;
	} > RAM

	__heap_end__ = __ram_end__ - __min_stack_size__;
	__main_stack_end__ =  __ram_end__;

	ASSERT((__heap_start__ + __min_heap_size__ + __min_stack_size__) <= __ram_end__, "not enough space for heap and stack")
}