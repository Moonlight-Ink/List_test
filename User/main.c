/**
******************************************************************************
* @file    			main.c
* @author  			WIZnet Software Team
* @version 			V1.0
* @date    			2015-02-14
* @brief   			��3.5.0�汾�⽨�Ĺ���ģ��
* @attention  	ʵ��ƽ̨��Ұ�� iSO-MINI STM32 ������ + Ұ��W5500���������
*
*               Ĭ��ʹ��Ұ�𿪷����SPI1�ӿڣ���Ͽ���J10��A4��cs��Ķ̽�ñ
*
*               �������ԣ��뱣֤W5500��IP�����PC����ͬһ�����ڣ��Ҳ���ͻ
*               ����������߸�PC��ֱ����������PC���������ӵ�ַIPΪ��̬IP
* 
*               ���Ա�����ǰ���Ƚ�w5500_conf.c�ļ��е�Remote_IP,�趨Ϊ
*               TCP Server��IP��ַ��ͨѶ�˿ڣ�Ĭ��Ϊ5000
* 
* ʵ��ƽ̨:Ұ�� iSO-MINI STM32 ������ 
* ��̳    :http://www.chuxue123.com
* �Ա�    :http://firestm32.taobao.com
******************************************************************************
*/ 
#include <stdio.h>
#include <string.h>
#include "stm32f10x.h"
#include "bsp_usart1.h"
#include "utility.h"
#include "bsp_led.h"   
#include "List.h"
#include "cJSON.h"
#include "dispose.h"

//st gpio[]={{1,0x01},{3,0x00},{5,0x00},{6,0x01}};
	
int main(void)
{ 	 
	systick_init(72);				            /*��ʼ��Systick����ʱ��*/
	USART1_Config(); 				            /*��ʼ������ͨ��:115200@8-n-1*/
  LED_GPIO_Config();
//  printf(" List Test\r\n");		
//	
//	Head=NodeCreat();
//	Insert_data();
////	Print_Node();
//	text(gpio,4);
//  Creat_Cjson();
	

	
	while(1)                            /*ѭ��ִ�еĺ���*/ 
	{
		USART1_Receive();

	}
} 



