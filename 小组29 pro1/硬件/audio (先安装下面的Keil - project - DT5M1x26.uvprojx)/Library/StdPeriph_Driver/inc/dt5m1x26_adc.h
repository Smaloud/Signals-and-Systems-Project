/*****************************************************************************
* @file    		dt5m1x26_adc.h
* @brief    	DT5M1x26 series adc drives Include
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
#ifndef __DT5M1x26_ADC_H__
#define __DT5M1x26_ADC_H__

#include "DT5M1x26.h"

typedef enum {
    ADC_ChANNEL0  = 0x00,
    ADC_ChANNEL1  = 0x01,
    ADC_ChANNEL2  = 0x02,
    ADC_ChANNEL3  = 0x03,
    ADC_ChANNEL4  = 0x04,
    ADC_ChANNEL5  = 0x05,
    ADC_ChANNEL6  = 0x06,
    ADC_ChANNEL7  = 0x07,
    ADC_ChANNEL8  = 0x08,
    ADC_ChANNEL9  = 0x09,
    ADC_ChANNEL10 = 0x0A,
    ADC_ChANNEL11 = 0x0B,
    ADC_ChANNEL12 = 0x0C,
    ADC_ChANNEL13 = 0x0D,
    ADC_ChANNEL14 = 0x0E,
    ADC_ChANNEL15 = 0x0F
}ADC_CHANNEL;

typedef struct{
    uint16_t clockdiv;
    uint32_t channel;
    uint8_t tc;
    uint8_t ts;
}ADC_InitTypeDef;

#define IS_ADC_TC_VALID(TC) (((TC) < 8)?1:0)	
#define IS_ADC_TS_VALID(TS) (((TS) < 32)?1:0)
#define IS_ADC_CH_VALID(CH) (((CH) < 16)?1:0)


void ADC_TC_Set(uint8_t tc);
void ADC_TS_Set(uint8_t ts);
void ADC_Active_Enable(void);
void ADC_Active_Disable(void);
void ADC_Reset_Enable(void);
void ADC_Reset_Disable(void);
void ADC_Power_Down_Enable(void);
void ADC_Power_Down_Disable(void);
void ADC_Channel_Select(uint8_t ch);
void ADC_Channel_GPIO_Set(uint8_t ch);
void ADC_EnableInt(void);
void ADC_DisableInt(void);
uint16_t ADC_Get_Result(void);
void ADC_Start(void);
void ADC_Stop(void);
uint8_t ADC_Get_DoneFlag(void);
void ADC_StructInit(ADC_InitTypeDef ADC_InitStruct);
void ADC_StructDeInit(void);
#endif   //__DT5M1x26_ADC_H__
