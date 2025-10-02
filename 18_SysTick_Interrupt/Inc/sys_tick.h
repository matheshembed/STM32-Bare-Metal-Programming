
#ifndef SYS_TICK_H_
#define SYS_TICK_H_

#include "stm32f4xx.h"


void SysTickDelayMs(int delay);
void SysTick_1Hz_Interrupt(void);

#endif /* SYS_TICK_H_ */
