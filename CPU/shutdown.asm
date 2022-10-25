[bits 16]

global _shutdown


_shutdown:
    mov ah,    0x53    ;apm mode set
	mov al,    0x00    ;check apm, mode
	xor bx,    bx
	int    0x15
	jc    APM_error
	
	mov ah,    0x53
	mov al,    0x01    ;connect to amp, mode
	xor bx,    bx
	int    0x15
	jc    APM_error
	
	mov ah,    0x53
	mov al,    0x0e    ;sets version to 1.1
	mov ch,    0x01    ;version 1.0
	mov cl,    0x01    ;plus 0.1
	int    0x15
	
	mov ah,    0x53
	mov al,    0x08    ;change state of pm
	mov bx,    0x0001  ;for all devices
	mov cx,    0x0001  ;pm is on
	int    0x15
	jc APM_error
	
	mov ah,    0x53
	mov al,    0x07
	mov bx,    0x0001
	mov cx,    0x0003  ;shutdown
	int    0x15
	jc APM_error
	

	
APM_error:
    jmp $
	
	
	