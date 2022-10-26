int strlen(unsigned char *str)
{
    int count = 0;
    if(!str) goto error;
    
    while(str[count] != '\0'){
        count++;
    }
  error:
    return count;
}

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

char hex_to_char(char hex)
{
	hex &= 0x0F;
	if(hex < 10) return hex + 48;
	else return hex + 55;
}
