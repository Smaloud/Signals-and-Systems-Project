/*****************************************************************************
* @file    		system_DT5M1x26.c
* @brief    	DT5M8036 series system clock init code and assert handler
* @version  	V0.1.02
* @date 		 06-29-2023
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
#include <stdint.h>
#include "DT5M1x26.h"


/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock  = __HSI;              /*!< System Clock Frequency (Core Clock) */
uint32_t CyclesPerUs      = (__HSI / 1000000);  /*!< Cycles per micro second */

/**
  * @brief  Calculate current PLL clock frequency.
  * @param  None.
  * @return PLL clock frequency. The clock UNIT is in Hz.
  */
uint32_t SysGet_PLLClockFreq(void)
{
	return 0;
}


/**
  * @brief  Get current HCLK clock frequency.
  * @param  None.
  * @return HCLK clock frequency. The clock UNIT is in Hz.
  */
uint32_t SysGet_HCLKFreq(void)
{
	return (0);
}


/**
  * @brief  This function is used to update the variable SystemCoreClock
  *   and must be called whenever the core clock is changed.
  * @param  None.
  * @retval None.
  */

void SystemCoreClockUpdate (void)
{

}

void SystemInit (void)
{

}
#if USE_ASSERT

/**
 * @brief      Assert Error Message
 *
 * @param[in]  file  the source file name
 * @param[in]  line  line number
 *
 * @return     None
 *
 * @details    The function prints the source file name and line number where
 *             the ASSERT_PARAM() error occurs, and then stops in an infinite loop.
 */
void AssertError(uint8_t *file, uint32_t line)
{

	printf("[%s] line %d : wrong parameters.\r\n", file, line);

	/* Infinite loop */
	while (1) ;
}
#endif

/***Copyright (C) 2022 Fujian Dongwei Semiconductor Technology Corp. ***/
