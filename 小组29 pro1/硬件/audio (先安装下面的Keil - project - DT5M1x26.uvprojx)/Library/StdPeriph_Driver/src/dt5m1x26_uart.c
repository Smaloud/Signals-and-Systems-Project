/*****************************************************************************
* @file    		dt5m1x26_uart.c
* @brief    	DT5M1x26 series uart drives
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
#include <stdio.h>
#include "dt5m1x26_uart.h"

int fputc(int ch, FILE *f)
{
	UART1->THR = (uint8_t) ch;
	/* Loop until the end of transmission */
	while ((UART1->LSR & UART_LSR_TEMT_Msk) == 0){}
	return ch;
}


/**
  * @brief  Enable UART1 transmit by FIFO
  * @retval None
  */
void UART1_FIFO_Enable(void)
{
	UART1->FCR |= UART_IIR_FIFOSE_Msk;
}
/**
  * @brief  Disable UART1 transmit by FIFO
  * @retval None
  */
void UART1_FIFO_Disable(void)
{
	UART1->FCR &= ~UART_IIR_FIFOSE_Msk;
}

/**
  * @brief  Get UART Interrupt flag
  * @param u32InterruptFlag interrupt flag
  * @retval None
  */
uint8_t UART1_GetIntFlag(uint32_t u32InterruptFlag)
{
	switch (u32InterruptFlag)
	{
		case UART_IER_ERBFI:{
			if (UART1->IIR & UART_IIR_IID_RDA) return 1;
			break;
		}
		case UART_IER_ETBEI:{
			if (UART1->IIR & UART_IIR_IID_THRE) return 1;
			break;
		}

	}
	return 0;
}

/**
  * @brief  UART Interrupt disable
  * @param u32InterruptFlag interrupt flag
  * @retval None
  */
void UART1_DisableInt(uint32_t u32InterruptFlag)
{
	NVIC_DisableIRQ(UART1_IRQn);
	UART1->IER &= ~ u32InterruptFlag;
}

/**
  * @brief  UART Interrupt enable
  * @param u32InterruptFlag interrupt flag
  * @retval None
  */
void UART1_EnableInt(uint32_t u32InterruptFlag)
{
	NVIC_EnableIRQ(UART1_IRQn);
	UART1->IER |= u32InterruptFlag;
}

/**
  * @brief  UART set
  * @param UART_InitTypeDef UART Param
  * @retval None
  */
void UART1_StructInit(UART_InitTypeDef *UART_InitTypeDef)
{
	while (UART1->USR & 0x01);//wait uart idle
	
	UART1->LCR = 0x00;
	/*BaudRate set*/
	UART1->LCR |= UART_LCR_DLAB_Msk;
	UART1->DLL  = (uint32_t)(1000000.0f/(((float)UART_InitTypeDef->BaudRate)*3.625f));
	UART1->DLH  = 0;

	/*Word length set*/
	UART1->LCR |= UART_InitTypeDef->WordLength;
	/*UART StopBit set*/
	UART1->LCR |= ((UART_InitTypeDef->StopBit >> 1) << 2);
	/*parity set*/
	UART1->LCR |= (UART_InitTypeDef->Parity << 3);
	/*FIFO set*/
	if (UART_InitTypeDef->FIFO == UART_FIFO_ENABLE) UART1->FCR |= UART_IIR_FIFOSE_Msk;
	else UART1->FCR &= ~UART_IIR_FIFOSE_Msk;
	
	UART1->LCR &= ~UART_LCR_DLAB_Msk;
}

/**
  * @brief  UART data read
  * @param pu8RxBuf buf to store received data
  * @param u32ReadBytes the length of data to read
  * @retval received data length
  */
uint32_t UART1_Read(uint8_t *pu8RxBuf, uint32_t u32ReadBytes)
{
	uint32_t  u32Count, u32delayno;

	for (u32Count = 0; u32Count < u32ReadBytes; u32Count++){
		u32delayno = 0;

		while (!(UART1->LSR & UART_LSR_DR_Msk)){
			/* Check RX empty => failed */
			u32delayno++;
			if ( u32delayno >= 0x40000000 )
				return FALSE;
		}
		pu8RxBuf[u32Count] = UART1->RBR;    /* Get Data from UART RX  */
	}

	return u32Count;

}

/**
  * @brief  UART data write
  * @param pu8RxBuf data buf to send
  * @param u32ReadBytes the length of data to send
  * @retval send data length
  */
uint32_t UART1_Write(uint8_t *pu8TxBuf, uint32_t u32WriteBytes)
{
	uint32_t  u32Count, u32delayno;

	for (u32Count = 0; u32Count != u32WriteBytes; u32Count++){
		u32delayno = 0;
		while ((UART1->LSR & UART_LSR_TEMT_Msk) == 0){
			/* Wait Tx empty and Time-out manner */
			u32delayno++;
			if ( u32delayno >= 0x40000000 )
				return FALSE;
		}
		UART1->THR = pu8TxBuf[u32Count];    /* Send UART Data from buffer */
	}

	return u32Count;
}
