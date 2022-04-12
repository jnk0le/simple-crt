/*****************************************************************************
 * Minimal linker script for STM32H743                                       *
 * Author : jnk0le@hotmail.com                                               *
 *          https://github.com/jnk0le                                        *
 * License: CC0                                                              *
 *****************************************************************************/

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm");
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
	.isr_vector_table : ALIGN(8) {
		PROVIDE(__isr_vector_table_start__ = .);
		KEEP(*(.isr_vector_table));
		. = ALIGN(8); /* will copy it by 8 bytes per round */
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

	.data : ALIGN(8) {
		PROVIDE(__data_start__ = .);
		*(.data* .gnu.linkonce.d*)
		. = ALIGN(8); /* will copy it by 8 bytes per round */
		PROVIDE(__data_end__ = .);
	} > DTCM AT > FLASH

	PROVIDE(__data_init_start__ = LOADADDR(.data));

	.bss : ALIGN(8) {
		PROVIDE(__bss_start__ = .);
		*(.bss* .gnu.linkonce.b*)
		*(COMMON)
		. = ALIGN(8); /* will clear it by 8 bytes per round */
		PROVIDE(__bss_end__ = .);
	} > DTCM

	.noinit (NOLOAD) : ALIGN(4) {
		PROVIDE(__noinit_start__ = .);
		*(.noinit*) 
		PROVIDE(__noinit_end__ = .);
	} > DTCM

	.stack (NOLOAD) : ALIGN(8) {
		__main_stack_start__ = .;
	} > DTCM

	__main_stack_end__ =  __dtcm_end__;
	
	ASSERT((__main_stack_start__ + __min_stack_size__) <= __dtcm_end__, "not enough space for stack")

	/* allocate space for vector table that needs to be
	   copied and relocated (VTOR offset) by software */
	.itcm_isr_vectors (NOLOAD) : ALIGN(8) {
		PROVIDE(__itcm_isr_vector_table_start__ = .);
		. += (__isr_vector_table_end__ - __isr_vector_table_start__);
		. = ALIGN(8); /* will copy it by 8 bytes per round */
		PROVIDE(__itcm_isr_vector_table_end__ = .);
	} > ITCM

	.itcm_text : ALIGN(8) {
		PROVIDE(__itcm_text_start__ = .);
		*(.itcm.text*)
		. = ALIGN(8); /* will copy it by 8 bytes per round */
		PROVIDE(__itcm_text_end__ = .);
	} > ITCM AT > FLASH

	PROVIDE(__itcm_text_init_start__ = LOADADDR(.itcm_text));

	.D1_noinit (NOLOAD) : ALIGN(4) {
		PROVIDE(__d1_noinit_start__ = .);
		*(.D1.noinit*)
		PROVIDE(__d1_noinit_end__ = .);
	} > SRAM_D1

	.heap (NOLOAD) : ALIGN(4) {
		__heap_start__ = .;
	} > SRAM_D1

	__heap_end__ = __d1_end__;

	ASSERT((__heap_start__ + __min_heap_size__) <= __d1_end__, "not enough space for heap")

	.D2_noinit (NOLOAD) : ALIGN(4) {
		PROVIDE(__d2_noinit_start__ = .);
		*(.D2.noinit*)
		PROVIDE(__d2_noinit_end__ = .);
	} > SRAM_D2

	.D3_noinit (NOLOAD) : ALIGN(4) {
		PROVIDE(__d3_noinit_start__ = .);
		*(.D3.noinit*)
		PROVIDE(__d3_noinit_end__ = .);
	} > SRAM_D3

	.bkp_noinit (NOLOAD) : ALIGN(4) {
		PROVIDE(__bkp_noinit_start__ = .);
		*(.bkp.noinit*)
		PROVIDE(__bkp_noinit_end__ = .);
	} > SRAM_BCKUP
}