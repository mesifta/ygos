#include "../Drivers/colors.h"
#include "string.h"
#include "../Util/stdint.h"

extern char greet[];
extern uint16_t *disk_buff_ptr;

void start(){
	isr_install();
	init_isr_exc();
	asm volatile("sti");
	init_keyboard();
	init_heap();
	init_disk();
	
	print_s(greet);
	prompt();
    
	return;
}

