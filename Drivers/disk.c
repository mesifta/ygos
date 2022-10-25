#include "../Util/stdint.h"
#include "../CPU/isr.h"
#include "../Kernel/string.h"

#define IRQ14 46

extern uint16_t *disk_buff_ptr;
uint16_t *buff_ptr;

int check_disk_main()
{
	port_byte_out(0x1F6, 0xA0);  //selects drive master(0xA0) at primary bus(0x1F6)
	port_byte_out(0x1F2, 0x0);   //sets 0 the sector count port
	port_byte_out(0x1F3, 0x0);   //sets 0 the LBAlo port
	port_byte_out(0x1F4, 0x0);   //sets 0 the LBAmid port
	port_byte_out(0x1F5, 0x0);   //sets 0 the LBAhi port
	
	port_byte_out(0x1F7, 0xEC);  //sends identify command(0xEC) to the status port(0x1F7)
	
	char check = port_byte_in(0xF7);  //checks status 0 = no drive
	
	if(check){
		return 1;
	}
	return 0;
}

void read_sectors_main(uint16_t *ptr, uint32_t sect_num, uint8_t num_sects)
{
	buff_ptr = ptr;
	port_byte_out(0x1F6, 0xE0);    //drive
    while((port_byte_in(0x3F6) & 0xb10000001) == 0x80){
		continue;
	}
	
	port_byte_out(0x1F2, num_sects);       //num sects
	port_byte_out(0x1F3, (uint8_t)sect_num);
	port_byte_out(0x1F4, (uint8_t)(sect_num >> 8));
	port_byte_out(0x1F5, (uint8_t)(sect_num >> 16));
	
	port_byte_out(0x1F7, 0x20);    //read command
	
	return;
}

void write_sectors_main(uint16_t *ptr, uint32_t sect_num, uint8_t num_sects)
{
	port_byte_out(0x1F6, 0xE0);
    port_byte_out(0x1F1, 0x00);
	port_byte_out(0x1F2, num_sects);       //num sects
	port_byte_out(0x1F3, (uint8_t)(sect_num));
	port_byte_out(0x1F4, (uint8_t)(sect_num >> 8));
	port_byte_out(0x1F5, (uint8_t)(sect_num >> 16));
	
	port_byte_out(0x1F7, 0x30);
	
	while((port_byte_in(0x3F6) & 0xb10000000) == 128){
		continue;
	}
	uint16_t word;
	int i = 0;
	for(i = 0; i < 256 * num_sects; i++){
		word = ptr[i] >> 8;
		word += ptr[i] << 8;
	    port_word_out(0x1F0, word);
		port_byte_out(0x1F7, 0xE7);   
	}
	
	return;
}

void disk_read(registers_t *r)
{
	uint16_t word;
	int i = 0;
	for(i = 0; i < 256; i++){
		word = port_word_in(0x1F0);
		buff_ptr[i] = word >> 8;
		buff_ptr[i] += word << 8;
	}
	buff_ptr += 512;
}

void dma_int(registers_t *r){
	port_byte_out(0x00, 0x00);
}
	
void init_disk(){
	register_interrupt_handler(IRQ14, disk_read);
}

