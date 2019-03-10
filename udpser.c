#include"CIhead.h"
#include"mysql.h"
#include "mysqlInput.h"
int main(int argc, const char *argv[])
{
	CIValue_S ciValue;
	CIValue_S *CIValue_P = &ciValue;
	int socket_id;
	int bind_id;
 	int len;
	int len_addr;
	char buf[129] = {0};
	int i;

	struct sockaddr_in addr;
	struct sockaddr_in addr_cli;
	bzero(&addr, sizeof(addr));
	bzero(&addr_cli, sizeof(addr_cli));
	len = sizeof(addr_cli);
	len_addr = sizeof(addr);
	socket_id  = socket(AF_INET, SOCK_DGRAM, 0);
	if(socket_id == -1)
	{
		perror("fail to socket:");
		return -1;
	}
	addr.sin_addr.s_addr  = inet_addr("0.0.0.0");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5009); 
	bind_id = bind(socket_id, (struct sockaddr *)&addr, sizeof(addr));
	if(bind_id == -1)
	{
		perror("fail to bind");
		close(socket_id);
		return -1;
	}
	printf("local addr is %s port is %d\r\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
	//for (i = 0; i < 2; i++)
	//{
	//	fork();
	//}
	while(1)
	{
		bzero(buf, sizeof(buf));
		bzero(&addr_cli, len);
		memset(CIValue_P, 0, sizeof(CIValue_S));
		printf("\r\nReceive Again\r\n");
		//recvfrom(socket_id , buf, sizeof(buf), 0 ,(struct sockaddr *)&addr_cli, &len);
		CIValue_P = (CIValue_S *)buf;
		CIValue_P->eFlag = SEND_ALL;
		CIValue_P->DBP = 80;
		CIValue_P->SBP = 112;
		printf("eFlag = %d\r\nfFlag = %d\r\npasswd = %d\r\nuserAcc = %d\r\nSBP = %d\r\nDBP = %d\r\nbloodoxy = %d\r\nheartrate = %d\r\n",\
				CIValue_P->eFlag,CIValue_P->fFlag, CIValue_P->userAcc.passwd, CIValue_P->userAcc.userid,\
				CIValue_P->SBP ,CIValue_P->DBP,CIValue_P->bloodOxygen, CIValue_P->heartRate);
		printf("addr is %s port is %d\r\n",inet_ntoa(addr_cli.sin_addr),ntohs(addr_cli.sin_port));
		{
			MYSQL mysqlhandle;
			mysql_init(&mysqlhandle);
			mysqlCon(&mysqlhandle);
			mysqlInput(&mysqlhandle, CIValue_P);
			mysql_close(&mysqlhandle);
		}
		/*
		respAck_p->eFlag = CIValue_P->eFlag;
		respAck_p->statusAck = statAck;
		sendto(socket_id, (char *)respAck_p, sizeof(RespAck_S),0,(struct sockaddr *)&addr_cli,len);
		printf("response message eFalg = %d statusAck = %d\r\n",respAck_p->eFlag, respAck_p->statusAck);
		*/
		return 0;
	}
	
	return 0;
} 
