#ifndef _STRING_H
#define _STRING_H

#define print_c(M) print_char(M, -1, -1, 0, 0)
#define print_s(M) print(M, -1, -1, 0, 0)
#define print_l() print_c('\n')

int strcmp(char *str1, char *str2)
{
    int i = 0;
	  for(i = 0; ; i++){
		    if(str1[i] == 0 && str2[i] == 0) return 1;
		    if(str1[i] == str2[i]) continue;
		    if(str1[i] != str2[i]) return 0;
		    if(str1[i] == 0 || str2[i] == 0) return 0;
	  }
}

#endif
