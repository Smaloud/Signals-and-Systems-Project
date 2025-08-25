/*****************************************************************************
* @file    		dt5m1x26_rcc.h
* @brief    	DT5M1x26 series rcc drives Include
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
#ifndef __DT5M1x26_RCC_H__
#define __DT5M1x26_RCC_H__

#include "DT5M1x26.h"

typedef enum{
    RCC_ClockSource_Int = 0x00,   /*interior clock*/
    RCC_ClockSource_Ext           /*external clock*/
}RCC_ClockSource_TypeDef;

typedef enum{
    RCC_RTCClockSource_32K    = 0x00,
    RCC_RTCClockSource_prediv = 0x01
}RCC_RTCClockSource_TypeDef;

#define IS_RCC_CLOCKSOURCE(SOURCE) ((SOURCE) == RCC_ClockSource_Int) || ((SOURCE) == RCC_ClockSource_Ext)


void RCC_ClockSourceConfig(RCC_ClockSource_TypeDef source);
void RCC_AHBClkConfig(uint16_t div);
void RCC_APBUARTClkConfig(uint16_t div);
void RCC_SoundClk_Int(uint16_t div);
void RCC_SoundClk_DeInt(void);
void RCC_PWMClk_Int(uint16_t div);
void RCC_PWMClk_DeInt(void);
void RCC_SPIClk_Int(uint16_t div);
void RCC_SPIClk_DeInt(void);
void RCC_I2CClk_Int(uint16_t div);
void RCC_I2CClk_DeInt(void);
void RCC_Timer0Clk_Int(uint16_t div);
void RCC_Timer0Clk_DeInt(void);
void RCC_Timer1Clk_Int(uint16_t div);
void RCC_Timer1Clk_DeInt(void);
void RCC_UartClk_Int(void);
void RCC_UartClk_DeInt(void);
void RCC_ADCClk_Int(uint16_t div);
void RCC_ADCClk_DeInt(void);
void RCC_WDTClk_Int(void);
void RCC_WDTClk_DeInt(void);
void RCC_RTCClk_Int(void);
void RCC_RTCClk_DeInt(void);
void RCC_AESClk_Init(void);
void RCC_AESClk_DeInit(void);

#endif   //__DT5M1x26_RCC_H__
