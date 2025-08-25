/*****************************************************************************
* @file    		dt5m1x26_rcc.c
* @brief    	DT5M1x26 series clock drives
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
#include "dt5m1x26_rcc.h"

/**
  * @brief  Clock source select
  * @param  source clock source:RCC_ClockSource_Int or RCC_ClockSource_Ext
  * @retval None
  */
void RCC_ClockSourceConfig(RCC_ClockSource_TypeDef source)
{
    assert_param(IS_RCC_CLOCKSOURCE(source));
    RCC->CR0 &= ~0x01;
    RCC->CR0 &= ~(0x01 << 14);
    RCC->CR0 |= (source << 14);
    RCC->CR0 |= 0x01;
}

/**
  * @brief  AHB clock config
  * @param  div AHB clock division
  * @retval None
  */
void RCC_AHBClkConfig(uint16_t div)
{
    /*close all clock*/
    RCC->CR0 &= ~0x01;
    RCC->AHB_DIV = div;
    RCC->CR0 |= 0x01;
}

/**
  * @brief  APB & UART clock config
  * @param  div AHB & UART clock division(2<=div<=511,default is 4)
  * @retval None
  */
void RCC_APBUARTClkConfig(uint16_t div)
{
    RCC->CR0 &= ~0x01;
    RCC->APB_DIV = div;
    RCC->CR0 |= 0x01;
}

/**
  * @brief  Sound clock initial
  * @param  div Sound clock division(1<=div<=15,default is 1)
  * @retval None
  */
void RCC_SoundClk_Int(uint16_t div)
{
    RCC->SOUND_DIV = div;
    RCC->CR0 |= 0x00008000;
}

/**
  * @brief  Sound clock deinitial
  * @param  none
  * @retval None
  */
void RCC_SoundClk_DeInt(void)
{
    RCC->CR0 &= (~0x00008000);
}

/**
  * @brief  PWM clock initial
  * @param  div PWM clock division(1<=div<=511,default is 8)
  * @retval None
  */
void RCC_PWMClk_Int(uint16_t div)
{
    RCC->PWM_DIV = div;
    RCC->CR0 |= 0x00000002;
}

/**
  * @brief  PWM clock deinitial
  * @param  none
  * @retval None
  */
void RCC_PWMClk_DeInt(void)
{
    RCC->CR0 &= (~0x00000002);
}

/**
  * @brief  SPI clock initial
  * @param  div SPI clock division(2<=div<=511,default is 8)
  * @retval None
  */
void RCC_SPIClk_Int(uint16_t div)
{
	RCC->SIO_DIV = div;
	RCC->CR0 |= 0x00000100;
}

/**
  * @brief  SPI clock deinitial
  * @param  none
  * @retval None
  */
void RCC_SPIClk_DeInt(void)
{
	RCC->CR0 &= (~0x00000100);
}

/**
  * @brief  I2C clock initial
  * @param  div I2C clock division(2<=div<=511,default is 8)
  * @retval None
  */
void RCC_I2CClk_Int(uint16_t div)
{
	RCC->SIO_DIV = div;
	RCC->CR0 |= 0x00000200;
}

/**
  * @brief  I2C clock deinitial
  * @param  none
  * @retval None
  */
void RCC_I2CClk_DeInt(void)
{
	RCC->CR0 &= (~0x00000200);
}

/**
  * @brief  TIMER0 clock initial
  * @param  div TIMER1 clock division(2<=div<=511,default is 8)
  * @retval None
  */
void RCC_Timer0Clk_Int(uint16_t div)
{
	RCC->TIM_DIV = div;
	RCC->CR0 |= 0x00000008;
}

/**
  * @brief  TIMER1 clock deinitial
  * @param  none
  * @retval None
  */
void RCC_Timer0Clk_DeInt(void)
{
	RCC->CR0 &= (~0x00000008);
}

/**
  * @brief  TIMER1 clock initial
  * @param  div TIMER2 clock division(2<=div<=511,default is 8)
  * @retval None
  */
void RCC_Timer1Clk_Int(uint16_t div)
{
	RCC->CP_DIV = div;
	RCC->CR0 |= 0x00000020;
}

/**
  * @brief  TIMER2 clock deinitial
  * @param  none
  * @retval None
  */
void RCC_Timer1Clk_DeInt(void)
{
	RCC->CR0 &= (~0x00000020);
}

/**
  * @brief  UART clock initial
  * @param  none
  * @retval None
  */
void RCC_UartClk_Int(void)
{
    RCC->CR0 |= 0x00000400;
}
/**
  * @brief  UART clock deinitial
  * @param  none
  * @retval None
  */
void RCC_UartClk_DeInt(void)
{
    RCC->CR0 &= (~0x00000400);
}

/**
  * @brief  ADC clock initial
  * @param  div ADC clock division(1<=div<=15,default is 4)
  * @retval None
  */
void RCC_ADCClk_Int(uint16_t div)
{
	 RCC->ADC_DIV = div;
	 RCC->CR0 |= 0x00000080;
}

/**
  * @brief  ADC clock deinitial
  * @param  none
  * @retval None
  */
void RCC_ADCClk_DeInt(void)
{
    RCC->CR0 &= (~0x00000080);
}

/**
  * @brief  WDT clock initial
  * @note  WDT clock is used RTC2
  * @retval None
  */
void RCC_WDTClk_Int(void)
{
	 RCC->CR0 |= 0x00002000;
}

/**
  * @brief  WDT clock deinitial
  * @param  none
  * @retval None
  */
void RCC_WDTClk_DeInt(void)
{
	 RCC->CR0 &= (~0x00002000);
}

/**
  * @brief  RTC clock initial
  * @param  div RTC clock division(2<=div<=65535,default is 32768)
  * @retval None
  */
void RCC_RTCClk_Int(void)
{
	RCC->CR0 |= 0x00001000;
}

/**
  * @brief  RTC clock deinitial
  * @param  none
  * @retval None
  */
void RCC_RTCClk_DeInt(void)
{
	RCC->CR0 &= (~0x00001000);
}

/**
  * @brief  AES clock deinitial
  * @param  none
  * @retval None
  */
void RCC_AESClk_Init(void)
{
  RCC->CR0 |= (0x00000800);
}

/**
  * @brief  AES clock deinitial
  * @param  none
  * @retval None
  */
void RCC_AESClk_DeInit(void)
{
  RCC->CR0 &= (~0x00000800);
}
