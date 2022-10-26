#include "shell.h"

//externel string vars defined in "Kernel/str.asm"
extern char cmd_ECHO[];
extern char cmd_COLOR[];
extern char cmd_NONE[];
extern char cmd_CLEAR[];
extern char cmd_SHUTDOWN[];

extern char shut[];

extern void switch_16();
extern void shutdown();


void command_handle()
{
	char *command = input_buff.buff; //gets command from input buffer
	int num = input_buff.index;
	int index = 0, i = 0;
	
	//check for space between command and parameters
	for(i = 0; i < num; i++){
		if(*command != ' ') break;
		command++;
	}
	//check for first word(=command)
	for(i = 0; i < num; i++, index++){
		if(command[i] == ' ' || command[i] == 0){
			command[i] = 0;
			break;
		}
	}
	
	if(strcmp(command, cmd_ECHO)){     //prints string to screen eg. ECHO hello world
		print_s(command + index + 1);
		print_l();
	}else if(strcmp(command, cmd_COLOR)){  //changes color eg. COLOR A4 A = bg 4 = fg
		char bg = hex_char_to_num(*(command + index + 1));
		char fg = hex_char_to_num(*(command + index + 2));
		set_screen_color(bg, fg);
	}else if(strcmp(command, cmd_CLEAR)){  //clears screen eg. CLEAR
		clear_screen();
	}else if(strcmp(command, cmd_SHUTDOWN)){
		clear_screen();
		memset((void *)0xB8000, 0, 160);
		set_screen_color(0, 0);
		print(shut, 32, 13, 0, 0);
		sleep(2);
		switch_16();
		shutdown();
		//port_word_out(0x604, 0x2000);
		//port_word_out(0xB004, 0x2000);
	}else{
		print_s(cmd_NONE);  //other
		print_l();
	}
	
	return;
}
