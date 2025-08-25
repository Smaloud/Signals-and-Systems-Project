/*****************************************************************************
* @file    		dt5m1x26_spi.c
* @brief    	DT5M1x26 series spi drives
* @version  	V0.1.02
* @date 		  06-29-2023
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
#include "dt5m1x26_spi.h"

/**
  * @brief  Clear Spi Interrupt flag
  * @param None
  * @retval None
  */
void SPI_IntFlag_clear(void)
{
	uint32_t r;
	r = SPI->DR;
}

/**
  * @brief  Get Spi Status
  * @param None
  * @retval SPi Status
  */
uint32_t SPI_Status_Get(void)
{
	return(SPI->SR);
}

/**
  * @brief  SPI Read data
  * @param None
  * @retval Receive Data
  */
uint16_t SPI_ReadByte(void)
{
	vu32 r;
	vu16 data;
	
	SPI->DR = 0xFF;
	while (!(SPI->SR & SPI_SR_TFE_Msk));
	while (SPI->SR & SPI_SR_BUSY_Msk);
	while (!(SPI->SR & SPI_SR_RFNE_Msk));
	
	r = SPI->ICR;
	data = SPI->DR;

	return data;
}

/**
  * @brief  SPI Write data
  * @param Data to write
	* write and read is together,after write receive buffer should clear
  * @retval None
  */
void SPI_WriteByte(uint16_t byte)
{
	vu32 r;

	SPI->DR = (uint16_t)byte;
	while(!(SPI->SR & SPI_SR_TFE_Msk));
	while(SPI->SR & SPI_SR_BUSY_Msk);

	r = SPI->ICR;
	r = SPI->DR;
}

void SPI_StructInit(SPI_InitTypeDef *Initstruct)
{
	uint32_t reg_val;
	vu32 r;

	SPI->SSIENR = 0;
	reg_val = SPI->CTRLR0;
	reg_val &= 0xfff0;
	reg_val |= Initstruct->dfs;

	switch (Initstruct->mode)
	{
	case SPI_TMOD_TR:
		reg_val &= ~(BIT8 | BIT9);
		break;

	case SPI_TMOD_TO:
		reg_val |= BIT8;
		reg_val &= ~BIT9;
		break;
	case SPI_TMOD_EEPROM:
		reg_val |= BIT8;
		reg_val |= BIT9;
		break;
	default:
		reg_val |= BIT9;
		reg_val &= ~BIT8;
		break;
	}
	if (Initstruct->scpol == SPI_SCPOL_LOW)
	{
		reg_val &= ~BIT7;
	}
	else
	{
		reg_val |= BIT7;
	}
	if (Initstruct->scph == SPI_SCPH_MIDDLE)
	{
		reg_val &= ~BIT6;
	}
	else
	{
		reg_val |= BIT6;
	}
	if (Initstruct->frf == SPI_FRF_SPI)
	{
		reg_val &= ~(BIT4 | BIT5);
	}
	else
	{
		reg_val |= (BIT4);
		reg_val &= ~(BIT5);
	}

	SPI->SSIENR = 0+(Initstruct->master<<1);
	SPI->CTRLR0 = reg_val;
	SPI->CTRLR1 = 0x3;           //special for TMOD=eeprom mode
	SPI->BAUDR = Initstruct->baund;
//	SPI->TXFTLR = 1;
//	SPI->RXFTLR = 1;
	SPI->SER    = 1;
	SPI->IMR    = 0;
	r = SPI->ICR;
	SPI->SSIENR = 1+(Initstruct->master<<1);
}
