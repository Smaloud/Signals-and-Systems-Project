/*****************************************************************************
* @file    		dt5m1x26_uart.h
* @brief    	DT5M1x26 series uart drives Include
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
#ifndef __DT5M1x26_UART_H__
#define __DT5M1x26_UART_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "DT5M1x26.h"

	/*---------------------------------------------------------------------------------------------------------*/
	/* UA_LCR constants definitions                                                                            */
	/*---------------------------------------------------------------------------------------------------------*/

#define UART_IIR_IID_THRE	(0x2 << UART_IIR_IID_Pos)
#define UART_IIR_IID_RDA	(0x4 << UART_IIR_IID_Pos)

#define UART_IER_ERBFI		0x01
#define UART_IER_ETBEI		0x02

typedef enum{
	UART_WORDLENGTH_5 = 0X00,
	UART_WORDLENGTH_6 = 0X01,
	UART_WORDLENGTH_7 = 0X02,
	UART_WORDLENGTH_8 = 0X03
}UART_Wordlength_TypeDef;

typedef enum{
	UART_STOP_BIT_1   = 0x01,
	UART_STOP_BIT_1_5 = 0x02,
	UART_STOP_BIT_2   = 0x03
}UART_StopBit_TypeDef;

typedef enum{
	UART_PARITY_NONE  = 0x00,
	UART_PARITY_ODD   = 0x01,
	UART_PARITY_EVEN  = 0x03
}UART_Parity_TypeDef;

typedef enum{
	UART_FIFO_ENABLE,
	UART_FIFO_DISABLE
}UART_FIFO_TypeDef;

typedef enum{
	UART_HWFLOW_ENABLE,
	UART_HWFLOW_DISABLE
}UART_HwFlowCtl_TypeDef;



typedef struct
{
	uint32_t BaudRate;
	uint32_t WordLength;
	uint32_t StopBit;
	uint32_t Parity;
	uint32_t HwFlowCtl;
	uint32_t FIFO;
}UART_InitTypeDef;

void UART1_FIFO_Enable(void);
void UART1_FIFO_Disable(void);
uint8_t UART0_GetIntFlag(uint32_t u32InterruptFlag);
void UART0_DisableInt(uint32_t u32InterruptFlag );
void UART0_EnableInt(uint32_t u32InterruptFlag );
void UART0_StructInit(UART_InitTypeDef *InitStruct);
uint32_t UART0_Read(uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
uint32_t UART0_Write(uint8_t *pu8TxBuf, uint32_t u32WriteBytes);
uint8_t UART1_GetIntFlag(uint32_t u32InterruptFlag);
void UART1_DisableInt(uint32_t u32InterruptFlag );
void UART1_EnableInt(uint32_t u32InterruptFlag );
void UART1_StructInit(UART_InitTypeDef *UART_InitTypeDef);
uint32_t UART1_Read(uint8_t *pu8RxBuf, uint32_t u32ReadBytes);
uint32_t UART1_Write(uint8_t *pu8TxBuf, uint32_t u32WriteBytes);

#ifdef __cplusplus
}
#endif

#endif //__DT5M1x26_UART_H__
