#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include "getTime.h" 
void getDate(char *cGetDate)
{
	if (NULL == cGetDate)
	{
		printf("please allocate space for cGetDate\r\n"); 
		return ;
	}
	struct tm *real_localtime;
	time_t real_time;
	real_time = time(NULL);
	real_localtime = localtime(&real_time);
	sprintf(cGetDate,"%d-%d-%d",real_localtime->tm_year + DEFAULT_YEAR,\
			real_localtime->tm_mon + DEFAULT_MON, real_localtime->tm_mday);
	return ;
}
void getTime(char *cGetTime)
{
	if (NULL == cGetTime)
	{
		printf("please allocate sapce for cGetTime\r\n");
		return ;
	}
	struct tm *real_localtime;
	time_t real_time;
	real_time = time(NULL);
	printf("%d\r\n",real_time);
	real_localtime = localtime(&real_time);
	printf("%d\r\n",real_localtime->tm_isdst);
	sprintf(cGetTime,"%d:%d:%d",real_localtime->tm_hour, real_localtime->tm_min,\
			real_localtime->tm_sec);
	return ;
}
int main(int argc, const char *argv[])
{
	char *time = malloc(129);
	getTime(time);
	printf("%s\r\n",time);
	return 0;
}
