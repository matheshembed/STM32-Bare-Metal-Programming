



#ifndef UART_H_
#define UART_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

void UART2TX_Init(void);
int UART2_Read(void);
void Uart2_Write(int ch);
void UART2RXTX_Init(void);


#endif /* UART_H_ */
