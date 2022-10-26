#ifndef _STRING_H
#define _STRING_H

int strlen(unsigned char *str);
int strcmp(char *str1, char *str2);
char hex_to_char(char hex);

#define print_c(M) print_char(M, -1, -1, 0, 0)
#define print_s(M) print(M, -1, -1, 0, 0)
#define print_l() print_c('\n')

#endif
