/*****************************************************************************
* @file    		dt5m1x26_cmp.c
* @brief    	DT5M1x26 series cmp drives
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
#include "dt5m1x26_cmp.h"

void CMP_Init(void)
{
    GPIO_InitTypeDef  GPIO_Init = { 0 };
    GPIO_Init.GPIO_Pin  = GPIO_PIN_2;
    GPIO_Init.GPIO_Dir  = GPIO_DIR_OUT;
    GPIO_Init.GPIO_Mode = GPIO_MODE_SF;
    GPIO_Init.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_StructInit(GPIOA, &GPIO_Init);
    GPIO_Pins_Reset(GPIOA,GPIO_PIN_2);

    GPIO_Init.GPIO_Pin  = GPIO_PIN_32|GPIO_PIN_33;
    GPIO_Init.GPIO_Dir  = GPIO_DIR_IN;
    GPIO_Init.GPIO_Mode = GPIO_MODE_SF;
    GPIO_Init.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_StructInit(GPIOB, &GPIO_Init);

    GPIO_MISC->Analog_reg.CMPINNEN = 1;
    GPIO_MISC->Analog_reg.CMPINPEN = 1;
    CMP->PWD      = 0;
    CMP->PROG     = 0;
    CMP->VREF_SWT = 1;   //1:Switch INN input signal 0: from pad 1:1.0V
    CMP->SPEED    = 0;
    //CMP_Int_Enalbe(CMP_OUT_RISE_IRQn);
}

/**
  * @brief  Enable Interrupt of CMP
  * @param  IRQn CMP_OUT_FALL_IRQn or CMP_OUT_RISE_IRQn which is falling/rising edge interrupt
  * @retval None
  */
void CMP_Int_Enalbe(IRQn_Type IRQn)
{
	NVIC_EnableIRQ(IRQn); //rising edge interrupt
  //*(vu32*)(0xE000E100ul)=0x800;
}

/**
  * @brief  Disable Interrupt of CMP
  * @param  IRQn CMP_OUT_FALL_IRQn or CMP_OUT_RISE_IRQn which is falling/rising edge interrupt
  * @retval None
  */
void CMP_Int_Disable(IRQn_Type IRQn)
{
	NVIC_DisableIRQ(IRQn); //rising edge interrupt
}

/**
  * @brief  GET REsult of CMP
  * @param  None
  * @retval Result
  */
uint8_t CMP_Get_Result(void)
{
	return(CMP->RESULT);
}