/* The size of the boostrap stack */
#define STACK_SIZE	    0xffff

/* The multiboot header and tags */
.section .multiboot2
mb2_header_start:
  /* Header */
  .long 0xE85250D6                        /* Magic number */
  .long 0                                 /* Architecture */
  .long mb2_header_end - mb2_header_start /* Header length */
  /* Checksum */
  .long 0x100000000 - (0xe85250d6 + 0 + (mb2_header_end - mb2_header_start))

  /* Tags */
  /* End tag */
  .long 0   /* Type */
  .long 0   /* Flags */
  .long 8   /* Size */
mb2_header_end:

.section .bss
.globl stack_top, stack_bottom
/* The bootstrap stack (just defined like a big global variable */
stack_top:
  .skip STACK_SIZE
stack_bottom:

.section .text
.extern kmain
/* The entry point */
.globl _start
_start:
  /* Set up the stack */
  mov $stack_top, %esp

  /* Call main kernel */
  call kmain

  /* Halt (loops indefinitely) */
1:
  cli
  hlt
  jmp 1b

