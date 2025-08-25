/*****************************************************************************
* @file    		dt5m1x26_timer.h
* @brief    	DT5M1x26 series timer drives Include
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
#ifndef __DT5M1x26_TIMER_H__
#define __DT5M1x26_TIMER_H__

#include "DT5M1x26.h"

typedef struct _TIMER_InitStruct
{
	uint8_t  run_mode;
  	uint32_t load_counter;
	uint8_t capture_mode;
	uint8_t ext_clk_div;
} TIMER_InitStruct;

enum
{
	TIMER_MODE_FREERUN,
	TIMER_MODE_DOWNCOUNT,
};

uint8_t Timer_GetIntFlag(TIMER_TypeDef *timer);
uint8_t Timer_ClearIntFlag(TIMER_TypeDef *timer);
uint32_t Timer_Get_CV(TIMER_TypeDef *timer);
void Timer_SetLC(TIMER_TypeDef *timer, uint32_t load_counter);
void Timer_StructInit(TIMER_TypeDef *timer, TIMER_InitStruct *TIMER_Init);
void Timer_DisableInt(TIMER_TypeDef *timer);
void Timer_EnableInt(TIMER_TypeDef *timer);
void Timer_Disable(TIMER_TypeDef *timer);
void Timer_Enable(TIMER_TypeDef *timer);

#endif  //__DT5M1x26_TIMER_H__
