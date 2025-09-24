

#include "adc.h"
#include "uart.h"
#include <stdint.h>
#include <stdio.h>


uint32_t sensor_value;
float voltage, tempC;

int main(void)
{
    Pa1_Adc_Init();
    UART2TX_Init();
    Start_Conversion_Conti();

    while(1)
    {
        sensor_value = Adc_Read();

        // Convert ADC → Voltage
        voltage = (sensor_value / 4095.0) * 3.3;

        // Voltage → Temperature in Celsius (LM35 = 10mV per °C)
        tempC = voltage * 100.0;

        // Print temperature
        printf("Temperature: %f °C \n\r", tempC);

        for(long i = 0; i < 1000000; i++) {}  // crude delay
    }
}



