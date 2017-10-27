#include "List.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Node *Head;


struct NODE *NodeCreat(void)
{
  Head=(Node *)malloc(sizeof(Node));
	if(Head == NULL)
	{
   return FALSE;
  }
  Head->data.addr=0;
  Head->data.value=0;
	Head->Next=NULL;
// Лђеп
//	memset(Head,0,sizeof(Node));
//	Head->Next=NULL;
	return Head;
}

uint8_t Insert_Node(Data* Msg)
{
  Node *Cur=Head->Next;
	Node *Pre=Head;
	Node *Temp;
	
	Temp=(Node *)malloc(sizeof(Node));
	if(Temp == NULL)
	{
   return FALSE;
  }
	Temp->data.addr=Msg->addr;
	Temp->data.value=Msg->value;
	
	while(Cur)
	{
   Pre=Cur;
	 Cur=Cur->Next;	
  }	
	
	Temp->Next=Pre->Next;
	Pre->Next=Temp;
	
	return TRUE;
}

uint8_t Delete_Node(Node* Del)
{
  Node *Cur=Head->Next;
	Node *Pre=Head;
	
	while(Cur)
	{
    if(Cur->data.addr ==Del->data.addr)
    {
			Pre->Next=Del->Next;
			Cur=Del->Next;
      free(Del);			
    }
		Pre=Cur;
		Cur=Cur->Next;
 }
}















