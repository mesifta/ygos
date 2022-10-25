[bits 16]
	
print_line:
    pusha   	        ;pushes registers on the stack	  
    mov ah,    0x0e     ;sets BIOS text mode
    
	mov al,    [bx]  
	
  ;looping through string
  exec: 
    int    0x10
	
	add bx,    1
	mov al,    [bx]
	cmp al,    0        ;check for NULL end of string
	jne exec
	
	popa
	ret 