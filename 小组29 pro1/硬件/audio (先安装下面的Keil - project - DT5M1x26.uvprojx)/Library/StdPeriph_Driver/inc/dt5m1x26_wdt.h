/*****************************************************************************
* @file    		dt5m1x26_wdt.h
* @brief    	DT5M1x26 series wdt drives Include
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
#ifndef __DT5M1x26_WDT_H__
#define __DT5M1x26_WDT_H__

#include "DT5M1x26.h"

typedef struct 
{
    uint32_t load_counter;
    uint32_t match_counter;
	uint8_t  wrap_en;	
	uint8_t  reset_en;
} WDT_InitTypeDef;

uint32_t WDT_GetIntFlag(void);
uint32_t WDT_ClearIntFlag(void);
void WDT_EnableInt(void);
void WDT_DisableInt(void);
void WDT_Enable(void);
void WDT_Disable(void);
void WDT_StructInit(WDT_InitTypeDef *WDT_Init);
void WDT_SetCLR(uint32_t load_counter);
void WDT_SetCMR(uint32_t match_counter);
uint32_t WDT_Get_CCVR(void);
void WDT_Refesh(void);


#endif  //__DT5M1x26_WDT_H__
