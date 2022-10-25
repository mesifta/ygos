#ifndef _HEAP_H
#define _HEAP_H

#include "../Util/stdint.h"
#include "../Util/stdbool.h"

#define LIST_START 0x900000
#define HEAP_START 0xA00000
#define HEAP_END   0xF00000

typedef struct Element {
	uint32_t size;
	bool in_use;
	void *address;
} Element;

struct {
	Element *start;
	uint32_t num_ele;
	uint32_t bytes_free;
} Heap;

#endif
