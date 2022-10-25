//receive byte to device control port register
unsigned char port_byte_in(unsigned short port){
	unsigned char result;
	__asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
	return result;
}

//send byte to device control port register
void port_byte_out(unsigned short port, unsigned char data){
	__asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

//receive 2 bytes from device control port register
unsigned short port_word_in(unsigned short port){
	unsigned short result;
	__asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
	return result;
}

//send 2 bytes to device control port register
void port_word_out(unsigned short port, unsigned short data){
	__asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}

