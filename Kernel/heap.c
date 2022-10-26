#include "heap.h"
#include "../Include/string.h"

void Element_create(void *ptr, uint32_t size, bool in_use)
{
	Element *list = Heap.start;
	list[Heap.num_ele].size = size;
	list[Heap.num_ele].in_use = in_use;
	list[Heap.num_ele].address = ptr;
	Heap.num_ele++;
}

void *malloc(uint32_t size)
{
	if(size < 10) size = 10;
	
	int best = 0, i;
	Element *list = Heap.start;
	for(i = 0; i < Heap.num_ele; i++){
		
		if(list[i].in_use == false){
			if(list[i].size >= size){
				if(best){
					if(list[best - 1].size > list[i].size) best = i + 1;	
				}else{
					best = i + 1;
				}
			}
		}
	}
	if(!best){
		return NULL;
	}
	best -= 1;
	if(list[best].size > (size + 9)){
		Element_create(list[best].address + size, (list[best].size - size), false);
		Heap.num_ele++;
		list[best].size = size;
	}
	list[best].in_use = true;
	Heap.bytes_free -= size;
	return list[best].address;
}
	
void *calloc(uint32_t size)
{
	void *ptr = malloc(size);
	memset(ptr, 0, size);
	return ptr;
}
	
int free(void *ptr)
{
	int i = 0;
	Element *list = Heap.start;
	for(i = 0; i < Heap.num_ele; i++){
		if(list[i].address == ptr){
			list[i].in_use = false;
			Heap.bytes_free += list[i].size;
			return 0;
		}
	}
	return 1;
}

void init_heap()
{
	Heap.start = (Element*)LIST_START;
	Heap.num_ele = 0;
	Heap.bytes_free = 0x100000;
	
	Element_create((void *)HEAP_START, 0x100000, false);
}
