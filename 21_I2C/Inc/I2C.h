

#ifndef I2C_H_
#define I2C_H_
#include "stm32f4xx.h"


void I2C1_Init(void);
void I2C_ByteRead(char saddr, char maddr, char* data );
void I2C1_BurstRead(char saddr, char maddr, int n, char* data);
void I2C1_BurstWrite(char saddr, char maddr, int n, char* data);



#endif /* I2C_H_ */
