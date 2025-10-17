/*
 * Where is the LED Connected ?
 * Port: A
 * Pin: 5
 * Bus: AHB1
 */

#define PERIPH_BASE_ADDR			(0x40000000UL)
#define AHB1_PERIPH_OFFSET			(0x00020000UL)
#define AHB1_BASE_ADDR				(PERIPH_BASE_ADDR + AHB1_PERIPH_OFFSET)

#define GPIOA_OFFSET				(0x0000UL) // 0x00000000 Both are same (Be good at ! Number Systems !)
#define GPIOA_BASE_ADDR 			(AHB1_BASE_ADDR + GPIOA_OFFSET)

#define RCC_OFFSET					(0x3800UL)
#define RCC_BASE_ADDR				(AHB1_BASE_ADDR + RCC_OFFSET)

#define RCC_AHB1ENR_OFFSET			(0x30UL)
#define RCC_AHB1ENR_ADDR			(*(volatile unsigned int * ) (RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET))

#define GPIOA_MODER_OFFSET 			(0x00UL)
#define GPIOA_MODER_ADDR			(*(volatile unsigned int * ) (GPIOA_BASE_ADDR + GPIOA_MODER_OFFSET))

#define GPIOA_ODR_OFFSET			(0x14UL)
#define GPIOA_ODR_ADDR 				(*(volatile unsigned int * ) (GPIOA_BASE_ADDR + GPIOA_ODR_OFFSET))

#define GPIOAEN						(1U << 0)

#define PIN5						(1U << 5)
#define LED_PIN						 PIN5

int main(void) {
	/*
	 * 1. Enable clock to GPIOA
	 * 2. set PA5 as output pin
	 * 3. set the PA5 HIGH
	 */

	// 1. Enable clock to GPIOA
	RCC_AHB1ENR_ADDR |= GPIOAEN;

	// 2. set PA5 as output pin
	GPIOA_MODER_ADDR |= (1U << 10); // Set Bit 10 to High
	GPIOA_MODER_ADDR &= ~(1U << 11); // Set Bit 11 to Low

	while (1) {
		// 3. set the PA5 HIGH
		GPIOA_ODR_ADDR |= LED_PIN;
	}

}

