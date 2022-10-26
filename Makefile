#$< is first dependency $^ is all dependencies $@ is destination file

C_SOURCES = $(wildcard Kernel/*.c Drivers/*.c CPU/*.c Util/*.c Include/*.c)
HEADERS = $(wildcard Kernel/*.h Drivers/*.h CPU/*.h Util/*.h)
OBJ = ${C_SOURCES:.c=.o}

all: os-image
	qemu-system-x86_64 -hda os-image 
	
run: all clean
	

os-image: boot.bin kernel.bin buff.bin
	cat $^ > os-image

kernel.bin: Kernel/entry.o CPU/interrupt.o CPU/exc.o Util/str.o CPU/switch_16.o CPU/shutdown.o ${OBJ}
	ld -T NUL -o kernel.tmp -Ttext 0x1000 $^
	objcopy -O binary -j .text  kernel.tmp $@


%.o : %.c ${HEADERS}
	gcc -ffreestanding -c $< -o $@
	
Kernel/entry.o: Boot/entry.asm
	nasm $< -f elf32 -o $@

CPU/exc.o: CPU/exc.asm
	nasm $< -f elf32 -o $@

CPU/interrupt.o: CPU/interrupt.asm
	nasm $< -f elf32 -o $@

Util/str.o: Util/str.asm
	nasm $< -f elf32 -o $@

CPU/switch_16.o: CPU/switch_16.asm
	nasm $< -f elf32 -o $@

CPU/shutdown.o: CPU/shutdown.asm
	nasm $< -f elf32 -o $@
	
boot.bin : Boot/boot.asm 
	nasm -I 'Boot' $< -f bin -o $@

buff.bin : Boot/buff.asm 
	nasm -I 'Boot' $< -f bin -o $@
	
clean:
	rm -fr *.bin *.o *.tmp 
	rm -fr Kernel/*.o Boot/*.bin Drivers/*.o Util/*.o CPU/*.o Include/*.o