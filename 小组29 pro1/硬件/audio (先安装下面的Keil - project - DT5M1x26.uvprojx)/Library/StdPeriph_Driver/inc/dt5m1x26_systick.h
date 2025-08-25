/*****************************************************************************
* @file    		dt5m1x26_systick.h
* @brief    	DT5M1x26 series systick drives Include
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
#ifndef __DT5M1x26_SYSTICK_H__
#define __DT5M1x26_SYSTICK_H__

#include "DT5M1x26.h"

void SysTick1ms_Init(void);
void Systick_Int_Handler(void);
uint32_t SysTick_GetTick(void);
void SysTick_RstTick(void);
void Delay_ms(uint32_t delay);
void Delay_us(vs32 n);


#endif   //__DT5M1x26_SYSTICK_H__
