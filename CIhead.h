#ifndef CIHEAD_H
#define CIHEAD_H
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<strings.h> 
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

typedef struct accountmess
{
	int userid;
	unsigned int passwd;
}AccountValue_S;

typedef enum  FuncStation
{
	SEND_ACCOUNT_ERROR = 1,   //用户名与密码错误标志位
    SEND_PSWORD,            //发送修改密码标志位
    SEND_ACCOUNT_ACK,        //发送用户密码确认信息标志位
    SEND_CORRECT,           //发送校准信息标志位
	SEND_BP,            //发送血压数据标志位
    SEND_HEARTRATE,  //发送心率数据标志位
	SEND_BLOODOXGEN,    //发送血氧数据标志位
    SEND_ALL,           //发送全部数据标志位
	SEND_BUTTON   //边界标志位
}FuncStation_E;

typedef enum  FreqStation
{
	Freqone,       //1分钟
    Freqtwo,      //15分钟
    Freqthree,      //1小时
    Freqfour,       //4小时
    Freqfive        //12小时
}FreqStation_E;

typedef struct CIValue
{
	FuncStation_E eFlag;   //功能状态信息标志位
    FreqStation_E fFlag;   //工作频率信息标志位
	AccountValue_S  userAcc;   //用户名与密码
	int SBP;        //收缩压
    int DBP;        //舒张压
    int heartRate;   //心率
    int bloodOxygen;  //血氧值
}CIValue_S;
#endif