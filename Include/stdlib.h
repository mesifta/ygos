#ifndef _STDLIB_H
#define _STDLIB_H

void memcpy(void *dest, void *scr, int count);
void memset(void *mem, char val, int num);
void sleep(int sec);
void int_to_string(int num, char str[]);
int hex_char_to_num(char letter);

#endif
