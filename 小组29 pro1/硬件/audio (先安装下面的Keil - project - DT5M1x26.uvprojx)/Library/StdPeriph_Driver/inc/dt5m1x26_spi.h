/*****************************************************************************
* @file    		dt5m1x26_spi.h
* @brief    	DT5M1x26 series spi drives Include
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
#ifndef __DT5M1x26_SPI_FUNC_H__
#define __DT5M1x26_SPI_FUNC_H__

#include "DT5M1x26.h"

enum
{
	SPI_DFS_4BIT = 3,
	SPI_DFS_5BIT,
	SPI_DFS_6BIT,
	SPI_DFS_7BIT,
	SPI_DFS_8BIT,
	SPI_DFS_9BIT,
	SPI_DFS_10BIT,
	SPI_DFS_11BIT,
	SPI_DFS_12BIT,
	SPI_DFS_13BIT,
	SPI_DFS_14BIT,
	SPI_DFS_15BIT,
	SPI_DFS_16BIT,

	SPI_TMOD_TR,
	SPI_TMOD_TO,
	SPI_TMOD_RO,
	SPI_TMOD_EEPROM,

	SPI_SCPOL_LOW,
	SPI_SCPOL_HIGH,

	SPI_SCPH_MIDDLE,
	SPI_SCPH_FIRST,

	SPI_FRF_SPI,
	SPI_FRF_SSP,
};

typedef enum{
	SPI_STATUS_BUSY = 0x01,           //SPI Busy Flag
	SPI_STATUS_TFNF = 0x02,						//Transmit FIFO Not Full Flag, Bit clear When Full
	SPI_STATUS_TFE  = 0x04,						//Transmit FIFO Empty Flag, Bit Clear While Not Empty
	SPI_STATUS_RFNE = 0x08,           //Receive FIFO Not Empty Flag, Bit Clear After Full
	SPI_STATUS_RFF  = 0x10,						//Receive FIFO Full Flag,Bit Clear if Not Empty
	SPI_STATUS_TXE  = 0x20,						//Transmittion Error Flag,Bit clear When read
	SPI_STATUS_DCOL  = 0x40,					//Data Collision Error Flag,Bit clear When read
}SPI_Status_Typedef;

typedef struct _SPI_InitTypeDef
{
    uint8_t frf;
    uint8_t mode;
    uint8_t scpol;
    uint8_t scph;
    uint8_t dfs;
    uint8_t baund;
	uint8_t master;

} SPI_InitTypeDef;

uint16_t SPI_ReadByte(void);
void SPI_WriteByte(uint16_t byte);
void SPI_StructInit(SPI_InitTypeDef *Initstruct);

#endif   //__DT5M1x26_SPI_FUNC_H__
