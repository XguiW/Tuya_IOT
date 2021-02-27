#ifndef __LCD_H
#define __LCD_H


#include "spi.h"
#include "stm32g0xx_hal.h"


#define X_MAX_PIXEL	        240
#define Y_MAX_PIXEL	        240
#define USE_HORIZONTAL			3


#define RED			0xF800
#define GREEN		0x07E0
#define BLUE		0x001F
#define WHITE		0xffff
#define BLACK		0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D			//»ÒÉ«0 3165 00110 001011 00101
#define GRAY1   0x8410			//»ÒÉ«1				00000 000000 00000
#define GRAY2   0x4208			//»ÒÉ«2  1111111111011111
#define PURPLE	0xf81f


//void LCD_WriteCommand(uint8_t Com);
//void LCD_WriteData(uint8_t data);
//void SPI_Send(uint8_t *pData, uint16_t Size, uint32_t Timeout);


void LCD_Init(void);
void LCD_Clear(uint16_t Color);

void LCD_Putchar_ASCII8x16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, char ch);
void LCD_Putchar_ASCII16x32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, char ch);
void LCD_Puts_ASCII8x16(uint8_t x, uint8_t y, uint16_t font_color, uint16_t fill_color, char * str);
void LCD_Puts_ASCII16x32(uint8_t x, uint8_t y, uint16_t font_color, uint16_t fill_color, char * str);

#endif
