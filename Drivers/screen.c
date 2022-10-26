#include "screen.h"
#include "../Include/stdlib.h"

//prints single char to screen
void print_char(char letter, int col, int row, unsigned char bg, unsigned char fg)
{
	unsigned char color;
	unsigned char *cursor = (unsigned char *)VIDEO_ADDRESS;
	
	if((!bg && !fg) || (bg == fg)){
		color = *(cursor +1);
	}else{
		color = (bg << 4) + (fg & 0x0f);
	}
	
	if(col >= 0 || row >= 0){
		cursor += get_screen_offset(col, row);
	}else{
		if((get_cursor() / 2) > ((MAX_COLS) * (MAX_ROWS)) - 1) handle_scrolling();
		cursor += get_cursor();
	}
	if(letter == '\n'){    
		if((get_cursor() / 2) >= ((MAX_COLS) * (MAX_ROWS - 1))){
			handle_scrolling();    //if last line handle scrolling
			return;
		}else{
			int rows = (int)(cursor - VIDEO_ADDRESS) / (2 * MAX_COLS);
			cursor = (char *)get_screen_offset(79, rows) + VIDEO_ADDRESS;
			letter = 0;
		}	
	}
	if(letter == '\t'){
		cursor += 6;
		letter = 0;
	}
	if(letter == '\b'){
		cursor -= 2;
		if((int)cursor < VIDEO_ADDRESS ) goto skip;
		letter = 0;
		*cursor = letter;
		*(cursor + 1) = color;
		cursor -= 2;
		goto skip;
	}
	*cursor = letter;         //first byte for letter
	*(cursor + 1) = color;    //second byte for color 0-3 bg 4-7 fg  
  skip:
	set_cursor((int)(cursor - VIDEO_ADDRESS) + 2);   //increments cursor
	
	return;
}

void print(char *str, int col, int row, unsigned char bg, unsigned char fg)
{
	if(!str) return;
	if(col >= 0 || row >= 0){
		set_cursor(get_screen_offset(col, row));
		col = - 1; row = - 1;
	}
	int i = 0;
	while(str[i]){      //loops till 0 byte
		print_char(str[i++], col, row, bg, fg);
	}
	return;
}
	
void clear_screen()
{
	char *byte = (char *)(VIDEO_ADDRESS + 160); //clears screen from second row
	int i = 0;
	for(i = 0; i < (MAX_ROWS -1) * MAX_COLS * 2; i += 2){
		byte[i] = 0;
	}
	set_cursor(get_screen_offset(0, 1)); //sets curser to second row
	return;
}

void set_screen_color(char bg, char fg)
{
	char color;
	if((!bg && !fg) || (bg == fg) || fg > 0xF || bg > 0x0F){
		color = WHITE_ON_BLACK;
	}else{
		color = (bg << 4) + (fg & 0x0f);  //shifts bg 4 bits to the right and masks fg first 4 bits
	}
	char *byte = (char *)VIDEO_ADDRESS;
	int i = 0;
	//sets color value in all 80x25 screen cells
	for(i = 1; i < MAX_ROWS * MAX_COLS * 2 + 1; i += 2){
		byte[i] = color;
	}
	
	return;
}

void set_cursor_size(char top, char bottom)
{
	port_byte_out(0x3D4, 0x0A);   //selects cursor top start register
	port_byte_out(0x3D5, (port_byte_in(0x3D5) & 0xC0) | (top & 0x0F));
	port_byte_out(0x3D4, 0x0B);   //selects cursor bottom end register
	port_byte_out(0x3D5, (port_byte_in(0x3D5) & 0xE0) | (bottom & 0x0F));
	
	return;
}

void handle_scrolling()
{
	int i = 0;
	//copies screen contents one line up from line 2
	for(i = 1; i < MAX_ROWS -1; i++){
		memcpy((void *)(get_screen_offset(0, i) + VIDEO_ADDRESS),
			   (void *)(get_screen_offset(0, i + 1) + VIDEO_ADDRESS), 160);
	}
	//clears bottom line
	unsigned int *offset = (unsigned int *)VIDEO_ADDRESS + get_screen_offset(0, 24);
	for(i = 0; i < 160; i += 2){
		*((char *)offset + i) = 0;
	}
    //sets cursor to bottom line
	set_cursor(get_screen_offset(0, 24));
	
	return;
}
