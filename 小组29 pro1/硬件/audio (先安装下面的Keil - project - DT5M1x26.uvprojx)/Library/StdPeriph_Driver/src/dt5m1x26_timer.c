/*****************************************************************************
* @file    		dt5m1x26_timer.c
* @brief    	DT5M1x26 series timer drives
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
#include "dt5m1x26_timer.h"

/**
  * @brief  Timer Enable.
  * @param  timer
  * @retval None
  */
void Timer_Enable(TIMER_TypeDef *timer)
{
	timer->CR |= TIMER_CR_ENABLE_Msk;
}

/**
  * @brief  Timer Disable.
  * @param  timer
  * @retval None
  */
void Timer_Disable(TIMER_TypeDef *timer)
{
	timer->CR &= ~TIMER_CR_ENABLE_Msk;
}

/**
  * @brief  Enable Timer Capture
  * @param  timer
  * @retval None
  */
void Timer1_Capture_enalbe(TIMER_TypeDef *timer)
{
	timer->CR |= TIMER_CR_CAPTURE_ENABLE_Msk | TIMER_CR_ENABLE_Msk;
}

/**
  * @brief  Disable Timer Capture
  * @param  timer
  * @retval None
  */
void Timer1_Capture_disable(TIMER_TypeDef *timer)
{
	timer->CR &= ~TIMER_CR_CAPTURE_ENABLE_Msk;
}

/**
  * @brief  Enable Timer genrated by ext clock.
  * @param  timer
  * @retval None
  */
void Timer1_Extclk_enalbe(TIMER_TypeDef *timer)
{
	timer->CR |= TIMER_CR_EXTCLK_ENABLE_Msk;
}

/**
  * @brief  Disable Timer genrated by ext clock.
  * @param  timer
  * @retval None
  */
void Timer1_Extclk_disable(TIMER_TypeDef *timer)
{
	timer->CR &= ~TIMER_CR_EXTCLK_ENABLE_Msk;
}

/**
  * @brief  Enable Timer Interrupt.
  * @param  timer
  * @retval None
  */
void Timer_EnableInt(TIMER_TypeDef *timer)
{
	Timer_ClearIntFlag(timer);
	timer->CR &= ~TIMER_CR_INT_MASK_Msk;
	if (timer == TIMER0) NVIC_EnableIRQ(TIMER0_IRQn);
	else NVIC_EnableIRQ(TIMER1_IRQn);
}

/**
  * @brief  Disable Timer Interrupt.
  * @param  timer
  * @retval None
  */
void Timer_DisableInt(TIMER_TypeDef *timer)
{
	Timer_ClearIntFlag(timer);
	timer->CR |= TIMER_CR_INT_MASK_Msk;
	if (timer == TIMER0) NVIC_DisableIRQ(TIMER0_IRQn);
	else NVIC_DisableIRQ(TIMER1_IRQn);
}

/**
  * @brief  Get Timer Interrupt flag.
  * @param  timer
  * @retval None
  */
uint8_t Timer_GetIntFlag(TIMER_TypeDef *timer)
{
	return timer->IS;
}

/**
  * @brief  Clear Timer Interrupt flag by Read EOI Register.
  * @param  timer
  * @retval 0
  */
uint8_t Timer_ClearIntFlag(TIMER_TypeDef *timer)
{
	return timer->EOI;
}

/**
  * @brief  Set Timer Load Counter.
  * @param  timer
  * @param  load_counter 
  * @retval None
  */
void Timer_SetLC(TIMER_TypeDef *timer, uint32_t load_counter)
{
	timer->LC = load_counter;
}

/**
  * @brief  Get Timer Current Counter.
  * @param  timer
  * @retval Current Counter
  */
uint32_t Timer_Get_CV(TIMER_TypeDef *timer)
{
	return timer->CV;
}
/**
  * @brief  Timer Struct initial.
  * @param  timer
  * @param  Initstruct
  * @retval None
  */
void Timer_StructInit(TIMER_TypeDef *timer, TIMER_InitStruct *Initstruct)
{

	if (Initstruct->run_mode == TIMER_MODE_DOWNCOUNT) timer->CR |=TIMER_CR_TIMER_MODE_Msk;
	else timer->CR &=~TIMER_CR_TIMER_MODE_Msk;

	timer->LC = Initstruct->load_counter;
	if (Initstruct->capture_mode==1) timer->CR |= TIMER_CR_ENABLE_Msk + TIMER_CR_CAPTURE_ENABLE_Msk;//enable capture
	else if (Initstruct->capture_mode==2) timer->CR |= TIMER_CR_ENABLE_Msk + TIMER_CR_EXTCLK_ENABLE_Msk + TIMER_EXT_CLK_DIV4;//enable external clock
	else timer->CR |= TIMER_CR_ENABLE_Msk;
}


