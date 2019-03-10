#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "error.h"
#include "mysql.h"
#include "mysqlInput.h"
#include "CIhead.h"
#include "timeStamp.h"
#include "md5.h"
#include<string.h>
/*
 *function mysqlCon Aimed to connected to localhost service 
 *parameter input: MYSQL handle
 * no return value
 * */
void mysqlCon(MYSQL *mysqlHandle)
{
	/* connected to database MKB */
	mysqlHandle = mysql_real_connect(mysqlHandle, "127.0.0.1",\
				"root","root123456","MKB",0,NULL,0);

	if (!mysqlHandle)
	{
		/* connected to database MKB three times again */
		int iIndex = 0;
		for (iIndex = 0; iIndex <= 3; iIndex++)
		{
			mysqlHandle = mysql_real_connect(mysqlHandle, "127.0.0.1", \
						"root", "root123456","MKB", 0, NULL, 0);
			if ((NULL != mysqlHandle) && (3 != iIndex))
				break;
		}
	}	
	return ;
}

/* 
 *function mysqlInput aimed to insert data to certain table
 *parameter input:MYSQL handle and 
 *retrun vlaues:0 means success -1 means failed
 * */
int mysqlInput(MYSQL *mysqlHandle, CIValue_S *CIValue_P)
{
	char * cmysqlBuffer = malloc(128);
	int iflag = 0;
	
	switch (CIValue_P->eFlag)
	{
		case SEND_BP:
			sprintf(cmysqlBuffer, "insert into DBP(userid, DBP,time) values(%d,%d,%d)",\
					CIValue_P->userAcc.userid, CIValue_P->DBP, getTime());
			printf("%s\r\n",cmysqlBuffer);
			iflag = mysql_real_query(mysqlHandle, cmysqlBuffer, strlen(cmysqlBuffer));
			if (iflag)
			{
				printf("failed to excute mysql_real_query\r\n");
				mysql_close(mysqlHandle);
				return -1;
			}
			sprintf(cmysqlBuffer, "insert into SBP(userid, SBP,time) values(%d,%d,%d)",\
					CIValue_P->userAcc.userid, CIValue_P->SBP, getTime());
			printf("%s\r\n",cmysqlBuffer);	
			iflag = mysql_real_query(mysqlHandle, cmysqlBuffer, strlen(cmysqlBuffer));
			if (iflag)
			{
				printf("failed to excute mysql_real_query\r\n");
				mysql_close(mysqlHandle);
				return -1;
			}	
			break;
		case SEND_BLOODOXGEN:
			sprintf(cmysqlBuffer, "insert into bloodoxygen(userid, bloodoxygen,time) values(%d, %d, %d)", \
					CIValue_P->userAcc.userid, CIValue_P->bloodOxygen, getTime());	
			printf("%s\r\n",cmysqlBuffer);
			iflag = mysql_real_query(mysqlHandle, cmysqlBuffer, strlen(cmysqlBuffer));
			if (iflag)
			{
				printf("failed to excute mysql_real_query\r\n");
				mysql_close(mysqlHandle);
				return -1;
			}
			break;
		case SEND_HEARTRATE:	
			sprintf(cmysqlBuffer, "insert into heartrate(userid, heartrate, time) values(%d, %d, %d)", \
					CIValue_P->userAcc.userid, CIValue_P->heartRate, getTime());
			printf("%s\r\n",cmysqlBuffer);
			iflag = mysql_real_query(mysqlHandle, cmysqlBuffer, strlen(cmysqlBuffer));
			if (iflag)
			{
				printf("failed to excute mysql_real_query\r\n");
				mysql_close(mysqlHandle);
				return -1;
			}
			break;
		case SEND_ALL:
			sprintf(cmysqlBuffer, "insert into DBP(userid, DBP,time) values(%d,%d,%d)",\
					CIValue_P->userAcc.userid, CIValue_P->DBP, getTime());
			printf("%s\r\n",cmysqlBuffer);
			iflag = mysql_real_query(mysqlHandle, cmysqlBuffer, strlen(cmysqlBuffer));
			if (iflag)
			{
				printf("failed to excute mysql_real_query\r\n");
				mysql_close(mysqlHandle);
				return -1;
			}
			sprintf(cmysqlBuffer, "insert into SBP(userid, SBP,time) values(%d,%d,%d)",\
					CIValue_P->userAcc.userid, CIValue_P->SBP, getTime());
			printf("%s\r\n",cmysqlBuffer);
			iflag = mysql_real_query(mysqlHandle, cmysqlBuffer, strlen(cmysqlBuffer));
			if (iflag)
			{
				printf("failed to excute mysql_real_query\r\n");
				mysql_close(mysqlHandle);
				return -1;
			}
			sprintf(cmysqlBuffer, "insert into heartrate(userid, heartrate, time) values(%d, %d, %d)", \
					CIValue_P->userAcc.userid, CIValue_P->heartRate, getTime());
			printf("%s\r\n",cmysqlBuffer);
			iflag = mysql_real_query(mysqlHandle, cmysqlBuffer, strlen(cmysqlBuffer));
			if (iflag)
			{
				printf("failed to excute mysql_real_query\r\n");
				mysql_close(mysqlHandle);
				return -1;
			}
			sprintf(cmysqlBuffer, "insert into bloodoxygen(userid, bloodoxygen,time) values(%d, %d, %d)", \
					CIValue_P->userAcc.userid, CIValue_P->bloodOxygen, getTime());
			printf("%s\r\n",cmysqlBuffer);
			iflag = mysql_real_query(mysqlHandle, cmysqlBuffer, strlen(cmysqlBuffer));
			if (iflag)
			{
				printf("failed to excute mysql_real_query\r\n");
				mysql_close(mysqlHandle);
				return -1;
			}
			break;
		default:
			printf("eFlag = %d\r\n",CIValue_P->eFlag);
			return -1;
	}
	free(cmysqlBuffer);
	return 0;
}

/* 
 *function mysql_input_sel Aimed to chose a certain exeutive command
 *parameter input:MYSQL handle and CIValue_P
 *return vlaues;enum StatAck_E 
 * */




