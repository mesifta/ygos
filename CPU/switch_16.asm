global _switch_16

gdt_start:

gdt_null:
    dq    0x0          ;8 byte null descripter
	

gdt_code:
    dw    0xffff       ;limit(0-15) 
	dw    0x0          ;base(0-15)
	db    0x0          ;base(16-23)
	db    10011010b    ;flags
	db    00001111b    ;flags, limit(16-19)
	db    0x0          ;base(24-31)
	
gdt_data:
    dw    0xffff
	dw    0x0
	db    0x0
	db    10010010b
	db    00001111b
	db    0x0
	
gdt_end:

gdt_descripter:
    dw    gdt_end - gdt_start - 1    ;size of gdt_descripter
	dd    gdt_start                  ;address of gdt_descripter
	

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

idt_real:
	    dw 0x3ff
		dd 0

[bits 32]

saveCR0:
	dd 0
		
_switch_16:
    cli
	
	lgdt    [gdt_descripter]
	
	jmp    CODE_SEG:protected_16

[bits 16]
protected_16:
	mov eax,    DATA_SEG
	
	mov ds,    eax
	mov es,    eax
	mov fs,    eax
	mov gs,    eax
	mov ss,    eax
	
		
	mov eax,    cr0
	mov [saveCR0],    eax
	and eax,    0x7FFFFFFe
	mov cr0,    eax
	
	jmp    0:real_mode

[bits 16]
real_mode:
    mov bp,    0x8000
	mov sp,    bp
	
	mov ax,    0
	mov ds,    ax
	mov es,    ax
	mov fs,    ax
	mov gs,    ax
	mov ss,    ax
	
	lidt    [idt_real]
	sti
