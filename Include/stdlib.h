#ifndef _STDLIB_H
#define _STDLIB_H

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

void memset(void *mem, char value, int num)
{
	int i = 0;
	for(i = 0; i < num; i++){
		*((char *)mem + i) = value;
	}
  error:
    return;
}

#endif
