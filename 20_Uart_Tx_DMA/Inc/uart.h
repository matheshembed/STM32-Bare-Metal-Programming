



#ifndef UART_H_
#define UART_H_

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

#define UART_SR_RXE 			(1U << 5)

//Dma definitions
#define HISR_TCIF6	(1U << 21)
#define HIFCR_CTC1F6 (1U << 21)

int UART2_Read(void);
void Uart2_Write(int ch);
void UART2RXTX_Init(void);
void UART2RX_Interrupt_Init(void);
void UART2TX_Init(void);

// Dma Functions
void DMA1_Stream6_Init(uint32_t src, uint32_t dest, uint32_t len);


#endif /* UART_H_ */
