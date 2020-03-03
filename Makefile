OBJECTS = loader.o io.o fb.o kmem.o kmemory.o gdt.o gdt_asm.o kmain.o pic.o kinterrupts.o kinterrupts_asm.o idt_setup.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
		--target=i386-jos-elf -nostartfiles -ffreestanding -nodefaultlibs -Wall -Wextra -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	 /usr/local/i386elfgcc/bin/i386-elf-ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	 mkisofs -R                              \
                -b boot/grub/stage2_eltorito    \
                -no-emul-boot                   \
                -boot-load-size 4               \
                -A os                           \
                -input-charset utf8             \
                -quiet                          \
                -boot-info-table                \
                -o os.iso                       \
                iso

run: os.iso
	 bochs -f bochsrc.txt -q

%.o: %.c
	 $(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	 $(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso
