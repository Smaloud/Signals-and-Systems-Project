/*****************************************************************************
* @file    		dt5m1x26_adc.c
* @brief    	DT5M1x26 series adc drives
* @version  	V0.1.02
* @date 		  06-29-2023
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
#include "dt5m1x26_adc.h"

/**
  * @brief  Set the time of ADC sample clock low level
  * @note   0 <= tc <= 7
  * @param  tc the time of ADC sample clock low level
  * @retval None
  */
void ADC_TC_Set(uint8_t tc)
{
	assert_param(IS_ADC_TC_VALID(tc));
	ADC->ADC_CON1.bit.tc = tc;
}

/**
  * @brief  Set the time of ADC sample clock high level
  * @note   0 <= tc <= 31
  * @param  ts the time of ADC sample clock high level
  * @retval None
  */
void ADC_TS_Set(uint8_t ts)
{
	assert_param(IS_ADC_TS_VALID(ts));
	ADC->ADC_CON1.bit.ts = ts;
}

/**
  * @brief  ADC Active Enable
  * @param 	None
  * @retval None
  */
void ADC_Active_Enable(void)
{
	ADC->ADC_CON1.bit.cs = 1;
}

/**
  * @brief  ADC Active Disable
  * @param 	None
  * @retval None
  */
void ADC_Active_Disable(void)
{
	ADC->ADC_CON1.bit.cs = 0;
}

/**
  * @brief  ADC Reset Enable
  * @param 	None
  * @retval None
  */
void ADC_Reset_Enable(void)
{
	ADC->ADC_CON1.bit.rst = 1;
}

/**
  * @brief  ADC Reset Disable
  * @param 	None
  * @retval None
  */
void ADC_Reset_Disable(void)
{
	ADC->ADC_CON1.bit.rst = 0;
}
/**
  * @brief  ADC Power Down Enable
  * @param 	None
  * @retval None
  */
void ADC_Power_Down_Enable(void)
{
	ADC->ADC_CON1.bit.pd = 1;
}

/**
  * @brief  ADC Power Down Disable
  * @param 	None
  * @retval None
  */
void ADC_Power_Down_Disable(void)
{
	ADC->ADC_CON1.bit.pd = 0;
}
/**
  * @brief  ADC Channel Select
  * @note   0<=channel<=15
  * @param 	None
  * @retval None
  */
void ADC_Channel_Select(uint8_t ch)
{
	assert_param(IS_ADC_CH_VALID(ch));
	ADC->ADC_CON1.bit.channel = ch;
}

/**
  * @brief  Set GPIO as ADC
  * @note   0<=channel<=15
  * @param 	None
  * @retval None
  */
void ADC_Channel_GPIO_Set(uint8_t ch)
{
	assert_param(IS_ADC_CH_VALID(ch));
  GPIO_MISC->Analog_reg.ADCIOEN = (0x01 << ch);
}

/**
  * @brief  ADC Interrupt Enable
  * @param 	None
  * @retval None
  */
void ADC_EnableInt(void)
{
	NVIC_EnableIRQ(ADC_INT_RISE_IRQn);
}

/**
  * @brief  ADC Interrupt Disable
  * @param 	None
  * @retval None
  */
void ADC_DisableInt(void)
{
	NVIC_DisableIRQ(ADC_INT_RISE_IRQn);
}

/**
  * @brief  Get ADC Result
  * @param 	None
  * @retval ADC Result
  */
uint16_t ADC_Get_Result(void)
{
	return((uint16_t)(ADC->ADC_CON3.bit.data));
}

/**
  * @brief  Start ADC Process11
  * @note   start bit will clear auto after adc get success
  * @param 	None
  * @retval None
  */
void ADC_Start(void)
{
	ADC_Active_Enable();
	ADC->ADC_CON2.bit.start = 1;
	ADC->ADC_CON2.bit.done = 1;
}

/**1
 * 0
  0* @brief  Stop ADC Process
 0 * @note   start bit will clear auto after adc get success
  * @param 	None
  * @retval None
  */
void ADC_Stop(void)
{
	ADC_Active_Disable();
}
/**
  * @brief  Get ADC Done Flag
  * @note done flag bit auto reset after read
  * @param 	None
  * @retval None
  */
uint8_t ADC_Get_DoneFlag(void)
{
	return((uint8_t)(ADC->ADC_CON2.bit.done));
}

/**
  * @brief  ADC Struct Init
  * @param 	ADC_InitStruct
  * @retval None
  */
void ADC_StructInit(ADC_InitTypeDef ADC_InitStruct)
{
  RCC_ADCClk_Int(ADC_InitStruct.clockdiv);
  ADC_Channel_GPIO_Set(ADC_InitStruct.channel);
  ADC_TC_Set(ADC_InitStruct.tc);
	ADC_TS_Set(ADC_InitStruct.ts);
	ADC_Stop();
	ADC_Reset_Disable();
	ADC_Power_Down_Disable();
}

/**
  * @brief  ADC Struct DeInit
  * @param 	ADC_InitStruct
  * @retval None
  */
void ADC_StructDeInit(void)
{
  ADC_Stop();
  ADC_Channel_GPIO_Set(0);
	//ADC_Reset_Enable();
	ADC_Power_Down_Enable();
}
