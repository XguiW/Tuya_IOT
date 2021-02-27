/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EN_LCD_Pin GPIO_PIN_11
#define EN_LCD_GPIO_Port GPIOC
#define EN_WiFi_Pin GPIO_PIN_12
#define EN_WiFi_GPIO_Port GPIOC
#define ADC_VBUS_Pin GPIO_PIN_0
#define ADC_VBUS_GPIO_Port GPIOA
#define ADC_VBAT_Pin GPIO_PIN_1
#define ADC_VBAT_GPIO_Port GPIOA
#define CHG_Pin GPIO_PIN_5
#define CHG_GPIO_Port GPIOA
#define STDBY_Pin GPIO_PIN_6
#define STDBY_GPIO_Port GPIOA
#define EN_EXT_Pin GPIO_PIN_1
#define EN_EXT_GPIO_Port GPIOB
#define EXT_SCL_Pin GPIO_PIN_10
#define EXT_SCL_GPIO_Port GPIOB
#define EXT_SDA_Pin GPIO_PIN_11
#define EXT_SDA_GPIO_Port GPIOB
#define EXT_INT_Pin GPIO_PIN_12
#define EXT_INT_GPIO_Port GPIOB
#define ALERT_Pin GPIO_PIN_6
#define ALERT_GPIO_Port GPIOC
#define INT_Pin GPIO_PIN_7
#define INT_GPIO_Port GPIOC
#define KEY1_Pin GPIO_PIN_9
#define KEY1_GPIO_Port GPIOD
#define KEY_Pin GPIO_PIN_11
#define KEY_GPIO_Port GPIOA
#define BELL_Pin GPIO_PIN_12
#define BELL_GPIO_Port GPIOA
#define RF_RST_Pin GPIO_PIN_9
#define RF_RST_GPIO_Port GPIOC
#define RF_MOSI_Pin GPIO_PIN_0
#define RF_MOSI_GPIO_Port GPIOD
#define RF_MISO_Pin GPIO_PIN_1
#define RF_MISO_GPIO_Port GPIOD
#define RF_PKT_Pin GPIO_PIN_2
#define RF_PKT_GPIO_Port GPIOD
#define RF_CS_Pin GPIO_PIN_3
#define RF_CS_GPIO_Port GPIOD
#define RF_SCK_Pin GPIO_PIN_4
#define RF_SCK_GPIO_Port GPIOD
#define LCD_DC_Pin GPIO_PIN_6
#define LCD_DC_GPIO_Port GPIOB
#define LCD_SDA_Pin GPIO_PIN_7
#define LCD_SDA_GPIO_Port GPIOB
#define LCD_SCK_Pin GPIO_PIN_8
#define LCD_SCK_GPIO_Port GPIOB
#define LCD_CS_Pin GPIO_PIN_9
#define LCD_CS_GPIO_Port GPIOB
#define LCD_RST_Pin GPIO_PIN_10
#define LCD_RST_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
