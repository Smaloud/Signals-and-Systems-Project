/*****************************************************************************
* @file    		dt5m1x26_rtc.c
* @brief    	DT5M1x26 series rtc drives
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
#include "dt5m1x26_rtc.h"

static void delay(uint32_t t)
{
	while (t--)
	{
		__nop();
	}
}

//void RTC_Clock_Select()
/**
* @brief Get RTC Interrupt flag
* @param None
* @retval Interrupt flag
*/
uint32_t RTC_GetIntFlag(void)
{
	vu32 r;
	r = RTC->STAT;
	delay(128);
	return r;
}

/**
* @brief Clear RTC Interrupt flag
* @param None
* @retval zero
*/
uint32_t RTC_ClearIntFlag(void)
{
	vu32 r;
	while (RTC->STAT)
	{
		r = RTC->EOI;
		delay(128);
	}
	delay(128);
	return 0;
}

/**
* @brief Enable RTC Interrupt
* @param None
* @retval None
*/
void RTC_EnableInt(void)
{
	NVIC_EnableIRQ(RTC_IRQn);
	RTC->CCR |= RTC_CCR_IEN_Msk;
	delay(128);
}

/**
* @brief Disable RTC Interrupt
* @param None
* @retval None
*/
void RTC_DisableInt(void)
{
	NVIC_DisableIRQ(RTC_IRQn);
	RTC->CCR &= ~RTC_CCR_IEN_Msk;
	delay(128);
}

/**
* @brief Enable RTC
* @param None
* @retval None
*/
void RTC_Enable(void)
{
	RTC->CCR |=BIT2;
	delay(128);
}

/**
* @brief Disable RTC
* @param None
* @retval None
*/
void RTC_Disable(void)
{
	RTC->CCR &=~BIT2;
	delay(128);
}

/**
* @brief RTC Struct initial
* @param Initstruct RTC Struct
* @retval None
*/
void RTC_StructInit(RTC_InitTypeDef *Initstruct)
{
	RTC->CLR = Initstruct->load_counter;
	delay(128);
	RTC->CMR = Initstruct->match_counter;
	delay(128);
	if (Initstruct->wrap_en)
	{
		RTC->CCR |=BIT3;
	}
	else
	{
		RTC->CCR &=~BIT3;
	}
	delay(128);
}

/**
  * @brief  Set RTC Counter load value
  * @param  Counter load value
  * @retval  None
  */
void RTC_SetCLR(uint32_t load_counter)
{
	RTC->CLR = load_counter;
	delay(128);
}

/**
  * @brief  Set RTC Counter Match value
  * @param  Counter Match value
  * @retval  None
  */
void RTC_SetCMR(uint32_t match_counter)
{
	RTC->CMR = match_counter;
	delay(128);
}

/**
  * @brief  Get RTC Counter Match value
  * @param  None
  * @retval  Counter Match value
  */
uint32_t RTC_Get_CMR(void)
{
	vu32 r;

	r = RTC->CMR;
	delay(128);
	return r;
}

/**
  * @brief  Get RTC Counter load value
  * @param  None
  * @retval  Counter Match value
  */
uint32_t RTC_Get_CLR(void)
{
	vu32 r;

	r = RTC->CLR;
	delay(128);
	return r;
}

/**
  * @brief  Get RTC Current Counter Value 
  * @param  none
  * @retval Current Counter Value 
  */
uint32_t RTC_Get_CCVR(void)
{
	vu32 r;

	r = RTC->CCVR;
	delay(128);
	return r;
}
