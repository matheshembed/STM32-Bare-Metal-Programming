
#include "stm32f4xx.h"

#define TIM2_EN					(1U << 0) // To enable to clock access to the timer APB1ENR
#define CR1_CEN					(1U << 0)

#define GPIOAEN					(1U <<0)
void Tim2_1hr_Init(void)
{
	/* Enable Clock access to tim2*/
	/* Tim2 Is connected with APB1 BUS Runs at 45Mhz*/
	RCC->APB1ENR |= TIM2_EN;


	/* Set the Prescalar value*/
	/* Our default system clock is 16 Mhz */
	/* We want to the timer to end up at 1 Hz */
	TIM2->PSC = 1600 - 1; // We count from Zero so , we put minus 1 here
	// 16 000 000/1600 = 10000

	/* Set the auto reload value*/
	TIM2->ARR = 10000 - 1; // We count from Zero so , we put minus 1 here again
	// 10 000 / 10 000 = 1 // Therefore we end up with 1 hertz

	/* Clear counter*/
	TIM2->CNT = 0;

	/* Enable Timer*/
	TIM2->CR1 |= CR1_CEN ;
}

void Tim2_PA5_Output_Compare(void)
{
	/*Enable clock access to gpioa*/
	 RCC->AHB1ENR |= GPIOAEN;
	/*PA5 Mode to alternate function Mode*/
	 GPIOA->MODER |= (1U << 11);
	 GPIOA->MODER &= (~(1U << 10));
	/*Alternate function Type to TIM2_CH1*/
	 GPIOA->AFR[0] |= (1U << 20);
	 GPIOA->AFR[0] &= (~(1U << 21));
	 GPIOA->AFR[0] &= (~(1U << 22));
	 GPIOA->AFR[0] &= (~(1U << 23));

	/* Enable Clock access to tim2*/
	/* Tim2 Is connected with APB1 BUS Runs at 45Mhz*/
	RCC->APB1ENR |= TIM2_EN;


	/* Set the Prescalar value*/
	/* Our default system clock is 16 Mhz */
	/* We want to the timer to end up at 1 Hz */
	TIM2->PSC = 1600 - 1; // We count from Zero so , we put minus 1 here
	// 16 000 000/1600 = 10000

	/* Set the auto reload value*/
	TIM2->ARR = 10000 - 1; // We count from Zero so , we put minus 1 here again
	// 10 000 / 10 000 = 1 // Therefore we end up with 1 hertz

	/* Set Output_Compare Toggle Mode*/
	TIM2->CCMR1 |= (1U << 4);
	TIM2->CCMR1 |= (1U << 5);
	/* Enable TIM2_CH1 in compare mode*/
	TIM2->CCER |= (1U << 0);


	/* Clear counter*/
	TIM2->CNT = 0;

	/* Enable Timer*/
	TIM2->CR1 |= CR1_CEN ;
}

void Tim3_PA6_Input_Capture(void)
{
	/*Enable clock access to gpioa*/
	 RCC->AHB1ENR |= GPIOAEN;

	 /*PA5 Mode to alternate function Mode*/
	 GPIOA->MODER |= (1U << 13);
	 GPIOA->MODER &= (~(1U << 12));

	/*Alternate function Type to TIM3_CH1*/
	 GPIOA->AFR[0] &= ~(1U << 24);
	 GPIOA->AFR[0] |= (1U << 25);
	 GPIOA->AFR[0] &= (~(1U << 26));
	 GPIOA->AFR[0] &= (~(1U << 27));

	 /*Enable the Clock access to TIM3*/
	 RCC->APB1ENR |= (1U << 1);

	 /*Set Prescaler*/
	 TIM3->PSC = 1600 - 1; // 16 000 000/16 000

	 /*Set CH1 to input capture*/
	 TIM3->CCMR1 |= (1U << 0);

	 /*Set CH1 To capture at rising edge*/
	 TIM3->CCER |= (1U << 0);

	 /*Enable timer 3*/
	 TIM3->CR1 |= (1U << 0);



}
