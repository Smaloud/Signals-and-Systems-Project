/*****************************************************************************
* @file    		dt5m1x26_gpio.c
* @brief    	DT5M1x26 series GPIO drives
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
#include "dt5m1x26_gpio.h"

/**
  * @brief  Get the interrupt status of GPIO
  * @note   only GPIO0~15 can be used;
  * @note   after read,the status will clear auto
  * @retval Interrupt gpio pin
  */
uint32_t GPIO_GetIntStatus(void)
{
	return(GPIO_MISC->ISR >> 16);
}

/**
  * @brief  Enable the interrupt triggle by GPIO 
  * @note   only GPIO0~15 can be used;
  * @param Pin
  * @retval None
  */
void GPIO_EnableTriggleInt(uint32_t Pin)
{
	assert_param(IS_GPIO_ENABLE_TRIGGLE_INT(Pin));
	GPIO_MISC->IMR |=Pin;
	NVIC_EnableIRQ(GPIO_IRQn);
}

/**
  * @brief  Disable the interrupt triggle by GPIO 
  * @note   only GPIO0~15 can be used;
  * @retval None
  */
void GPIO_DisableTriggleInt(uint32_t Pin)
{
	assert_param(IS_GPIO_ENABLE_TRIGGLE_INT(Pin));
	GPIO_MISC->IMR &= (~Pin);
	NVIC_DisableIRQ(GPIO_IRQn);
}

/**
  * @brief  gpio triggle interrupt edge set
  * @param  GPIO_Pin: pin
  * @param  Triggle_edge Trigger edge
  * @note   only GPIO0~15 can be used;
  * @retval None
  */
void GPIO_SetTriggerEdge(uint32_t Pin, GPIO_Triggle_TypeDef Triggle_edge)
{
	assert_param(IS_GPIO_ENABLE_TRIGGLE_INT(Pin));
	assert_param(IS_GPIO_TRIGGLE_TYPE(Triggle_edge));

	if (Triggle_edge == GPIO_TRIGGER_RISING) GPIO_MISC->IER |= Pin;
	else if (Triggle_edge == GPIO_TRIGGER_FALLING) GPIO_MISC->IER |= (Pin << 16);
	else GPIO_MISC->IER |= (Pin | (Pin << 16));
}

/**
  * @brief  gpio triggle interrupt edge clear
  * @param  GPIO_Pin: pin
  * @param  Triggle_edge Trigger edge
  * @note   only GPIO0~15 can be used;
  * @retval None
  */
void GPIO_ClearTriggerEdge(uint32_t Pin, GPIO_Triggle_TypeDef Triggle_edge)
{
	assert_param(IS_GPIO_ENABLE_TRIGGLE_INT(Pin));
	assert_param(IS_GPIO_TRIGGLE_TYPE(Triggle_edge));
	if (Triggle_edge == GPIO_TRIGGER_RISING) GPIO_MISC->IER &= ~Pin;
	else if (Triggle_edge == GPIO_TRIGGER_FALLING) GPIO_MISC->IER &= ~(Pin<<16);
	else GPIO_MISC->IER &= ~(Pin & Pin<<16);
}

/**
  * @brief  Enable mcu wake up by gpio input.
  * @param  GPIO_Pin: pin to enable 
  * @param  Wakeup_Trigger Trigger type
  * @note   only gpio0~15 can be used;
  * @retval None
  */
void GPIO_EnableWakeup(uint32_t Pin, WakeupTrigger_TypeDef Wakeup_Trigger)
{
	if (Wakeup_Trigger == WAKEUP_Trigger_Edge){
		if (Pin < GPIO_PIN_8) GPIO_MISC->CR |= (Pin << 24);
		else GPIO_MISC->WKE |= (Pin >> 8);
	}
	else{
		GPIO_MISC->WKE |= (Pin << 8);
	}
}

/**
  * @brief  Disable mcu wake up by gpio.
  * @param  GPIO_Pin: pin to disable
  * @note   only gpio0~15 can be used;
  * @retval None
  */
void GPIO_DisableWakeup(uint32_t Pin,WakeupTrigger_TypeDef Wakeup_Trigger)
{
	if (Wakeup_Trigger == WAKEUP_Trigger_Edge){
		if (Pin < GPIO_PIN_8) GPIO_MISC->CR &= ~(Pin << 24);
		else GPIO_MISC->WKE &= ~(Pin >> 8);
	}
	else{
		GPIO_MISC->WKE &= ~(Pin << 8);
	}
}

/**
  * @brief  Allow the interrupt of wake-up by GPIO
  * @note   only GPIO0~15 can be used;
  * @retval None
  */
void GPIO_EnableWakeUpInt(void)
{
	NVIC_EnableIRQ(GPIO_WAKEUP_IRQn);
}

/**
  * @brief  Disable the interrupt of wake-up by GPIO
  * @note   only GPIO0~15 can be used;
  * @retval None
  */
void GPIO_DisableWakeUpInt(void)
{
	NVIC_DisableIRQ(GPIO_WAKEUP_IRQn);
}

/**
  * @brief  GPIO pull up/down enable
  * @note   GPIO13,14,17,18,19,20 can be pull down(not pull up);others can be pull up,not pull down
  * @retval None
  */
void GPIO_PUP_Enable(GPIO_Pin_PUP Pin)
{
	GPIO_MISC->PUE |=Pin;
}

/**
  * @brief  GPIO pull up/down disable
  * @note   GPIO13,14,17,18,19,20 can be pull down(not pull up);others can be pull up,not pull down
  * @retval None
  */
void GPIO_PUP_Disable(GPIO_Pin_PUP Pin)
{
	GPIO_MISC->PUE &=~Pin;
}

/**
  * @brief  Enable GPIO input anti-shake function
  * @note   only GPIO0~15 can be used;
  * @retval None
  */
void GPIO_EnableDebounce(uint32_t Pin)
{
	GPIO_MISC->CR |= (Pin<<8);
}

/**
  * @brief  Disable GPIO input anti-shake function
  * @note   only GPIO0~15 can be used;
  * @retval None
  */
void GPIO_DisableDebounce(uint32_t Pin)
{
	GPIO_MISC->CR &= ~(Pin<<8);
}

/**
  * @brief  Reads the specified output data port bit.
  * @param  GPIOx: where x can be (A, B) to select the GPIO peripheral.
  * @param  GPIO_Pin: Specifies the port bit to read.
  * @retval The output port pin value.
  */
uint8_t GPIO_Pin_ReadBit(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
	uint8_t bitstatus = 0x00;

	if ((GPIOx->DATA & Pin)) bitstatus = TRUE;
	else bitstatus = FALSE;

	return bitstatus;
}

/**
  * @brief  Sets the selected data port bits.
  * @param  GPIOx: where x can be (A, B) to select the GPIO peripheral.  
  * @param  GPIO_Pin: specifies the port bits to be written.
  * @retval None
  */
void GPIO_Pins_Set(GPIO_TypeDef *GPIOx, uint32_t Pins)
{
	GPIOx->DATA |= Pins;
}

/**
  * @brief  Clears the selected data port bits.
  * @param  GPIOx: where x can be (A, B) to select the GPIO peripheral.  
  * @param  GPIO_Pin: specifies the port bits to be written.
  * @retval None
  */
void GPIO_Pins_Reset(GPIO_TypeDef *GPIOx, uint32_t Pins)
{
	GPIOx->DATA &= ~Pins;
}

/**
  * @brief  Initializes the GPIOx peripheral according to the specified 
  *         parameters in the GPIO_InitTypeDef.
  * @param  GPIOx: where x can be (A, B) to select the GPIO peripheral.
  * @note   PIN0~30 is in GPIOA, pin32,pin33 is in GPIOB
  * @param  GPIO_InitTypeDef: pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  * @retval None
  */
void GPIO_StructInit(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitTypeDef)
{
	__IO uint32_t *PUE;
	  /* Check the parameters */
	assert_param(IS_GPIO_PIN(GPIO_InitTypeDef->GPIO_Pin));
	assert_param(IS_GPIO_MODE(GPIO_InitTypeDef->GPIO_Mode));
	assert_param(IS_GPIO_DIRE(GPIO_InitTypeDef->GPIO_Dir));
	assert_param(IS_GPIO_PUPD(GPIO_InitTypeDef->GPIO_PuPd));

	if (GPIO_InitTypeDef->GPIO_Dir == GPIO_DIR_IN) GPIOx->DIR |= (GPIO_InitTypeDef->GPIO_Pin);
	else GPIOx->DIR &= ~(GPIO_InitTypeDef->GPIO_Pin);

	if (GPIO_InitTypeDef->GPIO_Mode == GPIO_MODE_SF) GPIOx->MODE |= (GPIO_InitTypeDef->GPIO_Pin);
	else GPIOx->MODE &= ~(GPIO_InitTypeDef->GPIO_Pin);
	
	if (GPIOx == GPIOA) PUE = &(GPIO_MISC->PUE);
	else PUE = &(GPIO_MISC->PUE2);
		
	if (GPIO_InitTypeDef->GPIO_PuPd == GPIO_PuPd_UP){
		if (IS_GPIO_ENABLE_PU(GPIO_InitTypeDef->GPIO_Pin)) *PUE |= GPIO_InitTypeDef->GPIO_Pin;
	}
	else if (GPIO_InitTypeDef->GPIO_PuPd == GPIO_PuPd_DOWN){
		if (IS_GPIO_ENABLE_PD(GPIO_InitTypeDef->GPIO_Pin)) *PUE |= GPIO_InitTypeDef->GPIO_Pin;
	}
	else{
		*PUE &= ~GPIO_InitTypeDef->GPIO_Pin;
	}
}
