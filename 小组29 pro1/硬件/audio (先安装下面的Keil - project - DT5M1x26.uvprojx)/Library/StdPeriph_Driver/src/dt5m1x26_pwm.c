/*****************************************************************************
* @file    		dt5m1x26_pwm.c
* @brief    	DT5M1x26 series PWM drives
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
#include "dt5m1x26_pwm.h"

/**
  * @brief  Set PWM Frequent
  * @param  PWM_Channel
  * @param  freq_count
  * @note   PWM clock Frequent equal (17Mhz/1000/div)
  * @note   PWM frequent equal (max_count / (PWM clock Frequent(khz)))
  * @retval None
  */
void PWM_Change_Freq(uint8_t PWM_Channel,uint32_t freq_count)
{
	if (PWM_Channel == PWM_Channel1) PWM->MC1 = freq_count;
	if (PWM_Channel == PWM_Channel2) PWM->MC2 = freq_count;
	if (PWM_Channel == PWM_Channel3) PWM->MC3 = freq_count;
	if (PWM_Channel == PWM_Channel4) PWM->MC4 = freq_count;
	if (PWM_Channel == PWM_Channel5) PWM->MC5 = freq_count;
	if (PWM_Channel == PWM_Channel6) PWM->MC6 = freq_count;
}

/**
  * @brief  Set PWM duty(low level)
  * @param  PWM_Channel
  * @param  duty
  * @retval None
  */
uint8_t PWM_Change_Duty_cycle(uint8_t PWM_Channel,uint32_t duty)
{
	if (PWM_Channel == PWM_Channel1 && (PWM->MC1 >= duty)) PWM->DC1 = duty;
	if (PWM_Channel == PWM_Channel2 && (PWM->MC2 >= duty)) PWM->DC2 = duty;
	if (PWM_Channel == PWM_Channel3 && (PWM->MC3 >= duty)) PWM->DC3 = duty;
	if (PWM_Channel == PWM_Channel4 && (PWM->MC4 >= duty)) PWM->DC4 = duty;
	if (PWM_Channel == PWM_Channel5 && (PWM->MC5 >= duty)) PWM->DC5 = duty;
	if (PWM_Channel == PWM_Channel6 && (PWM->MC6 >= duty)) PWM->DC6 = duty;
	return(1);
}

/**
  * @brief  Stop PWM Channel
  * @param  PWM_Channel
  * @retval None
  */
void PWM_Stop(uint32_t PWM_Channel)
{
 PWM->CR &= (~PWM_Channel);
}

/**
  * @brief  Start PWM Channel
  * @param  PWM_Channel
  * @retval None
  */
void PWM_Start(uint32_t PWM_Channel)
{
 PWM->CR |= (PWM_Channel);
}

/**
  * @brief  PWM Struct init
  * @param  Initstruct
  * @note   PWM clock Frequent equal (16Mhz/1000/div)
  * @note   PWM frequent equal (max_count / (PWM clock Frequent(khz)))
  * @note   PWM dead zone range 0~7
  * @retval None
  */
void PWM_StructInit(PWM_InitStrcut *Initstruct)
{
	uint32_t reg_val;

	reg_val = PWM->CR;
	if (Initstruct->pwm_select & PWM_Channel1){
		PWM->DC1 = Initstruct->duty_cycle_num;
		PWM->MC1 = Initstruct->max_count;

		// reg_val |= PWM_CR_PWM1_EN_Msk;
		if (Initstruct->deadzone_en){
			reg_val |= PWM_CR_DEAD_ZONE1_EN_Msk;
			reg_val |= (Initstruct->deadzone_count << 16);
		}
		else{
			reg_val &= ~PWM_CR_DEAD_ZONE1_EN_Msk;
			reg_val &= ~(Initstruct->deadzone_count << 16);
		}
	}

	if (Initstruct->pwm_select & PWM_Channel2){
		PWM->DC2 = Initstruct->duty_cycle_num;
		PWM->MC2 = Initstruct->max_count;
		// reg_val |= PWM_CR_PWM2_EN_Msk;
		if (Initstruct->deadzone_en){
			reg_val |= PWM_CR_DEAD_ZONE1_EN_Msk;
			reg_val |= (Initstruct->deadzone_count << 16);
		}
		else{
			reg_val &= ~PWM_CR_DEAD_ZONE1_EN_Msk;
			reg_val &= ~(Initstruct->deadzone_count << 16);
		}
	}

	if (Initstruct->pwm_select & PWM_Channel3){
		PWM->DC3 = Initstruct->duty_cycle_num;
		PWM->MC3 = Initstruct->max_count;
		// reg_val |= PWM_CR_PWM3_EN_Msk;
		if (Initstruct->deadzone_en){
			reg_val |= PWM_CR_DEAD_ZONE2_EN_Msk;
			reg_val |= (Initstruct->deadzone_count << 24);
		}
		else{
			reg_val &= ~PWM_CR_DEAD_ZONE2_EN_Msk;
			reg_val &= ~(Initstruct->deadzone_count << 24);
		}
	}

	if (Initstruct->pwm_select & PWM_Channel4){
		PWM->DC4 = Initstruct->duty_cycle_num;
		PWM->MC4 = Initstruct->max_count;
		// reg_val |= PWM_CR_PWM4_EN_Msk;
		if (Initstruct->deadzone_en){
			reg_val |=PWM_CR_DEAD_ZONE2_EN_Msk;
			reg_val |= (Initstruct->deadzone_count << 24);
		}
		else{
			reg_val &= ~PWM_CR_DEAD_ZONE2_EN_Msk;
			reg_val &= ~(Initstruct->deadzone_count << 24);
		}
	}

	if (Initstruct->pwm_select & PWM_Channel5){
		PWM->DC5 = Initstruct->duty_cycle_num;
		PWM->MC5 = Initstruct->max_count;
		// reg_val |= PWM_CR_PWM5_EN_Msk;
		if (Initstruct->deadzone_en){
			reg_val |= PWM_CR_DEAD_ZONE3_EN_Msk;
			reg_val |= (Initstruct->deadzone_count << 28);
		}
		else{
			reg_val &= ~PWM_CR_DEAD_ZONE3_EN_Msk;
			reg_val &= ~(Initstruct->deadzone_count << 28);

		}
	}

	if (Initstruct->pwm_select & PWM_Channel6){
		PWM->DC6 = Initstruct->duty_cycle_num;
		PWM->MC6 = Initstruct->max_count;
		// reg_val |= PWM_CR_PWM6_EN_Msk;
		if (Initstruct->deadzone_en){
			reg_val |= PWM_CR_DEAD_ZONE3_EN_Msk;
			reg_val |= (Initstruct->deadzone_count << 28);
		}
		else{
			reg_val &= ~PWM_CR_DEAD_ZONE3_EN_Msk;
			reg_val &= ~(Initstruct->deadzone_count << 28);
		}
	}
	if (Initstruct->pwm_pair_select & PWM_Pair_12) reg_val |= PWM_CR_PAIR12_EN_Msk;
	if (Initstruct->pwm_pair_select & PWM_Pair_34) reg_val |= PWM_CR_PAIR34_EN_Msk;
	if (Initstruct->pwm_pair_select & PWM_Pair_56) reg_val |= PWM_CR_PAIR56_EN_Msk;

	PWM->CR = reg_val;
}
