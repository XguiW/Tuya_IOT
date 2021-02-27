#ifndef __LT8920_H
#define __LT8920_H



#include "stm32g0xx_hal.h"
#include "usart.h"
#include "spi.h"

#define LT8920_SendOK  0
#define LT8920_SendErr 1

struct lt8920_init_reg 
{
	uint8_t  RegAddr;
	uint16_t RegDat;
};





void LT8920_Init(void);
void LT8920_EnterRx(void);
uint8_t LT8920_Send(uint8_t *dat, uint8_t Num);




#endif


