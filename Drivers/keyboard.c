#include "../CPU/isr.h"

void print_letter(unsigned char scancode) {
	char letter;
	int skip = 0;
	
	if(scancode == 0x02){
		letter = '1';
		goto shell;
	}else if(scancode == 0x03){
		letter = '2';
		goto shell;
	}else if(scancode == 0x04){
		letter = '3';
		goto shell;
	}else if(scancode == 0x05){
		letter = '4';
		goto shell;
	}else if(scancode == 0x06){
		letter = '5';
		goto shell;
	}else if(scancode == 0x07){
		letter = '6';
		goto shell;
	}else if(scancode == 0x08){
		letter = '7';
		goto shell;
	}else if(scancode == 0x09){
		letter = '8';
		goto shell;
	}else if(scancode == 0x0A){
		letter = '9';
		goto shell;
	}else if(scancode == 0x0B){
		letter = '0';
		goto shell;
	}else if(scancode == 0x0C){
		letter = '-';
		goto shell;
	}else if(scancode == 0x0D){
		letter = '+';
		goto shell;
	}else if(scancode == 0x0E){
		letter = '\b';
		goto shell;
	}else if(scancode == 0x0F){
		letter = '\t';
		goto shell;
	}else if(scancode == 0x10){
		letter = 'Q';
		goto shell;
	}else if(scancode == 0x11){
		letter = 'W';
		goto shell;
	}else if(scancode == 0x12){
		letter = 'E';
		goto shell;
	}else if(scancode == 0x13){
		letter = 'R';
		goto shell;
	}else if(scancode == 0x14){
		letter = 'T';
		goto shell;
	}else if(scancode == 0x15){
		letter = 'Y';
		goto shell;
	}else if(scancode == 0x16){
		letter = 'U';
		goto shell;
	}else if(scancode == 0x17){
		letter = 'I';
		goto shell;
	}else if(scancode == 0x18){
		letter = 'O';
		goto shell;
	}else if(scancode == 0x19){
		letter = 'P';
		goto shell;
	}else if(scancode == 0x1A){
		letter = '[';
		goto shell;
	}else if(scancode == 0x1B){
		letter = ']';
		goto shell;
	}else if(scancode == 0x1C){
		letter = '\n';
		goto shell;
	}else if(scancode == 0x1D){
		//lCTRL
		skip = 32;
	}else if(scancode == 0x1E){
		letter = 'A';
		goto shell;
	}else if(scancode == 0x1F){
		letter = 'S';
		goto shell;
	}else if(scancode == 0x20){
		letter = 'D';
		goto shell;
	}else if(scancode == 0x21){
		letter = 'F';
		goto shell;
	}else if(scancode == 0x22){
		letter = 'G';
		goto shell;
	}else if(scancode == 0x23){
		letter = 'H';
		goto shell;
	}else if(scancode == 0x24){
		letter = 'J';
		goto shell;
	}else if(scancode == 0x25){
		letter = 'K';
		goto shell;
	}else if(scancode == 0x26){
		letter = 'L';
		goto shell;
	}else if(scancode == 0x27){
		letter = ';';
		goto shell;
	}else if(scancode == 0x28){
		letter = '\'';
		goto shell;
	}else if(scancode == 0x29){
		letter = '`';
		goto shell;
	}else if(scancode == 0x2A){
		//LSHIFT
		skip = 11;
	}else if(scancode == 0x2B){
		letter = '\\';
		goto shell;
	}else if(scancode == 0x2C){
		letter = 'Z';
		goto shell;
	}else if(scancode == 0x2D){
		letter = 'X';
		goto shell;
	}else if(scancode == 0x2E){
		letter = 'C';
		goto shell;
	}else if(scancode == 0x2F){
		letter = 'V';
		goto shell;
	}else if(scancode == 0x30){
		letter = 'B';
		goto shell;
	}else if(scancode == 0x31){
		letter = 'N';
		goto shell;
	}else if(scancode == 0x32){
		letter = 'M';
		goto shell;
	}else if(scancode == 0x33){
		letter = ',';
		goto shell;
	}else if(scancode == 0x34){
		letter = '.';
		goto shell;
	}else if(scancode == 0x35){
		letter = '/';
		goto shell;
	}else if(scancode == 0x36){
		//RSHIFT
		skip = 30;
	}else if(scancode == 0x37){
		//keypad
		skip = 98;
	}else if(scancode == 0x38){
		//LALT
		skip = 7;
	}else if(scancode == 0x39){
		letter = ' ';
		goto shell;
	}
	
	return;
  shell:
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








