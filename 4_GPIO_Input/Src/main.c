/*
 * In this program I am going to turn on the led if the button is turned on and vice versa
 *
 * To do this We have to Follow the steps below
 *
 * 0.Enable  Clocks for the ports.
 * 1.Configure the GPIOA5 as output.. That is where the led is connected.
 * 2.Configure the GPIOC13 as input.. User switch is connected.
 *
 */



#include "stm32f4xx.h"


#include <stdint.h>
#define LED					(1U << 5)
#define GPIOAEN 			(1U << 0)
#define GPIOCEN				(1U << 2)
int main(void)
{
	// 1. Enable the clocks for GPIOA5 AND GPIOC13
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	// 2. Configure the Directions for PA5 and PC13
	GPIOA->MODER |=  (1U << 10);  // LED ->Output
	GPIOA->MODER &= ~(1U << 11);

	GPIOC->MODER &= ~(1 << 26);   // Switch ->Input
	GPIOC->MODER &= ~(1 << 27);

	while(1){

		// Check whether the user button is open or closed
		// We have to use the idr register

		// These bits are read-only and can be accessed in word mode only. They contain the input
		// value of the corresponding I/O port.

		// GPIOC->IDR == 0 .. SWITCH IS CLOSED and vice versa

		// Here we are using bit masking

		// IF IDR == 1 SWITCH IS OPEN AND IF IDR == 0 SWITCH IS CLOSED
		while((GPIOC->IDR & (1U << 13 ))==0){
			// Turn on the led
			GPIOA->ODR |= (LED);
		}

		GPIOA->ODR &= ~(LED);

	}

}
