#ifndef __DISPOSE_H
#define __DISPOSE_H


#include "stm32f10x.h"
#include "cJSON.h"


typedef struct arry
{
  u8 Channel_Num;
	u8 Channel_State;
}st;

//extern st gpio;

void Josn_Parse_Switch(char *data);
void printJson(cJSON * data);
void Creat_Cjson(void);
char text(st *temp,char *str,u8 cnt);















#endif  /*  __DISPOSE_H  */
