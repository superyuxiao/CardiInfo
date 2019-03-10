#ifndef __MYSQLINPUT_H
#define __MYSQLINPUT_H
#include "CIhead.h"
#define PASSWORD_LENGTH 6
int mysqlInput(MYSQL *mysqlHandle, CIValue_S *CIValue_P);
void mysqlCon(MYSQL *mysqlHandle);
//StatAck_E mysql_input_sel(MYSQL *mysqlHandle, HealthValue_S *healthValue_p);
//StatAck_E mysqlQuery(MYSQL *mysqlHandle, HealthValue_S *healthValue_p);
#endif
