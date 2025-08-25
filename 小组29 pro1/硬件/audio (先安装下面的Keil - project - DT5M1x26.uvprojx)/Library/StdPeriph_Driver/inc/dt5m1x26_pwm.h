/*****************************************************************************
* @file    		dt5m1x26_pwm.h
* @brief    	DT5M1x26 series pwm drives Include
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
#ifndef __DT5M1x26_PWM_H__
#define __DT5M1x26_PWM_H__

#include "DT5M1x26.h"

typedef struct _PWM_InitStrcut
{
	uint16_t duty_cycle_num;
	uint16_t max_count;
	uint8_t  deadzone_count;
	uint8_t  deadzone_en;
	uint8_t  pwm_select;
	uint8_t  pwm_pair_select;
} PWM_InitStrcut;

typedef enum{
	PWM_Channel1 = 0x01,
	PWM_Channel2 = 0x02,
	PWM_Channel3 = 0x04,
	PWM_Channel4 = 0x08,
	PWM_Channel5 = 0x10,
	PWM_Channel6 = 0x20
}PWM_CHANNEL_Typedef;

typedef enum{
	PWM_Pair_12,
	PWM_Pair_34,
	PWM_Pair_56
}PWM_PAIR_TypeDef;

void PWM_Start(uint32_t PWM_Channel);
void PWM_StructInit(PWM_InitStrcut *Initstruct);
uint8_t PWM_Change_Duty_cycle(uint8_t PWM_Channel,uint32_t duty);
void PWM_Change_Freq(uint8_t PWM_Channel,uint32_t freq_count);


#endif   //__DT5M1x26_PWM_H__
