/*****************************************************************************
* @file    		dt5m1x26_systick.c
* @brief    	DT5M1x26 series systick drives
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
#include "dt5m1x26_systick.h"

volatile uint32_t systick_count = 0;
/**
  * @brief  1ms Systick initial.
  * @param  None
  * @retval None
  */
void SysTick1ms_Init(void)
{
    SysTick_Config(9000);
}

/**
  * @brief  Systick interrupt callback function
  * @param  None
  * @retval None
  */
void Systick_Int_Handler(void)
{
    systick_count++;
}

/**
  * @brief  Get Systick counter.
  * @param  None
  * @retval Systick counter
  */
uint32_t SysTick_GetTick(void)
{
    return(systick_count);
}

/**
  * @brief  Reset Systick counter.
  * @param  None
  * @retval None
  */
void SysTick_RstTick(void)
{
    systick_count = 0;
}

/**
  * @brief  delay n*1.5us.
  * @param  None
  * @retval None
  */
void Delay_us(vs32 n)
{
	vs32 i, j;
	for (i = 0; i < n; i++)
	{
		__NOP();
	}
}

/**
  * @brief  delay 1000*n*1.5us.
  * @param  None
  * @retval None
  */
void Delay_ms(uint32_t delay)
{
//    uint32_t tickstart = SysTick_GetTick();

//    while(SysTick_GetTick() - tickstart < delay){}
	Delay_us(1000 * delay);
}
