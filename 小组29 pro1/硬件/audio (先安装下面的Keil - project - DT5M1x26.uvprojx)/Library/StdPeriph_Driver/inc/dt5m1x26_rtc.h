/*****************************************************************************
* @file    		dt5m1x26_rtc.h
* @brief    	DT5M1x26 series rtc drives Include
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
#ifndef __DT5M1x26_RTC_H__
#define __DT5M1x26_RTC_H__

#include "DT5M1x26.h"

typedef struct
{
    uint32_t load_counter;
    uint32_t match_counter;
	uint8_t  wrap_en;
} RTC_InitTypeDef;

uint32_t RTC_GetIntFlag(void);
uint32_t RTC_ClearIntFlag(void);
void RTC_EnableInt(void);
void RTC_DisableInt(void);
void RTC_Enable(void);
void RTC_Disable(void);
void RTC_StructInit(RTC_InitTypeDef *Initstruct);
void RTC_SetCLR(uint32_t load_counter);
void RTC_SetCMR(uint32_t match_counter);
uint32_t RTC_Get_CLR(void);
uint32_t RTC_Get_CMR(void);
uint32_t RTC_Get_CCVR(void);

#endif  //__DT5M1x26_RTC_H__
