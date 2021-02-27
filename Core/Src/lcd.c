#include "LCD.H"
#include "FONT.H"



/*----------------------   LCD接口函数-------------------------------------------*/
//    调用接口函数 延时
void delay_ms(uint16_t time)
{
	HAL_Delay(time);
}
//    调用接口函数 SPI发送数据
void SPI_Send(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	HAL_SPI_Transmit(&hspi2, pData, Size, Timeout);
	//SPI_Transmit(&hspi2, pData, Size, Timeout);
}
//    调用接口函数 A0置高
void LCD_A0_Set(void)
{
	LCD_DC_GPIO_Port->BSRR = (uint32_t)LCD_DC_Pin;
}
//    调用接口函数 A0置低
void LCD_A0_Reset(void)
{
	LCD_DC_GPIO_Port->BRR = (uint32_t)LCD_DC_Pin;
}
//    调用接口函数 RST置高
void LCD_RST_Set(void)
{
	LCD_RST_GPIO_Port->BSRR = (uint32_t)LCD_RST_Pin;
}
//    调用接口函数 RST置低
void LCD_RST_Reset(void)
{
	LCD_RST_GPIO_Port->BRR = (uint32_t)LCD_RST_Pin;
}
/*----------------------   LCD接口函数-------------------------------------------*/





void LCD_WriteCommand(uint8_t Com)
{
	LCD_A0_Reset();			// Set to Command mode
	SPI_Send(&Com, 1, 1);	// For HAL Library
	LCD_A0_Set();			// After finish Command, set to data mode
}

void LCD_WriteData(uint8_t data)
{
	//HAL_GPIO_WritePin(LCD_A0_GPIO_Port, LCD_A0_Pin, GPIO_PIN_SET);		// Set to data mode
	SPI_Send(&data, 1, 1);	// For HAL Library
}

void LCD_WriteColor(uint16_t Color)
{	
	uint8_t dat[2];
	
	dat[0] = Color>>8;
	dat[1] = Color;
	SPI_Send(dat, 2, 1);	// For HAL Library
}






void LCD_Init(void)
{
	LCD_RST_Reset();
	delay_ms(100);
	LCD_RST_Set();
	delay_ms(20);
	
	//************* Start Initial Sequence **********// 
	LCD_WriteCommand(0x36); 
	if 			(USE_HORIZONTAL == 0)	LCD_WriteData(0x00);
	else if (USE_HORIZONTAL == 1)	LCD_WriteData(0xC0);
	else if (USE_HORIZONTAL == 2)	LCD_WriteData(0x70);
	else if (USE_HORIZONTAL == 3)	LCD_WriteData(0xA0);

	LCD_WriteCommand(0x3A); 
	LCD_WriteData(0x05);

	LCD_WriteCommand(0xB2);
	LCD_WriteData(0x0C);
	LCD_WriteData(0x0C);
	LCD_WriteData(0x00);
	LCD_WriteData(0x33);
	LCD_WriteData(0x33);

	LCD_WriteCommand(0xB7); 
	LCD_WriteData(0x35);  

	LCD_WriteCommand(0xBB);
	LCD_WriteData(0x32);

	LCD_WriteCommand(0xC2);
	LCD_WriteData(0x01);

	LCD_WriteCommand(0xC3);
	LCD_WriteData(0x15);   

	LCD_WriteCommand(0xC4);
	LCD_WriteData(0x20);  

	LCD_WriteCommand(0xC6); 
	LCD_WriteData(0x0F);    

	LCD_WriteCommand(0xD0); 
	LCD_WriteData(0xA4);
	LCD_WriteData(0xA1);

	LCD_WriteCommand(0xE0);
	LCD_WriteData(0xD0);
	LCD_WriteData(0x08);
	LCD_WriteData(0x0E);
	LCD_WriteData(0x09);
	LCD_WriteData(0x09);
	LCD_WriteData(0x05);
	LCD_WriteData(0x31);
	LCD_WriteData(0x33);
	LCD_WriteData(0x48);
	LCD_WriteData(0x17);
	LCD_WriteData(0x14);
	LCD_WriteData(0x15);
	LCD_WriteData(0x31);
	LCD_WriteData(0x34);

	LCD_WriteCommand(0xE1);
	LCD_WriteData(0xD0);
	LCD_WriteData(0x08);
	LCD_WriteData(0x0E);
	LCD_WriteData(0x09);
	LCD_WriteData(0x09);
	LCD_WriteData(0x15);
	LCD_WriteData(0x31);
	LCD_WriteData(0x33);
	LCD_WriteData(0x48);
	LCD_WriteData(0x17);
	LCD_WriteData(0x14);
	LCD_WriteData(0x15);
	LCD_WriteData(0x31);
	LCD_WriteData(0x34);

	LCD_WriteCommand(0x21); 

	LCD_WriteCommand(0x11); 

	LCD_WriteCommand(0x29);	
}


/*************************************************
函数名：LCD_Set_Region
功能：设置lcd显示区域，在此区域写点数据自动换行
入口参数：xy起点和终点,Y_IncMode表示先自增y再自增x
返回值：无
*************************************************/
void LCD_SetRegion(uint16_t x_start,uint16_t y_start,uint16_t x_end,uint16_t y_end)
{		
	uint8_t dat[4] = {0};

	if (USE_HORIZONTAL == 0)
	{
		LCD_WriteCommand(0x2A);				//列地址设置
		dat[0] = x_start >> 8;
		dat[1] = x_start;
		dat[2] = x_end >> 8;
		dat[3] = x_end;
		SPI_Send(dat, 4, 1);

		LCD_WriteCommand(0x2B);				//行地址设置
		dat[0] = y_start >> 8;
		dat[1] = y_start;
		dat[2] = y_end >> 8;
		dat[3] = y_end;
		SPI_Send(dat, 4, 1);		
	}
	else if (USE_HORIZONTAL == 1)
	{
		LCD_WriteCommand(0x2A);				//列地址设置
		dat[0] = x_start >> 8;
		dat[1] = x_start;
		dat[2] = x_end >> 8;
		dat[3] = x_end;
		SPI_Send(dat, 4, 1);

		LCD_WriteCommand(0x2B);				//行地址设置
		dat[0] = (y_start+80) >> 8;
		dat[1] = (y_start+80);
		dat[2] = (y_end+80) >> 8;
		dat[3] = (y_end+80);
		SPI_Send(dat, 4, 1);		
	}
	else if (USE_HORIZONTAL == 2)
	{
		LCD_WriteCommand(0x2A);				//列地址设置
		dat[0] = x_start >> 8;
		dat[1] = x_start;
		dat[2] = x_end >> 8;
		dat[3] = x_end;
		SPI_Send(dat, 4, 1);

		LCD_WriteCommand(0x2B);				//行地址设置
		dat[0] = y_start >> 8;
		dat[1] = y_start;
		dat[2] = y_end >> 8;
		dat[3] = y_end;
		SPI_Send(dat, 4, 1);		
	}
	else if (USE_HORIZONTAL == 3)
	{
		LCD_WriteCommand(0x2A);				//列地址设置
		dat[0] = (x_start+80) >> 8;
		dat[1] = (x_start+80);
		dat[2] = (x_end+80) >> 8;
		dat[3] = (x_end+80);
		SPI_Send(dat, 4, 1);

		LCD_WriteCommand(0x2B);				//行地址设置
		dat[0] = y_start >> 8;
		dat[1] = y_start;
		dat[2] = y_end >> 8;
		dat[3] = y_end;
		SPI_Send(dat, 4, 1);		
	}

	//储存器写
	LCD_WriteCommand(0x2C);
}





/*************************************************
函数名：LCD_Clear
功能：全屏清屏函数
入口参数：填充颜色COLOR
返回值：无
*************************************************/
void LCD_Clear(uint16_t Color)               
{	
	uint8_t DIS_Buff[600];
	uint16_t i;

	Color = (Color>>8)|(Color<<8);
	
	for (i = 0; i < 600; i++){
		DIS_Buff[i] = Color;
	}

	LCD_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);

	for (i = 0; i < 192; i++){
		SPI_Send(DIS_Buff, 600, 5);
	}
}



/*************************************************
函数名：LCD_Clear_Reg
功能：局部屏函数
入口参数：填充颜色COLOR
返回值：无
*************************************************/
void LCD_Clear_Reg(uint16_t x_start,uint16_t y_start,uint16_t x_end,uint16_t y_end,uint16_t Color)               
{	
   unsigned int i,m;
		
	 LCD_SetRegion(127-y_end+1,x_start,127-y_start,x_end+1);
 
	//LCD_WriteCommand(0x2C);

	for(m=127-y_end+1;m<127-y_start;m++) {
		for(i=x_start;i<x_end+1;i++){	
		LCD_WriteData(Color>>8);
		LCD_WriteData(Color);
		//LCD_WriteData16(Color);
		}
	}
}

void LCD_Putchar_ASCII8x16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, char ch)
{
	//    由于硬件SPI发送16bit的高低位反了，所以提前将颜色打调。   在Puts中实现。
	uint8_t i, j, DIS_Buff[256];	// 一个16x32字符的Buff大小：8*16*2
	uint16_t position;
	uint16_t *point = (uint16_t*)DIS_Buff;
	
	position = (ch - 0x20)*16;
	
	LCD_SetRegion(x, y, x+7, y+15);
	
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 8; j++, point++)
		{
			if (asc16[position+i] & (0x80>>j))
			{
				(*point) = fc;
				//LCD_WriteColor(fc);
			}
			else
			{
				(*point) = bc;
				//LCD_WriteColor(bc);
			}
		}
	}
	
	//	发送数组的数据
	SPI_Send(DIS_Buff, 256, 5);
}

void LCD_Puts_ASCII8x16(uint8_t x, uint8_t y, uint16_t font_color, uint16_t fill_color, char * str)
{
	//    由于硬件SPI发送16bit的高低位反了，所以提前将颜色打调。
	font_color = (font_color>>8)|(font_color<<8);
	fill_color = (fill_color>>8)|(fill_color<<8);

	for(; *str != 0; str++){
		LCD_Putchar_ASCII8x16(x, y, font_color, fill_color, *str);
		x += 8;
	}
}


void LCD_Putchar_ASCII16x32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, char ch)
{
	//    由于硬件SPI发送16bit的高低位反了，所以提前将颜色打调。   在Puts中实现。
	uint8_t i, j, DIS_Buff[1024];	// 一个16x32字符的Buff大小：32*16*2
	uint16_t position;
	uint16_t *point = (uint16_t*)DIS_Buff;
	
	position = (ch - 0x20)*64;
	
	LCD_SetRegion(x, y, x+15, y+31);
	
	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < 8; j++, point++)
		{
			if (asc32[position+i*2] & (0x80>>j))
			{
				(*point) = fc;
				LCD_WriteColor(fc);
			}
			else
			{
				(*point) = bc;
				LCD_WriteColor(bc);
			}
		}
		for (j = 0; j < 8; j++, point++)
		{
			if (asc32[position+i*2+1] & (0x80>>j))
			{
				(*point) = fc;
				LCD_WriteColor(fc);
			}
			else
			{
				(*point) = bc;
				LCD_WriteColor(bc);
			}
		}
	}
	
	//	发送数组的数据
	SPI_Send(DIS_Buff, 1024, 10);
}

void LCD_Puts_ASCII16x32(uint8_t x, uint8_t y, uint16_t font_color, uint16_t fill_color, char * str)
{
	//    由于硬件SPI发送16bit的高低位反了，所以提前将颜色打调。
	font_color = (font_color>>8)|(font_color<<8);
	fill_color = (fill_color>>8)|(fill_color<<8);
	
	for(; *str != 0; str++){
		LCD_Putchar_ASCII16x32(x, y, font_color, fill_color, *str);
		x += 16;
	}
}










