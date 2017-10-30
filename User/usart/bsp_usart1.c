/**
  ******************************************************************************
  * @file    bsp_usart1.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����c��printf������usart�˿�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO-MINI STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "bsp_usart1.h"
#include "utility.h"
#include <string.h>
#include "List.h"


uint8_t Rx1_cnt=0;
uint8_t Rx1_buf[400]={0};
uint8_t Rx1_Temp[400]={0};
uint8_t Temp_cnt=0;

 /**
  * @brief  USART1 GPIO ����,����ģʽ���á�9600 8-N-1
  * @param  ��
  * @retval ��
  */
void USART1_Config(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;
		USART_InitTypeDef USART_InitStructure;
		NVIC_InitTypeDef  NVIC_InitStructure;
	   
		/* config USART1 clock */
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
		
		/* USART1 GPIO config */
		/* Configure USART1 Tx (PA.09) as alternate function push-pull */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);    
		/* Configure USART1 Rx (PA.10) as input floating */
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
			
		/* USART1 mode config */
		USART_InitStructure.USART_BaudRate = 115200;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No ;
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		USART_Init(USART1, &USART_InitStructure); 
//		USART_Cmd(USART1, ENABLE);
		
		/*ʹ�ܴ���1�����ж�*/
		USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
		USART_Cmd(USART1, ENABLE);
		
			/* Configure the NVIC Preemption Priority Bits */  
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	  /* Enable the USARTy Interrupt */
  	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	 
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
		
}

void USART1_Receive(void)
{
	uint8_t rxlen = Rx1_cnt;
	
	if(rxlen == Rx1_cnt && rxlen)
	{
	  delay_ms(10);
	  if(rxlen == Rx1_cnt && rxlen)
	  {		
     memcpy(Rx1_Temp,Rx1_buf,Rx1_cnt);		
//	   printf("%s",Rx1_Temp);	
     printf("Delete List\r\n");			
		 Delete_Node(0x02);
		 memset(Rx1_buf,0,Rx1_cnt);
     Rx1_cnt=0;	
			
    }
  }
}

void USART1_Dispose(uint8_t *Msg,uint8_t cnt)
{
  uint8_t i=0;
	uint8_t ch=0;
	
	for(i=0;i<cnt;)
	{
		ch=*(Msg+i++);
    printf("%d",ch);
	}
}




///�ض���c�⺯��printf��USART1
int fputc(int ch, FILE *f)
{
		/* ����һ���ֽ����ݵ�USART1 */
		USART_SendData(USART1, (uint8_t) ch);
		
		/* �ȴ�������� */
		while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);		
	
		return (ch);
}

///�ض���c�⺯��scanf��USART1
int fgetc(FILE *f)
{
		/* �ȴ�����1�������� */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USART1);
}
/*********************************************END OF FILE**********************/