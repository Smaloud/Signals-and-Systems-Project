/*****************************************************************************
* @file    		dt5m1x26_i2c.c
* @brief    	DT5M1x26 series I2C drives
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
#include "dt5m1x26_i2c.h"

/**
* @brief Get I2C transmit Abort source
* @note Register will reset after read
* @retval None
*/
uint32_t I2C_GetTxAbort_flag(void)
{
	return I2C->TX_ABORD_SOURCE;
}

/**
* @brief Clear I2C interrupt flag
* @param None
* @retval None
*/
void I2C_ClearInt(void)
{
	vu32 r;
	r = I2C->CLR_INTR;
}

/**
* @brief Get I2C interrupt flag
* @param None
* @retval interrupt flag
*/
uint32_t I2C_GetIntFlag(void)
{
	return I2C->INTR_STAT;
}

/**
* @brief Enable I2C interrupt
* @param None
* @retval None
*/
void I2C_EnableInt(void)
{
	NVIC_EnableIRQ(I2C_IRQn);
}

/**
* @brief Disable I2C interrupt
* @param None
* @retval None
*/
void I2C_DisableInt(void)
{
	NVIC_DisableIRQ(I2C_IRQn);
}

/**
* @brief Enable I2C
* @param None
* @retval None
*/
void I2C_Enable(void)
{
	I2C->EN = 1;
}

/**
* @brief Disable I2C
* @param None
* @retval None
*/
void I2C_Disable(void)
{
	I2C->EN = 0;
}

/**
* @brief Set I2C FIFO Transmit buffer length threshod
* @param level threshod
* @retval None
*/
void I2C_Set_TX_FIFO_Level(uint32_t level)
{
	I2C->TX_TL = level;
}

/**
* @brief Set I2C FIFO Receive buffer length threshod
* @param level threshod
* @retval None
*/
void I2C_Set_RX_FIFO_Level(uint32_t level)
{
	I2C->RX_TL = level;
}

/**
* @brief Get I2C FIFO Transmit buffer length threshod
* @param  None
* @retval level threshod
*/
uint32_t I2C_Get_TX_FIFO_Level(void)
{
	return I2C->TXFLR;
}

/**
* @brief Get I2C FIFO Receive buffer length threshod
* @param None
* @retval level threshod
*/
uint32_t I2C_Get_RX_FIFO_Level(void)
{
	return I2C->RXFLR;
}

/**
* @brief Check if is I2C FIFO Transmit buf empty
* @param None
* @retval 1:FIFO empty 0:not empty
*/
uint8_t I2C_Check_TX_FIFO_Empty(void)
{
	if (I2C->STATUS & I2C_SR_TFE_Msk) return(1);
	return(0);
}

/**
* @brief Check if is I2C FIFO Transmit buf full
* @param None
* @retval 1:FIFO Full 0:not full
*/
uint8_t I2C_Check_TX_FIFO_Full(void)
{
	if (I2C->STATUS & I2C_SR_TFNF_Msk) return(0);
	return(1);
}

/**
* @brief Check if is I2C FIFO Receive buf full
* @param None
* @retval 1:FIFO Full 0:not full
*/
uint8_t I2C_Check_RX_FIFO_Full(void)
{
	if (I2C->STATUS & I2C_SR_RFF_Msk) return(1);
	return(0);
}

/**
* @brief Check if is I2C FIFO Receive buf empty
* @param None
* @retval 1:FIFO empty 0:not empty
*/
uint8_t I2C_Check_RX_FIFO_Empty(void)
{
	if (I2C->STATUS & I2C_SR_RFNE_Msk) return(0);
	return(1);
}

void I2C_Set_Read(void)
{
	I2C->DATA_CMD = BIT8; //set read
}

/**
* @brief Check if is length of Data in I2C FIFO Transmit buf less than the threshold that set by IC_TX_TL register
* @param None
* @note  register reset by hardware
* @retval 1:more than
*/
uint8_t I2C_Check_TX_empty(void)
{
	if (I2C->RAW_INTR_STAT & RAW_INTR_STAT_TX_EMPTY_Msk) return(1);
	return(0);
}

/**
* @brief Get I2C FIFO Transmit Data Length
* @param None
* @retval Transmit Data Length
*/
uint32_t I2C_Get_FIFO_TX_Length(void)
{
	return(I2C->TXFLR);
}

/**
* @brief Get I2C FIFO Receive Length
* @param None
* @retval Receive Data Length
*/
uint32_t I2C_Get_FIFO_RX_Length(void)
{
	return(I2C->RXFLR);
}

/**
* @brief Fill Data to I2C FIFO buf
* @param None
* @retval Transmit Data Length
*/
uint8_t I2C_Fill_TX_FIFO(uint8_t dat)
{
	I2C->DATA_CMD = dat;
	//return I2C->DATA_CMD;
	return 0;
}

/**
* @brief Check if is length of Data in I2C FIFO Receive buf more than the threshold that set by IC_RX_TL register
* @param None
* @note  register reset by hardware
* @retval 1:more than
*/
uint8_t I2C_Check_RX_Full(void)
{
	if (I2C->RAW_INTR_STAT & RAW_INTR_STAT_RX_FULL_Msk) return(1);
	return(0);
}

/**
* @brief Get I2C FIFO Receive Data
* @param None
* @retval Receive Data
*/
uint8_t I2C_Get_RX_FIFO(void)
{
	while (I2C_Check_RX_FIFO_Empty());
	return I2C->DATA_CMD;
}

/**
* @brief Check if I2C is activity
* @param None
* @retval 1: I2C is activity
*/
uint8_t I2C_Check_Activity(void)
{
	if (I2C->STATUS & I2C_SR_ACTIVITY_Msk) return(1);
	return(0);
}

/**
* @brief I2C Struct Initial
* @param Initstruct: I2C Struct
* @retval None
*/
void I2C_StructInit(I2C_InitTypeDef *Initstruct)
{
	I2C->EN = 0;

	if (Initstruct->master_mode) I2C->CON |= I2C_CON_MASTER_MODE_Msk;
	else I2C->CON &= ~I2C_CON_MASTER_MODE_Msk;
	/*I2C is allowed to act as both master and slave */
	if (Initstruct->slave_mode) I2C->CON &= ~I2C_CON_SLAVE_DISABLE_Msk;
	else I2C->CON |= I2C_CON_SLAVE_DISABLE_Msk;
	
	
	if (Initstruct->addr_width == I2C_ADDR_WIDTH_10BIT){
		I2C->CON |= I2C_CON_SLAVE_ADDR_10BIT_Msk;
		I2C->CON |= I2C_CON_MASTER_ADDR_10BIT_Msk;
	}
	else{
		I2C->CON &= ~I2C_CON_SLAVE_ADDR_10BIT_Msk;
		I2C->CON &= ~I2C_CON_MASTER_ADDR_10BIT_Msk;
	}
	
	/*I2C Slave Address while i2c used as slave*/
	I2C->SAR = Initstruct->self_addr;
	/* I2C target device address while I2C used as master*/
	I2C->TAR = (Initstruct->target_addr>>1);
	/*I2C Speed set*/
	switch (Initstruct->speed){
		case I2C_SPEED_STANDARD:{
			I2C->CON |= BIT1;
			I2C->CON &= ~BIT2;
			break;
		}
		case I2C_SPEED_FAST:{
			I2C->CON &= ~BIT1;
			I2C->CON |= BIT2;
			break;
		}
		case I2C_SPEED_HIGH:{
			I2C->CON |= BIT1;
			I2C->CON |= BIT2;
			break;
		}
		default:break;
	}

	if (Initstruct->restart_en) I2C->CON |= I2C_CON_RESTART_EN_Msk;
	else I2C->CON &= ~I2C_CON_RESTART_EN_Msk;

	I2C->EN = 1;
}
