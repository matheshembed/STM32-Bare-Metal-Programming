/*
************************SysTick Timer**********************

* The SysTick Timer is found in all ARM Cortex Microcontrollers,
* Regardless of the Silicon Manufacturer.
* This means This comes with ARM architecture itself.

* Used for taking actions periodically.
	- Often used as time-base for RTOS

* The systick is a 24-bit Down Counter driven by the processor clock.

* Counts from initial value down to zero
* 24-bits imply maximum initial value of:
	2^24 = 0xFFFFFFF = 16,777,2116

	Initial Value can be set to a value between
	0x0000000 to 0xFFFFFFF

* SysTick Registers
	- SysTick Current Value Register (STCVR)
		This register contains the current count value
	- SysTick Control & Status Register (STCSR)
		This Register allows us to configure the systick clock source, enable/disable interrupts and enable/disable the systick counter
	- SysTick Reload Value Register (STRVR)
		This is where the initial count value is placed
*************************************************************
Compute the delay achieved by loading 10 in the systick reload value register(STRVR) given system clock = 16 Mhz
Written as :
	SysTick->LOAD =9
		- Written in the CMSIS standard
		- We write 9 although we want 10 because the counter starts counting from 0

	Solution:
		system clock = 16 Mhz = 16 000 000 cycles / second
		if 1 second executes 16 000 000 cycles how many seconds execute 1 cycle ?

		1 / 16000000 = 62.5 ns = 62.5*10^(-9) s

		Then 10 cycles => 10 * 62.5*10^(-9) s = 625*10^(-9) = 625ns

		System clock (sysclk) is chosen as clock source
			systick->LOAD = N

			Delay Achieved = N*(1/Sysclock) = N/Sysclock

	EG:
		Compute N value for achieving a 1ms delay given SYSCLK as 16Mhz
		1 ms = 0.001s
		delay = n/sysclk
		0.001 = n/16 000 000
		n = 0.001 * 16 000 000
		n = 16 000
*/

/* SysTick is Architecture specific so we have to read the Generic User Guide from ARM */
/* Refer Section 4.4 */

#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL					16000 // Cycles for Each Milli Second

// To Set the Systick Counter in the systick control and status register
#define CTRL_EN								(1U << 0)

// To configure the clock source for the systick n the systick control and status register
// 0 => External Clock , 1 => Processor Clock
#define CTRL_CLKSRC							(1U << 2)

//Returns 1 if the timer counted to 1 since last time this was read
#define CTRL_COUNTFLAG						(1U << 16)

void SysTickDelayMs(int delay)
{
	// Configure systick
	// Reload with number of clocks per milli seconds
	SysTick->LOAD = SYSTICK_LOAD_VAL;

	// Clear Systick current value register
	SysTick->VAL = 0;

	// Enable systick and select internal clock source
	SysTick->CTRL |= CTRL_EN | CTRL_CLKSRC ;

	for(int i=0; i < delay ; i++)
	{
		// Wait until the cont flag is set
		while((SysTick->CTRL & CTRL_COUNTFLAG) == 0){}

	}

	SysTick->CTRL = 0;


}













