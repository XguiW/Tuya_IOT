#ifndef __SHT30_H
#define __SHT30_H


#include "main.h"
#include "i2c.h"


#define SHT30_Addr 0x88


extern int16_t Temperature;
extern uint16_t Humidity;


// ������ʪ�����ݵ�����Temperature,Humidity
void SHT30_Updata(void);

// ��SHT30�ļ����������ڴ������Բ���
void SHT30_HeaterEnable(void);

// �ر�SHT30�ļ����������ڴ������Բ���
void SHT30_HeaterDisabled(void);

// SHT30������λ
void SHT30_SoftReset(void);


#endif
