[bits 16]

disk_load:
    push dx
	
    mov ah,    0x02      ;disk reading mode
	mov al,    dh        ;read DH sectors
	mov ch,    0x00      ;cylinder number
	mov dh,    0x00      ;second side of floppy
	
	mov cl,    0x02      ;fourth sector
	
	int 0x13
	
	jc disk_error        ;jump if C flag
	
	pop dx        
	cmp dh,    al        ;compares sectors read to sectors to be read
	jne disk_error
	
	ret
	
disk_error:
    mov bx,    err_msg
    call print_line
	jmp $
	
err_msg:
    db '  Error Reading Disk!', 0
	
