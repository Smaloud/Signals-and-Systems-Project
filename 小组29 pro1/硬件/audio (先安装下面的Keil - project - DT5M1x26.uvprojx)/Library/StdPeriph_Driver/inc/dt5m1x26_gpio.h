/*****************************************************************************
* @file    		dt5m1x26_gpio.h
* @brief    	DT5M1x26 series gpio drives Include
* @version  	V0.1.02
* @date 		06-29-2023
******************************************************************************
* @attention
* Copyright (C) 2022 Fujian Dongwei Semiconductor Technology Corp. All rights reserved.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the License); you may
* not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an AS IS BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DT5M1x26_GPIO_H__
#define __DT5M1x26_GPIO_H__

#include "stdint.h"
#include "DT5M1x26.h"

enum
{
	GPIO_PIN_MISC_NORMAL,
	GPIO_PIN_MISC_PWMOUT,
};

typedef enum{
	GPIO_DIR_OUT=0,      /*!< GPIO Output Mode             */
	GPIO_DIR_IN          /*!< GPIO Input Mode              */
}GPIO_Dire_TypeDef;

#define IS_GPIO_DIRE(DIRE) (((DIRE) == GPIO_DIR_OUT)|| ((MODE) == GPIO_DIR_IN))

typedef enum{
	GPIO_MODE_GP,
	GPIO_MODE_SF
}GPIO_Mode_TypeDef;

#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_MODE_GP)|| ((MODE) == GPIO_MODE_SF))

typedef enum{
	GPIO_TRIGGER_RISING,
	GPIO_TRIGGER_FALLING,
	GPIO_TRIGGER_BOTH
}GPIO_Triggle_TypeDef;

#define IS_GPIO_TRIGGLE_TYPE(TYPE) (((TYPE) == GPIO_TRIGGER_RISING) || ((TYPE) == GPIO_TRIGGER_FALLING) || ((TYPE) == GPIO_TRIGGER_BOTH))

#define GPIO_PIN_0			(uint32_t)0x00000001
#define GPIO_PIN_1			(uint32_t)0x00000002				
#define GPIO_PIN_2			(uint32_t)0x00000004
#define GPIO_PIN_3			(uint32_t)0x00000008
#define GPIO_PIN_4			(uint32_t)0x00000010
#define GPIO_PIN_5			(uint32_t)0x00000020
#define GPIO_PIN_6			(uint32_t)0x00000040
#define GPIO_PIN_7			(uint32_t)0x00000080
#define GPIO_PIN_8			(uint32_t)0x00000100
#define GPIO_PIN_9			(uint32_t)0x00000200
#define GPIO_PIN_10			(uint32_t)0x00000400
#define GPIO_PIN_11			(uint32_t)0x00000800
#define GPIO_PIN_12			(uint32_t)0x00001000
#define GPIO_PIN_13			(uint32_t)0x00002000
#define GPIO_PIN_14			(uint32_t)0x00004000
#define GPIO_PIN_15			(uint32_t)0x00008000
#define GPIO_PIN_16			(uint32_t)0x00010000
#define GPIO_PIN_17			(uint32_t)0x00020000
#define GPIO_PIN_18			(uint32_t)0x00040000
#define GPIO_PIN_19			(uint32_t)0x00080000
#define GPIO_PIN_20			(uint32_t)0x00100000
#define GPIO_PIN_21			(uint32_t)0x00200000
#define GPIO_PIN_22			(uint32_t)0x00400000
#define GPIO_PIN_23			(uint32_t)0x00800000
#define GPIO_PIN_24			(uint32_t)0x01000000
#define GPIO_PIN_25			(uint32_t)0x02000000
#define GPIO_PIN_26			(uint32_t)0x04000000
#define GPIO_PIN_27			(uint32_t)0x08000000
#define GPIO_PIN_28			(uint32_t)0x10000000
#define GPIO_PIN_29			(uint32_t)0x20000000
#define GPIO_PIN_30			(uint32_t)0x40000000
#define GPIO_PIN_31			(uint32_t)0x80000000
#define GPIO_PIN_32			(uint32_t)0x00000001
#define GPIO_PIN_33			(uint32_t)0x00000002
#define GPIO_PIN_ALL		(uint32_t)0xffffffff
#define GPIO_PIN_0_7		(uint32_t)0x000000ff
#define GPIO_PIN_8_15		(uint32_t)0x0000ff00
#define GPIO_PIN_16_23		(uint32_t)0x00ff0000
#define GPIO_PIN_24_31		(uint32_t)0xff000000

#define SWD_CLK_PIN			GPIO_PIN_3
#define SWD_DAT_PIN			GPIO_PIN_4

#define SPI_MOSI_PIN0		GPIO_PIN_5
#define SPI_CLK_PIN0		GPIO_PIN_6
#define SPI_MISO_PIN0		GPIO_PIN_7
#define SPI_CS_PIN0			GPIO_PIN_8

#define UART_TX_PIN0		GPIO_PIN_9
#define UART_RX_PIN0		GPIO_PIN_10

#define UART_TX_PIN1		GPIO_PIN_22
#define UART_RX_PIN1		GPIO_PIN_23

#define I2C_SCL_PIN0		GPIO_PIN_11
#define I2C_SDA_PIN0		GPIO_PIN_12

#define PWM1_OUT_PIN		GPIO_PIN_13
#define PWM2_OUT_PIN		GPIO_PIN_14

#define AUDIO_OUT1_PIN		GPIO_PIN_15
#define AUDIO_OUT2_PIN		GPIO_PIN_16
typedef enum
{
	GPIO_Pin_0_PUP=0x00000001,
	GPIO_Pin_1_PUP=0x00000002,
	GPIO_Pin_2_PUP=0x00000004,
	GPIO_Pin_3_PUP=0x00000008,
	GPIO_Pin_4_PUP=0x00000010,
	GPIO_Pin_5_PUP=0x00000020,
	GPIO_Pin_6_PUP=0x00000040,
	GPIO_Pin_7_PUP=0x00000080,
	GPIO_Pin_8_PUP=0x00000100,
	GPIO_Pin_9_PUP=0x00000200,
	GPIO_Pin_10_PUP=0x00000400,
	GPIO_Pin_11_PUP=0x00000800,
	GPIO_Pin_12_PUP=0x00001000,
	GPIO_Pin_13_PUP=0x00002000,
	GPIO_Pin_14_PUP=0x00004000,
	GPIO_Pin_15_PUP=0x00008000,
	GPIO_Pin_17_23_PUP=0x00010000,
	GPIO_Pin_24_31_PUP=0x00020000,
}GPIO_Pin_PUP;


#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_PIN_5) || \
                              ((PIN) == GPIO_PIN_6) || \
                              ((PIN) == GPIO_PIN_7) || \
                              ((PIN) == GPIO_PIN_8) || \
                              ((PIN) == GPIO_PIN_11) || \
                              ((PIN) == GPIO_PIN_12) || \
                              ((PIN) == GPIO_PIN_13) || \
                              ((PIN) == GPIO_PIN_14) || \
								((PIN) == GPIO_PIN_16) || \
								((PIN) == GPIO_PIN_17) || \
								((PIN) == GPIO_PIN_18) || \
								((PIN) == GPIO_PIN_19) || \
								((PIN) == GPIO_PIN_20) || \
								((PIN) == GPIO_PIN_21) || \
								((PIN) == GPIO_PIN_22) || \
								((PIN) == GPIO_PIN_23) || \
								((PIN) == GPIO_PIN_24) || \
								((PIN) == GPIO_PIN_25) || \
								((PIN) == GPIO_PIN_26) || \
								((PIN) == GPIO_PIN_27) || \
								((PIN) == GPIO_PIN_28) || \
								((PIN) == GPIO_PIN_32) || \
								((PIN) == GPIO_PIN_33))

/** @defgroup Configuration_Pull-Up_Pull-Down_enumeration 
  * @{
  */
typedef enum
{
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP     = 0x01,
  GPIO_PuPd_DOWN   = 0x02
}GPIO_PuPd_TypeDef;

#define IS_GPIO_PUPD(PUPD) (((PUPD) == GPIO_PuPd_NOPULL) || ((PUPD) == GPIO_PuPd_UP) || \
                            ((PUPD) == GPIO_PuPd_DOWN))

#define IS_GPIO_ENABLE_PU(PIN) (((PIN) == GPIO_PIN_5) || \
                              ((PIN) == GPIO_PIN_6) || \
                              ((PIN) == GPIO_PIN_7) || \
                              ((PIN) == GPIO_PIN_8) || \
                              ((PIN) == GPIO_PIN_11) || \
                              ((PIN) == GPIO_PIN_12) || \
								((PIN) == GPIO_PIN_16) || \
								((PIN) == GPIO_PIN_21) || \
								((PIN) == GPIO_PIN_22) || \
								((PIN) == GPIO_PIN_23) || \
								((PIN) == GPIO_PIN_24) || \
								((PIN) == GPIO_PIN_25) || \
								((PIN) == GPIO_PIN_26) || \
								((PIN) == GPIO_PIN_27) || \
								((PIN) == GPIO_PIN_28) || \
								((PIN) == GPIO_PIN_32) || \
								((PIN) == GPIO_PIN_33))   

#define IS_GPIO_ENABLE_PD(PIN) (((PIN) == GPIO_PIN_13) || \
                              ((PIN) == GPIO_PIN_14) || \
                              ((PIN) == GPIO_PIN_17) || \
								((PIN) == GPIO_PIN_18) || \
								((PIN) == GPIO_PIN_19) || \
								((PIN) == GPIO_PIN_20))	

#define IS_GPIO_ENABLE_TRIGGLE_INT(PIN) (((PIN) == GPIO_PIN_3) || \
										((PIN) == GPIO_PIN_4) || \
										((PIN) == GPIO_PIN_5) || \
										((PIN) == GPIO_PIN_6) || \
										((PIN) == GPIO_PIN_7) || \
										((PIN) == GPIO_PIN_8) || \
										((PIN) == GPIO_PIN_11) || \
										((PIN) == GPIO_PIN_12) || \
										((PIN) == GPIO_PIN_13) || \
										((PIN) == GPIO_PIN_14))	
typedef struct _GOIO_InitStruct
{
	uint32_t GPIO_Pin;
	GPIO_Mode_TypeDef GPIO_Mode;
	GPIO_Dire_TypeDef GPIO_Dir;
	GPIO_PuPd_TypeDef GPIO_PuPd;
} GPIO_InitTypeDef;

typedef enum
{
  WAKEUP_Trigger_Edge,
  WAKEUP_Trigger_Level
}WakeupTrigger_TypeDef;

uint32_t GPIO_GetIntStatus(void);
void GPIO_ClearIntStatus(void);
void GPIO_PUP_Disable(GPIO_Pin_PUP Pin);
void GPIO_PUP_Enable(GPIO_Pin_PUP Pin);
void GPIO_IntMask(uint32_t Pin);
void GPIO_IntUnMask(uint32_t Pin);
void GPIO_EnableTriggleInt(uint32_t Pin);
void GPIO_DisableTriggleInt(uint32_t Pin);
void GPIO_EnableWakeUpInt(void);
void GPIO_DisableWakeUpInt(void);
void GPIO_SetTriggerEdge(uint32_t Pin, GPIO_Triggle_TypeDef Triggle_edge);
void GPIO_ClearTriggerEdge(uint32_t Pin, GPIO_Triggle_TypeDef Triggle_edge);
void GPIO_EnableWakeup(uint32_t Pin, WakeupTrigger_TypeDef Wakeup_Trigger);
void GPIO_DisableWakeup(uint32_t Pin,WakeupTrigger_TypeDef Wakeup_Trigger);
void GPIO_EnableDebounce(uint32_t Pin);
void GPIO_DisableDebounce(uint32_t Pin);
void GPIO_Pin54_Misc(uint32_t mode);
void GPIO_Pin55_Misc(uint32_t mode);
uint8_t GPIO_Pin_ReadBit(GPIO_TypeDef *GPIOx, uint32_t Pin);
void GPIO_Pins_Set(GPIO_TypeDef *GPIOx, uint32_t Pins);
void GPIO_Pins_Reset(GPIO_TypeDef *GPIOx, uint32_t Pins);
void GPIO_StructInit(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);



#endif   //__DT5M1x26_GPIO_H__
