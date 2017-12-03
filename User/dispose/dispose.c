
#include "dispose.h"

#include <stdlib.h>
#include "string.h"
#include "bsp_usart1.h"
#include "bsp_led.h"   


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






u8  text(u8 s)
{
	char  test[100]="";
	char  s1='{';
	char  s2='\\';
	char  s3='"';
	char  s4=':';
	char  s5=',';
	char  s6='}';
	
	char t1[]="channel_1";
	char tt1[]="open";
  
	strcpy(test,&s1);
  strcat(test,&s2);
  strcat(test,&s3);		
	strcat(test,t1);
	strcat(test,&s2);
	strcat(test,&s3);
	strcat(test,&s4);
	strcat(test,&s2);
	strcat(test,&s3);
	strcat(test,tt1);
	strcat(test,&s2);
	strcat(test,&s3);
	strcat(test,&s6);
	
	printf("%s",test);

}






























