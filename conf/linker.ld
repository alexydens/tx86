OUTPUT_FORMAT("elf64-x86-64")
ENTRY(_start)

PHDRS
{
	text PT_LOAD;
	rodata PT_LOAD;
	data PT_LOAD;
	bss PT_LOAD;
}

SECTIONS
{
	. = 0x00100000;
	.text : ALIGN(4K) {
		*(.multiboot2)
		*(.text)
	} :text
	.rodata : ALIGN(4K) {
		*(.rodata)
	} :rodata
	.data : ALIGN(4K) {
		*(.data)
	} :data
	.bss : ALIGN(4K) {
		*(.bss)
		*(COMMON)
	} :bss
}

