#include "colors.h"

//VGA Text mode
#define VIDEO_ADDRESS 0xB8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0F

// screen controller ports
#define VGA_CTRL_REG 0x3D4
#define VGA_DATA_REG 0x3D5

//curser position value
#define VGA_OFFSET_LOW 0x0F
#define VGA_OFFSET_HIGH 0x0E

int get_cursor();
void set_cursor(int offset);
int get_screen_offset(int col, int row);
void handle_scrolling();

//get cursor position
int get_cursor()
{
	int cursor;
	port_byte_out(VGA_CTRL_REG, VGA_OFFSET_HIGH);
	cursor = port_byte_in(VGA_DATA_REG) << 8; //gets high bits shifts it left
	port_byte_out(VGA_CTRL_REG, VGA_OFFSET_LOW);
	cursor += port_byte_in(VGA_DATA_REG);
	
	return cursor * 2;
}

//sets cursor position
void set_cursor(int offset)
{
	offset /= 2;
	port_byte_out(VGA_CTRL_REG, VGA_OFFSET_HIGH);
	port_byte_out(VGA_DATA_REG, (unsigned char)(offset >> 8)); //shifts right to get high bits
	port_byte_out(VGA_CTRL_REG, VGA_OFFSET_LOW);
	port_byte_out(VGA_DATA_REG, (unsigned char)(offset & 0xFF)); //masks higher bits to get lower bits
	
	return;
}

//calculates memorey address of offset
int get_screen_offset(int col, int row)
{
	int offset = 2 * ((row * MAX_COLS) + col);
	return offset;
}

