#ifndef __LIST_H
#define __LIST_H

#include "stm32f10x.h"


typedef struct Data
{
  uint8_t addr;
	uint8_t value;
}Data;

typedef struct NODE {    
    struct Data data;
    struct NODE *Next;    
}Node;

struct NODE *NodeCreat(void);

uint8_t Insert_Node(Data* Msg);

uint8_t Delete_Node(Node* Del);






























#endif /* __LIST_H */















