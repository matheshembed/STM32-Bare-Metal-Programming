#include "stm32f4xx.h"
#include "SPI.h"
void spi1_config(void);
void spi1_gpio_init(void);



int main(void)
{
    // Initialize GPIOs for SPI1 and SPI2
    spi2_gpio_init();     // PB13, PB14, PB15
    spi1_gpio_init();     // PA5, PA6, PA7, PA9


    // Configure SPI peripherals
    spi2_config();        // SPI2 as slave (must be ready first)
    spi1_config();        // SPI1 as master

    // Enable slave by pulling CS low
    cs_enable();

    for (int i = 0; i < 8; i++)
    {
        // Wait until SPI1 TXE is set
        while (!(SPI1->SR & SR_TXE)) {}

        // Write data to SPI1
        SPI1->DR = tx_data1[i];

        // Wait until SPI2 RXNE is set
        while (!(SPI2->SR & SR_RXNE)) {}

        // Read received data from SPI2
        rx_data_spi2[i] = SPI2->DR;

        // Wait until SPI1 RXNE is set (optional read)
        while (!(SPI1->SR & SR_RXNE)) {}
        volatile uint8_t dummy __attribute__((unused)) = SPI1->DR;
    }

    // Wait until SPI1 is not busy
    while (SPI1->SR & SR_BSY) {}

    // Disable slave by pulling CS high
    cs_disable();

    // Clear OVR flag on SPI2
    volatile uint8_t temp __attribute__((unused)) = SPI2->DR;
    temp = SPI2->DR;
    temp = SPI2->SR;




    while (1)
    {
        // You can add LED toggle or UART print here to verify rx_data_spi2[]
    }

}
