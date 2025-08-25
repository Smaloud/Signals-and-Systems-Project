/*****************************************************************************
* @file    		dt5m1x26_i2c.h
* @brief    	DT5M1x26 series i2c drives Include
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
#ifndef __DT5M1x26_I2C_H__
#define __DT5M1x26_I2C_H__

#include "DT5M1x26.h"

#define I2C_TX_EMPTY_INT	0x0010
#define I2C_RX_FULL_INT		0x0004

enum
{
	I2C_CMD_WRITE,
	I2C_CMD_READ
};
typedef enum{
	I2C_SPEED_STANDARD = 0,   /*100kbit/s*/
	I2C_SPEED_FAST,						/*400kbit/s*/
	I2C_SPEED_HIGH = 0Xff     /*3.4Mbit/s*/
}I2C_SPEED_Typedef;

typedef enum{
	I2C_ADDR_WIDTH_7BIT,
	I2C_ADDR_WIDTH_10BIT = 0Xff
}I2C_ADDRWIDTH_Typedef;



typedef struct _I2C_InitTypeDef
{
	uint8_t target_addr;
	uint8_t self_addr;
	uint8_t master_mode;
	uint8_t slave_mode;
	uint8_t restart_en;
	uint8_t int_mask;
	I2C_SPEED_Typedef speed;
	I2C_ADDRWIDTH_Typedef addr_width;
} I2C_InitTypeDef;

uint32_t I2C_GetIntFlag(void);
void I2C_ClearInt(void);
void I2C_EnableInt(void);
void I2C_DisableInt(void);
void I2C_Enable(void);
void I2C_Disable(void);
uint8_t I2C_Check_RX_Full(void);
uint8_t I2C_Check_TX_empty(void);
void I2C_Set_RX_FIFO_Level(uint32_t level);
void I2C_Set_TX_FIFO_Level(uint32_t level);
void I2C_Set_Read(void);
uint32_t I2C_Get_RX_FIFO_Level(void);
uint32_t I2C_Get_TX_FIFO_Level(void);
uint8_t I2C_Get_RX_FIFO(void);
uint8_t I2C_Fill_TX_FIFO(uint8_t dat);
uint8_t I2C_Check_RX_FIFO_Empty(void);
uint8_t I2C_Check_RX_FIFO_Full(void);
uint8_t I2C_Check_TX_FIFO_Full(void);
uint8_t I2C_Check_TX_FIFO_Empty(void);
uint32_t I2C_Get_FIFO_RX_Length(void);
uint32_t I2C_Get_FIFO_TX_Length(void);
uint8_t I2C_Check_Activity(void);
void I2C_StructInit(I2C_InitTypeDef *Initstruct);

#endif   //__DT5M1x26_I2C_H__
