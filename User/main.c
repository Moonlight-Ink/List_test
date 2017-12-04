/**
******************************************************************************
* @file    			main.c
* @author  			WIZnet Software Team
* @version 			V1.0
* @date    			2015-02-14
* @brief   			用3.5.0版本库建的工程模板
* @attention  	实验平台：野火 iSO-MINI STM32 开发板 + 野火W5500网络适配板
*
*               默认使用野火开发板的SPI1接口，请断开“J10”A4与cs间的短接帽
*
*               内网测试，请保证W5500的IP与测试PC机在同一网段内，且不冲突
*               如果是用网线跟PC机直连，请设置PC机本地连接地址IP为静态IP
* 
*               测试本程序前，先将w5500_conf.c文件中的Remote_IP,设定为
*               TCP Server的IP地址和通讯端口，默认为5000
* 
* 实验平台:野火 iSO-MINI STM32 开发板 
* 论坛    :http://www.chuxue123.com
* 淘宝    :http://firestm32.taobao.com
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
	systick_init(72);				            /*初始化Systick工作时钟*/
	USART1_Config(); 				            /*初始化串口通信:115200@8-n-1*/
  LED_GPIO_Config();
//  printf(" List Test\r\n");		
//	
//	Head=NodeCreat();
//	Insert_data();
////	Print_Node();
//	text(gpio,4);
//  Creat_Cjson();
	

	
	while(1)                            /*循环执行的函数*/ 
	{
		USART1_Receive();

	}
} 



