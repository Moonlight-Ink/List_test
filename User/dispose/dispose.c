#include "dispose.h"
#include "malloc.h"
#include <stdlib.h>
#include <string.h>
#include "bsp_usart1.h"
#include "bsp_led.h"   
#include <stdio.h>

st gpio[]={{1,0x01},{3,0x00},{5,0x00},{6,0x01}};

void Josn_Parse_Switch(char *data)
{		
  cJSON *json,*out,*item,*tc,*child;
  char temp[20]="";
	uint8_t i=0;
	
	json=cJSON_Parse(data); 
	if(!json)
	{
    printf("Error before: [%s]\n",cJSON_GetErrorPtr());
  }
	else
	{
		out=cJSON_GetObjectItem(json,"cmd");
    if(out)
		{
      printf("Get cmd string:%s\r\n",out->valuestring);
		  printf("\r\n");
    }
		
		out=cJSON_GetObjectItem(json,"model");
		if(out)
		{
       printf("Get model string:%s\r\n",out->valuestring);
		   printf("\r\n");
    }
		
		out=cJSON_GetObjectItem(json,"sid");
		if(out)
		{
      printf("Get sid string:%s\r\n",out->valuestring);
			printf("\r\n");
    }
		
		tc=cJSON_GetObjectItem(json,"short_id");
		if(tc)
		{
			printf("Get short_id value:%d\r\n",tc->valueint);
			printf("\r\n");
    }
		
		out=cJSON_GetObjectItem(json,"token");
		if(out)
		{
      printf("Get token string:%s\r\n",out->valuestring);
			printf("Get token string:%s\r\n",cJSON_Print(out));
			printf("\r\n");
    }
		
		item = cJSON_GetObjectItem(json,"data");
		if(item)
		{
			printf("%s\r\n", item->valuestring);
			printf("%s\r\n", cJSON_Print(item));
			printf("%s\r\n", cJSON_PrintUnformatted(item));
			
			child=cJSON_Parse(item->valuestring);
			if(child==NULL)
			{
				printf("Error before: [%s]\n",cJSON_GetErrorPtr());
			}
			else
			{
			  for(i=0;i<6;i++)
        {
         sprintf(temp,"channel_%d",i);
         out = cJSON_GetObjectItem(child,temp);

         if(out)
			   {
					 if(!strcmp(out->valuestring,"on"))
					 {
             LED1_TOGGLE
           }
					 if(!strcmp(out->valuestring,"off")) 
					 {
             LED2_TOGGLE
           }
           if(!strcmp(out->valuestring,"seek")) 					 
					 {
             LED3_TOGGLE
           }
//			  	 printf("Get type string:%d\r\n",out->type);
			  	 printf("Get data string:%s\r\n",out->valuestring);
//				   printf("Get data string:%s\r\n",cJSON_Print(out));	
					 printf("\r\n");
			    }
		     }	
		 cJSON_Delete(child);
		   }			
		}	
		
//	 printf("%s\r\n", "�и�ʽ�ķ�ʽ��ӡJson:");
//   printf("%s\r\n", cJSON_Print(json));
//	 printf("\r\n");
//		
//   printf("%s\r\n", "�޸�ʽ��ʽ��ӡjson: ");
//   printf("%s\r\n", cJSON_PrintUnformatted(json));
//	 printf("\r\n");	
//		
//   printf("%s\r\n", "һ��һ���Ļ�ȡname��ֵ��:");
//		
//   printf("%s\r\n", "��ȡsemantic�µ�cjson����:");
//   item = cJSON_GetObjectItem(json, "semantic");//
//   printf("%s\r\n", cJSON_Print(item));
//	 printf("\r\n");	
//		
//   printf("%s\r\n", "��ȡslots�µ�cjson����");
//	 item = cJSON_GetObjectItem(item, "slots");
//	 printf("%s\r\n", cJSON_Print(item));
//	 printf("\r\n");	
//		
//	 printf("%s\r\n", "��ȡname�µ�cjson����");
//	 item = cJSON_GetObjectItem(item, "name");
//	 printf("%s\r\n", cJSON_Print(item));
//	 printf("\r\n");	
//	 
//	 printf("%s:", item->string); //��һ��cjson����Ľṹ�����������Ա����˼
//	 printf("\r\n");	
//	 printf("%s\r\n", item->valuestring);
//	 printf("\r\n");	
//	 
//	 printf("%s\r\n", "��ӡjson�������ڲ�ļ�ֵ��:");
//	 printJson(json);
//	 printf("\r\n");	

}
	cJSON_Delete(json);
}


void printJson(cJSON * data)//�Եݹ�ķ�ʽ��ӡjson�����ڲ��ֵ��
{
	int i;
	for(i=0; i<cJSON_GetArraySize(data); i++) //���������json��ֵ��
	{
		cJSON * item = cJSON_GetArrayItem(data, i);
		if(cJSON_Object == item->type) //�����Ӧ�ļ�ֵ��ΪcJSON_Object�͵ݹ����printJson
		{
			printJson(item);
			printf("\r\n");			
		}
	else //ֵ��Ϊjson�����ֱ�Ӵ�ӡ������ֵ
	{
		printf("%s->", item->string);
		printf("\r\n");	
		printf("%s\n", cJSON_Print(item));
		printf("\r\n");	
	}
	}
}

void Creat_Cjson(void)
{
	cJSON *root;
	char *out; 
  char tc[150]={0};
	
	text(gpio,tc,4);
	
	root=cJSON_CreateObject();
	cJSON_AddStringToObject(root,"cmd","report");
	cJSON_AddStringToObject(root,"model","perfe1");
	cJSON_AddNumberToObject(root,"addr",0x03);
	cJSON_AddStringToObject(root,"type","io");
	cJSON_AddStringToObject(root,"io",tc);
  out=cJSON_Print(root);
	cJSON_Delete(root);
	printf("%s\n",out);
	myfree(out);

}




char text(st *temp,char *str,u8 cnt)
{
	u8 i=0;
	char *tep1=NULL;
  char *tep2=NULL;	
	tep1=(char*)malloc(sizeof(char) * 15);
  tep2=(char*)malloc(sizeof(char) * 15);
  strcpy(str,"{");
	
	for(i=0;i<cnt;)
	{
		sprintf(tep1,"channel_%d",(temp+i)->Channel_Num);
		
		if((temp+i)->Channel_State)
		{
			memcpy(tep2,"press",8); 
		}		
		else
		{
		 memcpy(tep2,"unpress",10); 
		}
		
			
	  strcat(str,"\"");
	  strcat(str,tep1);
		strcat(str,"\":\"");
		strcat(str,tep2);
	  strcat(str,"\"");
		i++;
		if(i<cnt)
		{
     strcat(str,",");
    }
  }
    free(tep1);
    free(tep2);
		tep1=NULL;
		tep2=NULL;	
		strcat(str,"}");
}






























