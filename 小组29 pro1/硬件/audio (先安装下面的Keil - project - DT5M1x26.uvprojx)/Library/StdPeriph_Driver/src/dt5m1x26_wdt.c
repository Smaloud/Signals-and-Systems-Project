/*****************************************************************************
* @file    		dt5m1x26_wdt.c
* @brief    	DT5M1x26 series wdt drives
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
#include "dt5m1x26_wdt.h"

static void delay(uint32_t t)
{
	while (t--)
	{
		__nop();
	}
}

/**
  * @brief  Get WDt Interrupt flag
  * @param  None
  * @retval  None
  */
uint32_t WDT_GetIntFlag(void)
{
	vu32 r;
	r = WDT->STAT;
	delay(128);
	return r;
}

/**
  * @brief  Clear WDt Interrupt flag
  * @param  None
  * @retval  None
  */
uint32_t WDT_ClearIntFlag(void)
{
	vu32 r;
	while (WDT->STAT){
		r = WDT->EOI;
		delay(128);
	}
	delay(128);
	return 0;
}

/**
  * @brief  Enable WDt Interrupt
  * @param  None
  * @retval  None
  */
void WDT_EnableInt(void)
{
	NVIC_EnableIRQ(WDT_IRQn);
	WDT->CCR |= WDT_CCR_IEN_Msk;
	delay(128);
}

/**
  * @brief  Disable WDt Interrupt
  * @param  None
  * @retval  None
  */
void WDT_DisableInt(void)
{
	NVIC_DisableIRQ(WDT_IRQn);
	WDT->CCR &= ~WDT_CCR_IEN_Msk;
	delay(128);
}

/**
  * @brief  Enable WDt
  * @param  None
  * @retval  None
  */
void WDT_Enable(void)
{
	WDT->CCR |=BIT2;
	delay(128);
}

/**
  * @brief  Disable WDt
  * @param  None
  * @retval  None
  */
void WDT_Disable(void)
{
	WDT->CCR &=~BIT2;
	delay(128);
}

/**
  * @brief  WDt Struct Initial
  * @param  WDt Struct
  * @retval  None
  */
void WDT_StructInit(WDT_InitTypeDef *Initstruct)
{
	delay(128);
	WDT->CLR = Initstruct->load_counter;
	delay(128);
	WDT->CMR = Initstruct->match_counter;
	delay(128);
	if (Initstruct->wrap_en) WDT->CCR |=BIT3;
	else WDT->CCR &=~BIT3;
	delay(128);
	if (Initstruct->reset_en) RCC->CR1.all = 0x303f;
	else RCC->CR1.all = 0x103f;
}

/**
  * @brief  Set WDt Counter load value
  * @param  Counter load value
  * @retval  None
  */
void WDT_SetCLR(uint32_t load_counter)
{
	WDT->CLR = load_counter;
	delay(128);
}

/**
  * @brief  Set WDt Counter Match value
  * @param  Counter Match value
  * @retval  None
  */
void WDT_SetCMR(uint32_t match_counter)
{
	WDT->CMR = match_counter;
	delay(128);
}

/**
  * @brief  Get WDt Counter Match value
  * @param  none
  * @retval  Counter Match value
  */
uint32_t WDT_Get_CMR(void)
{
	vu32 r;

	r = WDT->CMR;
	delay(128);
	return r;
}

/**
  * @brief  Get WDt Counter load value(Counter start value)
  * @param  none
  * @retval Counter Reload value
  */
uint32_t WDT_Get_CLR(void)
{
	vu32 r;

	r = WDT->CLR;
	delay(128);
	return r;
}

/**
  * @brief  Get WDt Current Counter Value 
  * @param  none
  * @retval Current Counter Value 
  */
uint32_t WDT_Get_CCVR(void)
{
	vu32 r;

	r = WDT->CCVR;
	delay(128);
	return r;
}

/**
  * @brief  WDT fresh 
  * @param  none
  * @retval None
  */
void WDT_Refesh(void)
{
	WDT->CLR = 0;
	delay(128);
}
