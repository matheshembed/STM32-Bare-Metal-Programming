

#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"

#define GPIOAEN					(1U << 0)
#define UART2EN					(1U << 17)
#define USART2_CR1				(1U << 3)
#define UART_EN					(1U << 13)
#define UART_SR_TXE				(1U << 7)

#define SYS_FREQ				16000000 // MCU CLOCK SPEED
#define APB1_CLK				SYS_FREQ

#define UART_BAUDRATE			112500

static void Uart_Set_Bd(USART_TypeDef *USARTx, uint32_t PeriClk, uint32_t BaudRate);
static uint16_t Compute_Uart_Bd(uint32_t PeriClk, uint32_t BaudrRate);
void UART2TX_Init(void);
void Uart2_Write(char ch);

int __io_putchar(int ch){
	Uart2_Write(ch);
	return ch;
}


int main(void){

	UART2TX_Init();


	while(1){

		printf("Hello from STM32F446RE...............\n\r");

	}
}

void UART2TX_Init(void){
	// The UART2 IS CONNECTED TO THE GPIOA AND PIN 2
	// To initialize the uart we have to make the gpio as the alternate function which is



	// Clock access to the GPIOA
	RCC->AHB1ENR |=  GPIOAEN ;

	// Setting PA2 to alternate function mode
	GPIOA->MODER |=  (1U << 5);
	GPIOA->MODER &= ~((1U << 4));

	// Set PA2 to alternate function tyoe to UART_TX (AF7)
	// AFRL REGISTER DUE THE USART IS CONNECTED TO THE GPIO PIN 2
	GPIOA->AFR[0] &= (~(1U << 11));
	GPIOA->AFR[0] |= (1U << 10);
	GPIOA->AFR[0] |= (1U << 9);
	GPIOA->AFR[0] |= (1U << 8);

	// Enable the Clock access to the UART 2
	RCC->APB1ENR |=  UART2EN ;

	// Configure the Baud rate
	Uart_Set_Bd(USART2, APB1_CLK, UART_BAUDRATE);

	// Configure the transfer direction
	// I want to clear every bits of the register and set only the 3 pin that is why we are not usig the OR operator
	USART2->CR1 |= USART2_CR1;
	//Since we are already written the value in the CR1 Register ourself we dont want it to be vanished .. we need that ... so using the OR Operator as usual.
	USART2->CR1 |= UART_EN;
}

void Uart2_Write(char ch){
	// Make sure the transmit data register is empty before writing the data to it
	// Then Write to transmit data register

	// 0 => Data is not transferred to the shift register
	// 1 =>  Data is transferred to the shift register
	while(!(USART2->SR & UART_SR_TXE));

	// Write to the Transmit data register
	USART2->DR =  (ch & 0xFF);
}
static void Uart_Set_Bd(USART_TypeDef *USARTx, uint32_t PeriClk, uint32_t BaudRate){

	USARTx->BRR = Compute_Uart_Bd(PeriClk,BaudRate);
}

static uint16_t Compute_Uart_Bd(uint32_t PeriClk, uint32_t BaudRate){

	return ((PeriClk + (BaudRate/2U))/BaudRate);
}


