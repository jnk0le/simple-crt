/*****************************************************************************
 * Minimal linker script for CH32V003x4                                      *
 * Author : Jan Oleksiewicz <jnk0le@hotmail.com>                             *
 * License: CC0                                                              *
 *****************************************************************************/

OUTPUT_FORMAT("elf32-littleriscv")
OUTPUT_ARCH(riscv);

ENTRY(__irq_vector_table);

MEMORY
{
	FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 16K
	RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 2K
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
		__isr_vector_table_start__ = .;
		KEEP(*(.isr_vector_table))
		__isr_vector_table_end__ = .;
	} > FLASH

	/* FLASH starts at 0, so put rodata here to allow pure imm12 addressing */
	.rodata : ALIGN(4) {
		*(.srodata .srodata.*)
		*(.rodata .rodata.* .gnu.linkonce.r.*) 
	} > FLASH

	.text : ALIGN(2) {
		__text_start__ = .;
		*(.text .text.* .gnu.linkonce.t.*)
		__text_end__ = .;
	} > FLASH

	/* .data LMA must be placed before before static constructors */
	.data : ALIGN(4) {
		__data_start__ = .;
		*(.data .data.* .gnu.linkonce.d.*)
		*(.sdata .sdata.* .gnu.linkonce.s.*)
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

		/*__fini_array_start = .;
 		KEEP(*(SORT(.fini_array*)))
		__fini_array_end = .;*/

		*(vtable)
		*(.eh_frame*)
	} > FLASH

 	.bss : ALIGN(4) {
		__bss_start__ = .;
		*(.sbss .sbss.* .gnu.linkonce.sb.*)
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
	} > RAM

	/* there is only 2KiB of SRAM so we can load it in a single c.mv this way */
 	__global_pointer$ = __bss_end__;
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
	__main_stack_end__ = __ram_end__;

	/* make an 11 bit offset to initialize stack pointer by using __bss_end__,
	cut off 4 bytes in rare case of empty .data and .bss as to fit in single addi instruction */
	__ch32v003_bsstostack_offset__ = ((__data_size__ + __bss_size__) == 0 ) ? 2044 : (__main_stack_end__ - __bss_end__);

	ASSERT((__heap_start__ + __min_heap_size__ + __min_stack_size__) <= __ram_end__, "not enough space for heap and stack")
}