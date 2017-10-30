#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include <stdio.h>


//extern uint8_t Rx1_cnt;
//extern uint8_t Rx1_buf[400];


void USART1_Config(void);
void USART1_Receive(void);
void USART1_Dispose(uint8_t *Msg,uint8_t cnt);
//int fputc(int ch, FILE *f);
//void USART1_printf(USART_TypeDef* USARTx, uint8_t *Data,...);

#endif /* __USART1_H */
