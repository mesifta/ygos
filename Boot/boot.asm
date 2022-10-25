[bits 16]
[org 0x7c00]                ;sets the code offset in memory
    
	KERNEL_OFFSET equ 0x1000 
	
	mov [BOOT_DRIVE],    dl


    mov ax,    0x0003       ;clears screen
	int    0x10
	
	mov bp,    0x9000       ;sets stack base at 0x9000
	mov sp,    bp           ;sets stack top pointer
	
	
	call load_kernel
	
	call switch_32
	
;---------------------------------------------------------------------------------------------	
[bits 16]
    
  load_kernel:
	mov bx,    KERNEL_OFFSET    ;sets location in memory where to load kernel
	mov dh,    34              ;sectors to load
	mov dl,    [BOOT_DRIVE]     ;selects drive
	call disk_load
	
	ret
	
;~~~~~~~~~~~~~~~~~~

[bits 32]  
  BEGIN_32BIT:
  
    call KERNEL_OFFSET       ;starts kernel
	
	jmp $                   ;endless loop
	
;---------------------------------------------------------------------------------------------

	%include "print.asm"
	%include "disk.asm"
	%include "gdt.asm"
	%include "switch_32.asm"
	
;-----------------------------------------------------------------------------------------------
	BOOT_DRIVE: db 0
	
	times 510-($-$$) db 0   ;fills rest of 512 bytes with 0
	
	dw 0xaa55               ;declares magic bootable number
	
