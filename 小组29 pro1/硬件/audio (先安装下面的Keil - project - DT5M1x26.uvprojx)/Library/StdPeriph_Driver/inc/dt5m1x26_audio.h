/*****************************************************************************
* @file    		dt5m1x26_audio.h
* @brief    	DT5M1x26 series audio drives Include
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
#ifndef __DT5M1x26_AUDIO_H__
#define __DT5M1x26_AUDIO_H__

#include "DT5M1x26.h"

#define SOUND_FORMAT_PCM		0
#define SOUND_FORMAT_ADPCM		1

#define SOUND_SAMPLE_RATE_8K	(1250UL)
#define SOUND_SAMPLE_RATE_16K	(625UL)
#define SOUND_SAMPLE_RATE_44K	(227UL)

typedef struct _Sound_InitStruct
{
    uint8_t unsigne_en;
    uint8_t sound_format;
    uint16_t sample_rate;
    uint32_t pcm_frist_value;

} Sound_InitStruct;

__INLINE void Sound_Fill_FIFO0(uint32_t dat)
{
    SOUND->FIFO0 = dat;
}

__INLINE void Sound_Fill_FIFO1(uint32_t dat)
{
    SOUND->FIFO1 = dat;
}

void Sound_ClearInt(void);
uint8_t Sound_GetInt(void);
uint8_t Sound_GetFifoPointer(void);
void Sound_EnableInt(void);
void Sound_DisableInt(void);
void Sound_StructInit(Sound_InitStruct *Initstruct);
void Sound_Enable(void);
void Sound_Disable(void);

#endif    //__DT5M1x26_AUDIO_H__
