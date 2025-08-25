/*****************************************************************************
* @file    		dt5m1x26_audio.c
* @brief    	DT5M1x26 series audio drives
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
#include "dt5m1x26_audio.h"

void Sound_ClearInt(void)
{
    SOUND->EOFI = 1;
}

uint8_t Sound_GetInt(void)
{
    return (SOUND->SR & BIT3);
}

uint8_t Sound_GetFifoPointer(void)
{
    return (SOUND->SR & BIT1);
}

void Sound_EnableInt(void)
{
    NVIC_EnableIRQ(SOUND_IRQn);
}

void Sound_DisableInt(void)
{
    NVIC_DisableIRQ(SOUND_IRQn);
}

//���ò����� AUDIO_REG2 bit13~0
//10MHz/x = Fs ==> x=10MHz / Fs  eg. Fs=8000Hz x=1250
void Sound_StructInit(Sound_InitStruct *Initstruct)
{
    uint32_t reg_val = 0;

    reg_val = Initstruct->sample_rate;

    if(Initstruct->unsigne_en){
        reg_val |= SOUND_CR_USIGH_EN_Msk;
    }
    else{
        reg_val &= ~SOUND_CR_USIGH_EN_Msk;
    }
    if(Initstruct->sound_format == SOUND_FORMAT_ADPCM){
        reg_val |= SOUND_CR_ADPCM_EN_Msk;
        reg_val |= SOUND_CR_USIGH_EN_Msk;
    }
    else
    {
        reg_val &= ~SOUND_CR_ADPCM_EN_Msk;
    }

    SOUND->CR = reg_val;
    SOUND->PSV = Initstruct->pcm_frist_value;
}
