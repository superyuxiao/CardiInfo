#include<stdio.h>
#include<time.h>
#include"timeStamp.h"
int getTime(void)
{
	time_t time_real;
	time_real = time(NULL);
	return time_real;
}

