#ifndef __LIST_H
#define __LIST_H

#include "stm32f10x.h"


//#define IO       0
//#define Realy    1
//#define Unpress  0  
//#define Press    1
//#define Close    0
//#define Open     1



typedef struct Data
{
  uint8_t addr;
	char type[10];
	uint8_t channel;
	char data[10];
}Data;

typedef struct NODE {    
    struct Data data;
    struct NODE *Next;    
}Node;


extern Node *Head;

struct NODE *NodeCreat(void);

uint8_t Insert_Node(Data* Msg);

void Delete_Node(uint8_t address);

void Compare_Node(Data *Com);

uint8_t Insert_data(void);

void Print_Node(void);
























#endif /* __LIST_H */















