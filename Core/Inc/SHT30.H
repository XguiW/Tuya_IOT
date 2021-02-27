#ifndef __SHT30_H
#define __SHT30_H


#include "main.h"
#include "i2c.h"


#define SHT30_Addr 0x88


extern int16_t Temperature;
extern uint16_t Humidity;


// 更新温湿度数据到变量Temperature,Humidity
void SHT30_Updata(void);

// 打开SHT30的加热器，用于传感器自测试
void SHT30_HeaterEnable(void);

// 关闭SHT30的加热器，用于传感器自测试
void SHT30_HeaterDisabled(void);

// SHT30软件复位
void SHT30_SoftReset(void);


#endif

