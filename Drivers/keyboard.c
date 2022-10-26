#include "../CPU/isr.h"

void print_letter(unsigned char scancode) {
	char letter = 0;
	
	if(scancode == 0x02){
		letter = '1';
	}else if(scancode == 0x03){
		letter = '2';
	}else if(scancode == 0x04){
		letter = '3';
	}else if(scancode == 0x05){
		letter = '4';
	}else if(scancode == 0x06){
		letter = '5';
	}else if(scancode == 0x07){
		letter = '6';
	}else if(scancode == 0x08){
		letter = '7';
	}else if(scancode == 0x09){
		letter = '8';
	}else if(scancode == 0x0A){
		letter = '9';
	}else if(scancode == 0x0B){
		letter = '0';
	}else if(scancode == 0x0C){
		letter = '-';
	}else if(scancode == 0x0D){
		letter = '+';
	}else if(scancode == 0x0E){
		letter = '\b';
	}else if(scancode == 0x0F){
		letter = '\t';
	}else if(scancode == 0x10){
		letter = 'Q';
	}else if(scancode == 0x11){
		letter = 'W';
	}else if(scancode == 0x12){
		letter = 'E';
	}else if(scancode == 0x13){
		letter = 'R';
	}else if(scancode == 0x14){
		letter = 'T';
	}else if(scancode == 0x15){
		letter = 'Y';
	}else if(scancode == 0x16){
		letter = 'U';
	}else if(scancode == 0x17){
		letter = 'I';
	}else if(scancode == 0x18){
		letter = 'O';
	}else if(scancode == 0x19){
		letter = 'P';
	}else if(scancode == 0x1A){
		letter = '[';
	}else if(scancode == 0x1B){
		letter = ']';
	}else if(scancode == 0x1C){
		letter = '\n';
	}else if(scancode == 0x1D){
		//lCTRL
		return;
	}else if(scancode == 0x1E){
		letter = 'A';
	}else if(scancode == 0x1F){
		letter = 'S';
	}else if(scancode == 0x20){
		letter = 'D';
	}else if(scancode == 0x21){
		letter = 'F';
	}else if(scancode == 0x22){
		letter = 'G';
	}else if(scancode == 0x23){
		letter = 'H';
	}else if(scancode == 0x24){
		letter = 'J';
	}else if(scancode == 0x25){
		letter = 'K';
	}else if(scancode == 0x26){
		letter = 'L';
	}else if(scancode == 0x27){
		letter = ';';
	}else if(scancode == 0x28){
		letter = '\'';
	}else if(scancode == 0x29){
		letter = '`';
	}else if(scancode == 0x2A){
		//LSHIFT
		return;
	}else if(scancode == 0x2B){
		letter = '\\';
	}else if(scancode == 0x2C){
		letter = 'Z';
	}else if(scancode == 0x2D){
		letter = 'X';
	}else if(scancode == 0x2E){
		letter = 'C';
	}else if(scancode == 0x2F){
		letter = 'V';
	}else if(scancode == 0x30){
		letter = 'B';
	}else if(scancode == 0x31){
		letter = 'N';
	}else if(scancode == 0x32){
		letter = 'M';
	}else if(scancode == 0x33){
		letter = ',';
	}else if(scancode == 0x34){
		letter = '.';
	}else if(scancode == 0x35){
		letter = '/';
	}else if(scancode == 0x36){
		//RSHIFT
		return;
	}else if(scancode == 0x37){
		//keypad
		return;
	}else if(scancode == 0x38){
		//LALT
		return;
	}else if(scancode == 0x39){
		letter = ' ';
	}
    
	if(letter == 0) return;
    if(letter != '\b') print_char(letter, -1, -1, 0, 0);
    shell_handle(letter);
	return;
}

void keyboard_callback(registers_t *reg)
{
	unsigned char scancode = port_byte_in(0x60);
	print_letter(scancode);
	
	return;
}

void init_keyboard(){
	register_interrupt_handler(IRQ1, keyboard_callback);
	
	return;
}








