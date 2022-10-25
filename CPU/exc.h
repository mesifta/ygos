#include "../Kernel/string.h"

extern char *except0;
extern char *except1;
extern char *except2;
extern char *except3;
extern char *except4;
extern char *except5;
extern char *except6;
extern char *except7;
extern char *except8;
extern char *except9;
extern char *except10;
extern char *except11;
extern char *except12;
extern char *except13;
extern char *except14;
extern char *except15;
extern char *except16;
extern char *except17;
extern char *except18;
extern char *except19;

char *exc_arr[20];

void init_isr_exc()
{
	exc_arr[0] = except0;
	exc_arr[1] = except1;
	exc_arr[2] = except2;
	exc_arr[3] = except3;
	exc_arr[4] = except4;
	exc_arr[5] = except5;
	exc_arr[6] = except6;
	exc_arr[7] = except7;
	exc_arr[8] = except8;
	exc_arr[9] = except9;
	exc_arr[10] = except10;
	exc_arr[11] = except11;
	exc_arr[12] = except12;
	exc_arr[13] = except13;
	exc_arr[14] = except14;
	exc_arr[15] = except15;
	exc_arr[16] = except16;
	exc_arr[17] = except17;
	exc_arr[18] = except18;
	exc_arr[19] = except19;
	
	return;
}
