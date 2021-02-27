//#include "LT8920.H"



//struct lt8920_init_reg const LT8920_Reg[] =    
//{
//	{ 0, 0x6fe0 }, //-- 6fe0(Recommand)(6fef = default)
//	{ 1, 0x5681 },
//	{ 2, 0x6617 },
//	{ 4, 0x9cc9 },
//	{ 5, 0x6637 },
//	{ 7, 0x0030 }, //channel is 2402Mhz
//	{ 8, 0x6c90 },
//	{ 9, 0x4800 }, //PA -12.2dbm,1840?
//	{10, 0x7ffd },
//	{11, 0x0008 },
//	{12, 0x0000 },
//	{13, 0x48bd },
//	{22, 0x00ff },
//	{23, 0x8005 },
//	{24, 0x0067 },
//	{25, 0x1659 },
//	{26, 0x19e0 },
//	{27, 0x1300 },
//	{28, 0x1800 },
//	{32, 0x4800 }, //--32Bit Addr.
//	{33, 0x3fc7 },
//	{34, 0x2000 },
//	{35, 0x0500 }, //-- ReSend Timer=10?4?
//	{36, 0x0380 },
//	{37, 0x0380 },
//	{38, 0x5A5A },
//	{39, 0x0380 },
//	{40, 0x4402 },
//	{41, 0xBC00 }, /*CRC is ON, scramble is OFF, AUTO_ACK  Enable, PKT Low Active*/
//	{42, 0xFDb0 }, /*??RX_ACK?? 176us*/
//	{43, 0x000f },
//	{44, 0x1000 }, 
//	{45, 0x0552 }, //-- 62.5 kpbs
//	{50, 0x0000 }  
//};


//uint8_t SPI_WriteReadByte(uint8_t Txdat)
//{
//	while (!(SPI1->SR&SPI_SR_TXE));
//	*(__IO uint8_t*)&SPI1->DR = Txdat;
//	while (!(SPI1->SR&SPI_SR_RXNE));
//	return *(__IO uint8_t*)&SPI1->DR;	
//}





//void LT8920_WriteReg(uint8_t Reg, uint16_t dat)
//{
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
//	SPI_WriteReadByte(Reg & 0x7F);	
//	SPI_WriteReadByte(dat>>8);
//	SPI_WriteReadByte(dat);
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);	
//}

//void LT8920_ReadReg(uint8_t Reg, uint16_t *dat)
//{
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
//	SPI_WriteReadByte(Reg|0x80);
//	*dat  = SPI_WriteReadByte(0xFF) << 8;
//	*dat |= SPI_WriteReadByte(0xFF);
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);	
//}

//void LT8920_WriteFIFO(uint8_t *dat, uint8_t num)
//{
//	uint8_t i;

//	if ((num == 0) || (num >= 64))
//		return;
//	
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
//	SPI_WriteReadByte(50);
//	SPI_WriteReadByte(num);
//	for(i = 0; i < num; i++){
//		SPI_WriteReadByte(dat[i]);
//	}
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
//}

//uint8_t LT8920_ReadFIFO(uint8_t *dat, uint8_t num)
//{
//	uint8_t i, len;

//	if ((num == 0) || (num >= 64))
//		return 0;
//	
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
//	SPI_WriteReadByte(0xB2);
//	len = SPI_WriteReadByte(0xFF);
//	for(i = 0; i < num; i++){
//		dat[i] = SPI_WriteReadByte(0xFF);
//	}
//	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);

//	return len;
//}

//void LT8920_EnterRx(void)
//{
//	LT8920_WriteReg(7,  0x004E);  //--- Enter [ IDLE ]
//	HAL_Delay(10);
//	LT8920_WriteReg(52, 0x8080);  //--- Clear TX/RX FIFO
//	HAL_Delay(10);
//	LT8920_WriteReg(7,  0x00CE);  //--- Clear TX/RX FIFO
//	HAL_Delay(10);
//}


//void LT8920_Init(void)
//{
//	uint8_t  i;
//	
//	__HAL_SPI_ENABLE(&hspi1);	   // ¿ªÆôSPI
//	SPI_WriteReadByte(0xFF);

//	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_RESET);
//	HAL_Delay(100);
//	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET);
//	HAL_Delay(100);

//	for (i = 0; i < 34; i++){
//		LT8920_WriteReg(LT8920_Reg[i].RegAddr, LT8920_Reg[i].RegDat);
//	}	
//}

//void LT8920_CheckLock(void)
//{
//	uint16_t temp;

//	LT8920_ReadReg(0x03, &temp);
//	if (temp & (1<<12))
//		printf("RF Locked\r\n");
//	else
//		printf("RF Unlocked\r\n");
//}


//uint8_t LT8920_Send(uint8_t *dat, uint8_t Num)
//{
//	uint8_t i;
//	static uint16_t result;

//	for (i = 0; i < 5; i++){
//		LT8920_WriteReg(7,  0x004E);  //--- Enter [ IDLE ]
//		LT8920_WriteReg(52, 0x8080);  //--- Clear TX/RX FIFO
//		LT8920_WriteFIFO(dat, Num);
//		LT8920_WriteReg(7,  0x014E);  //--- Enter [ TX ]

//		while(HAL_GPIO_ReadPin(PKT_GPIO_Port, PKT_Pin));
//		LT8920_WriteReg(7,  0x004E);  //--- Enter [ IDLE ]

//		LT8920_ReadReg(52, &result);
//		if ((result & 0x003F) == 0x0000){
//			//printf("Send OK\r\n");
//			return LT8920_SendOK;
//		}
//		//printf("Send Err %d\r\n", i);
//	}
//	

//	return LT8920_SendErr;
//}





















