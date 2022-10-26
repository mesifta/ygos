#define err_handle(A) if(!(A)){goto error;}

void memcpy(void *dest, void *scr, int count)
{
	err_handle(dest != scr);
    int i = 0;
    for(i = 0; i < count; i++){
        *((char *)dest + i) = *((char *)scr + i);
    }
  error:
    return;
}

void memset(void *mem, char val, int num)
{
	err_handle(mem);
	int i = 0;
	for(i = 0; i < num; i++){
		*((char *)mem + i) = val;
	}
  error:
    return;
}

void sleep(int sec)
{
    int i = 0, j = 0;
    for(i = 0; i < sec; i++){
        while(j < 100000000){
            j++;
        }
        j = 0;
    }
}

void int_to_string(int num, char str[])
{
    err_handle(str);
    int i = 0, j = 0;
    char buff[40];
    
    while(num / 10 != 0){
        buff[i++] = (num % 10) + 48; 
        num /= 10;
    }    
    buff[i] = num + 48;
    for(j = 0; i >= 0; j++){
        str[j] = buff[i--];
    } 
  error:
    return;  
}

int hex_char_to_num(char letter)
{
	if(letter > 47 && letter < 58) return letter - 48;
	else return letter - 55;
}
