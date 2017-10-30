#include "List.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bsp_led.h"   
#include "utility.h"

Node *Head;

uint8_t repeat=0;

struct NODE *NodeCreat(void)
{
  Head=(Node *)malloc(sizeof(Node));
	if(Head == NULL)
	{
	 printf("false1");
   return FALSE;
  }
  Head->data.addr=0;
	memset(Head->data.type,0,sizeof(Head->data.type));
	Head->data.channel=0;
	memset(Head->data.data,0,sizeof(Head->data.data));
	Head->Next=NULL;
// 或者
//	memset(Head,0,sizeof(Node));
	
	
//	Head->Next=NULL;
	return Head;
}

uint8_t Insert_Node(Data* Msg)
{
  Node *Insert_Cur=Head->Next;
	Node *Insert_Pre=Head;
	Node *Temp;
	
	Temp=(Node *)malloc(sizeof(Node));
	if(Temp == NULL)
	{
	 printf("false2");
   return FALSE;
  }
	
	Temp->data.addr=Msg->addr;
	strcpy(Temp->data.type,Msg->type);
	Temp->data.channel=Msg->channel;
	strcpy(Temp->data.data,Msg->data);
	
	while(Insert_Cur)
	{
		if(Temp->data.addr==Insert_Cur->data.addr)
		{
			strcmp(Temp->data.type,Insert_Cur->data.type);
      if(!(strcmp(Temp->data.type,Insert_Cur->data.type)))
			{
        if(Temp->data.channel==Insert_Cur->data.channel)
				{
					printf("repeat\r\n");
          return 0;					
         }
      }
    }
   Insert_Pre=Insert_Cur;
	 Insert_Cur=Insert_Cur->Next;	
  }	
		Temp->Next=Insert_Pre->Next;
		Insert_Pre->Next=Temp;

	return TRUE;
}

void Delete_Node(uint8_t address)
{
  Node *Cur=Head->Next;
	Node *Pre=Head;
	
	while(Cur)
	{
    if(Cur->data.addr ==address)
    {
			Pre->Next=Cur->Next;
      free(Cur);
      Cur=Pre->Next;			
    }
		else
		{
			Pre=Cur;
			Cur=Cur->Next;
		}
 }
 	Print_Node();
}

//void Delete_Node(uint8_t address)
//{
//  Node *Cur=Head->Next;
//	Node *Pre=Head;
//	
//	while(Cur)
//	{
//    if(Cur->data.addr ==address)
//    {
//			Pre->Next=Cur->Next;
//      free(Cur);
//      Cur=Pre;			
//    }
//			Pre=Cur;
//			Cur=Cur->Next;

// }
// 	Print_Node();
// }

//void Compare_Node(Data *Com)
//{
//  Node *Cpa_Cur=Head->Next;
//	Node *Cpa_Pre=Head;
//  
//	while(Cpa_Cur)
//	{
//    if(Cpa_Cur->data.addr==Com->addr)
//		{
//      if(Cpa_Cur->data.type==Com->type)
//			{
//        if(Cpa_Cur->data.channel==Com->channel)
//					//已找到，更新数据状态
//				break;	
//      }				
//    }	
//	  Cpa_Pre=Cpa_Cur;
//		Cpa_Cur=Cpa_Cur->Next;	
//  }
////未找到，运行插入节点函数，发送通知
//	Insert_Node(Com);
//}

void Print_Node(void)
{
	Node *Pri_Cur=Head->Next;
	
	while(Pri_Cur)
	{
		printf(" addr:%d,type:%s,chanel:%d,data:%s\r\n",Pri_Cur->data.addr,Pri_Cur->data.type,Pri_Cur->data.channel,Pri_Cur->data.data);		
		Pri_Cur=Pri_Cur->Next;		
 }
}


uint8_t Insert_data(void)
{	

	
  Data *Insert;
	
	Insert=(Data *)malloc(sizeof(Node));

	if(Insert==NULL)
	{
   printf("false0");	
	 return FALSE;
  }

	Insert->addr=0x01;
	strcpy(Insert->type,"IO");
	Insert->channel=0x01;
  strcpy(Insert->data,"unpress");
	Insert_Node(Insert);
	
	Insert->addr=0x02;
	strcpy(Insert->type,"Relay");
	Insert->channel=0x01;
	strcpy(Insert->data,"open");
	Insert_Node(Insert);

	

	Insert->addr=0x02;
	strcpy(Insert->type,"IO");
	Insert->channel=0x01;
	strcpy(Insert->data,"press");
	Insert_Node(Insert);

//	Insert=(Data *)malloc(sizeof(Node));
//	Insert->addr=0x02;
//	strcpy(Insert->type,"Relay");
//	Insert->channel=0x03;
//	 strcpy(Insert->data,"close");
//	Insert_Node(Insert);

	Insert=(Data *)malloc(sizeof(Node));
	Insert->addr=0x02;
	strcpy(Insert->type,"Relay");
	Insert->channel=0x04;
	strcpy(Insert->data,"close");
	Insert_Node(Insert);

	Insert=(Data *)malloc(sizeof(Node));
	Insert->addr=0x01;
	strcpy(Insert->type,"Relay");
	Insert->channel=0x06;
	strcpy(Insert->data,"open");
	Insert_Node(Insert);


	Insert->addr=0x04;
	strcpy(Insert->type,"IO");
	Insert->channel=0x01;
	strcpy(Insert->data,"unpress");
	Insert_Node(Insert);
 
	Print_Node();
	return TRUE;
}









