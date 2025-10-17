#include "stm32f4xx.h"

#define GPIOAEN					(1U << 0)
#define PIN5					(1U << 5)
#define LED_PIN_ON				 PIN5
#define LED_PIN_OFF            	(1U << 21)

int main(void){

	/*
	 * Section 7.4.7 in the RM
	 * The BSRR Register is used to Set and Reset the GPIO Pin
	 * To set make BSx => High
	 * To reset make BRx => High
	 *
	 */

	RCC->AHB1ENR |= GPIOAEN;
	GPIOA->MODER |=  (1U << 10);
	GPIOA->MODER &=  (~(1U << 11));
	while(1){
		GPIOA->BSRR = LED_PIN_ON;
		for(int i=0; i<100000; i++){}

		GPIOA->BSRR = LED_PIN_OFF;
		for(int i=0; i<100000; i++){}
	}
}
