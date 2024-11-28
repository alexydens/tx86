void kmain(void) {
  unsigned short port = 0x3f8;
  unsigned char val = 'A';
  __asm__ __volatile__ ("outb %b0,%w1" :: "a"(val), "Nd" (port));
  while (1) __asm__ __volatile__ ("cli; hlt");
}
