
#include "uart.h"
#include "adc.h"

uint32_t sensor_value;
int main(void)
{


	Pa1_Adc_Init();
	// If we want to print the values in the serial monitor we have to initizlize uart_tx
	// And pass the values in the print function.
	// This is the reason to include the files of uart ...
	//UART2TX_Init();


	while(1)
	{
		Start_Conversion();
		sensor_value = Adc_Read();
		//printf("Sensor Value : %ld \n\r ",sensor_value);
		for(int i=0; i<100000; i++){}
	}




}



