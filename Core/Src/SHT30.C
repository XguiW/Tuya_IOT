#include "sht30.h"

int16_t	 Temperature;
uint16_t Humidity;

// �ӿں������ӳ�
void SHT30_Delay(uint32_t time_ms)
{
	HAL_Delay(time_ms);
}

// �ӿں�����I2Cд����
HAL_StatusTypeDef SHT30_I2C_Transmit(uint8_t *pData, uint8_t Size)
{
	return HAL_I2C_Master_Transmit(&hi2c1, SHT30_Addr, pData, Size, 1);
}

// �ӿں�����I2C������
HAL_StatusTypeDef SHT30_I2C_Receive(uint8_t *pData, uint8_t Size)
{
	return HAL_I2C_Master_Receive(&hi2c1, SHT30_Addr, pData, Size, 1);
}


// ������ʪ�����ݵ�����Temperature,Humidity
void SHT30_Updata(void)
{
	uint8_t timeout = 200, res;
	uint8_t Command[2];
	uint8_t RecDat[6];

	// Single Shot, Repeatability:High
	Command[0] = 0x24;
	Command[1] = 0x00;
	SHT30_I2C_Transmit(Command, 2);

	// Readout of Measurement Results for Single Shot Mode
	while(timeout--){
		res = SHT30_I2C_Receive(RecDat, 6);
		if (res == HAL_OK)
			break;
		SHT30_Delay(1);
	}
	if (res != HAL_OK)
		return;
	
	// Conversion of Signal Output
	Temperature = RecDat[0] << 8;
	Temperature = Temperature | RecDat[1];
	Temperature = - 4500 + 17500 * Temperature / 65535 ;
	Humidity	= RecDat[3] << 8;
	Humidity	= Humidity | RecDat[4];
	Humidity	= 10000 * Humidity / 65535;	
}

// ��SHT30�ļ����������ڴ������Բ���
void SHT30_HeaterEnable(void)
{
	uint8_t Command[2];

	Command[0] = 0x30;
	Command[1] = 0x6D;
	SHT30_I2C_Transmit(Command, 2);	
}

// �ر�SHT30�ļ����������ڴ������Բ���
void SHT30_HeaterDisabled(void)
{
	uint8_t Command[2];

	Command[0] = 0x30;
	Command[1] = 0x66;
	SHT30_I2C_Transmit(Command, 2);	
}


// SHT30������λ
void SHT30_SoftReset(void)
{
	uint8_t Command[2];

	Command[0] = 0x30;
	Command[1] = 0xA2;
	SHT30_I2C_Transmit(Command, 2);	
}


