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
	SEND_ACCOUNT_ERROR = 1,   //�û�������������־λ
    SEND_PSWORD,            //�����޸������־λ
    SEND_ACCOUNT_ACK,        //�����û�����ȷ����Ϣ��־λ
    SEND_CORRECT,           //����У׼��Ϣ��־λ
	SEND_BP,            //����Ѫѹ���ݱ�־λ
    SEND_HEARTRATE,  //�����������ݱ�־λ
	SEND_BLOODOXGEN,    //����Ѫ�����ݱ�־λ
    SEND_ALL,           //����ȫ�����ݱ�־λ
	SEND_BUTTON   //�߽��־λ
}FuncStation_E;

typedef enum  FreqStation
{
	Freqone,       //1����
    Freqtwo,      //15����
    Freqthree,      //1Сʱ
    Freqfour,       //4Сʱ
    Freqfive        //12Сʱ
}FreqStation_E;

typedef struct CIValue
{
	FuncStation_E eFlag;   //����״̬��Ϣ��־λ
    FreqStation_E fFlag;   //����Ƶ����Ϣ��־λ
	AccountValue_S  userAcc;   //�û���������
	int SBP;        //����ѹ
    int DBP;        //����ѹ
    int heartRate;   //����
    int bloodOxygen;  //Ѫ��ֵ
}CIValue_S;
#endif