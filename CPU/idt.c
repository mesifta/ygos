#include "idt.h"

idt_gate_t IDT[256];
idt_register_t IDT_reg;

void set_idt_gate(int num, unsigned short handler)
{
	IDT[num].low_offset = low_16(handler);
	IDT[num].selector = 0x08;
	IDT[num].always0 = 0;
	IDT[num].flags = 0x8E;
	IDT[num].high_offset = high_16(handler);
}

void load_idt()
{
	IDT_reg.base = (unsigned short)&IDT;
	IDT_reg.limit = 256 * sizeof(idt_gate_t) - 1;
	asm volatile("lidt (%0)" : : "r" (&IDT_reg));
}
