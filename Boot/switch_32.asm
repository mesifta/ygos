[bits 16]

switch_32:
    cli                        ;clear interrupt
	lgdt    [gdt_descripter]   ;load gdt_descripter
	
	mov eax,    cr0            ;sets control register
	or eax,    0x1             ;lowest bit of cr0 1=32 bit mode 0=16 bit mode
	mov cr0,    eax
	
	jmp CODE_SEG:init_PM
	

[bits 32]

init_PM:
    mov ax,    DATA_SEG
	
	mov ds,    ax               ;sets segment registers
	mov ss,    ax
	mov es,    ax
	mov fs,    ax
	mov gs,    ax
	
	mov ebp,    0x8f0000          ;sets up 32BIT stack
	mov esp,    ebp
	
	
	call BEGIN_32BIT
	