#include "../Kernel/string.h"

extern char prompt_line[];

//input buffer scruct
struct buffer {
	char buff[51];
	int index;
	int overflow;
} input_buff;

void command_handle();
void prompt();

int input_buff_insert(char letter)
{
	//check for buffer full if not inserts letter if full increments overflow integer
	if(input_buff.index < 50){
		input_buff.buff[input_buff.index] = letter;
		input_buff.index += 1;
	}else{
		input_buff.overflow += 1;
	}
	
	return;
}

void input_buff_clear()
{
	int i = 0;
	mem_set((void *)input_buff.buff, 0, 51);
	input_buff.index = 0;
	input_buff.overflow = 0;
	
	return;
}

void shell_handle(char letter)
{
	if(letter == '\n'){   //handles command when enter is pressed
		if(input_buff.index > 0) command_handle();
		input_buff_clear();
		prompt();
		return;
	}else if(letter == '\b'){   
		if(input_buff.overflow){
			input_buff.overflow -= 1;
		}else{
			input_buff.index -= 1;
			input_buff.buff[input_buff.index] = 0;
		}
		if(input_buff.index >= 0) print_c('\b');
	}else{
		input_buff_insert(letter);
	}
	
	return;
}
			
void prompt(){
	print_s(prompt_line);
	
	return;
}			

