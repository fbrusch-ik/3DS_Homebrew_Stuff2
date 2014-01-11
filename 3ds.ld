ENTRY(_Homebrew)
SECTIONS
{
 . = 0x080C3EE0;
 .text : {
 bootloader.o (START_VECTOR)
 *(.text)
 }
 .data : { *(.data) }
 .bss : { *(.bss COMMON) }
 . = ALIGN(4);
 . = . + 0x8000000; /* 4kB of stack memory */
 stack_top = .;
}