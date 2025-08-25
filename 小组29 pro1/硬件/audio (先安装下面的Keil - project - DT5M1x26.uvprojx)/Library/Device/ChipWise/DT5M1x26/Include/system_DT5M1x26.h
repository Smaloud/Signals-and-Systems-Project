/*****************************************************************************
* @file    		system_DT5m1x26.h
* @brief    	DT5M1x26 series system clock definition file
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
#ifndef __SYSTEM_DT5M1x26_H__
#define __SYSTEM_DT5M1x26_H__

#ifdef __cplusplus
extern "C" {
#endif


	/*----------------------------------------------------------------------------
	  Define SYSCLK
	 *----------------------------------------------------------------------------*/

#define __HXT           (12000000UL)
#define __LXT         	(32768UL)
#define __HIRC12M       (12000000UL)
#define __HIRC16M       (16000000UL)
#define __LIRC        	(10000UL)
#define __HIRC          __HIRC12M
#define __HSI           (__HIRC12M)      /* Factory Default is internal 12MHz */


	extern uint32_t SystemCoreClock;        /*!< System Clock Frequency (Core Clock) */
	extern uint32_t CyclesPerUs;            /*!< Cycles per micro second */

	/**
	 * Update SystemCoreClock variable
	 *
	 * @param  None
	 * @return None
	 *
	 * @brief  Updates the SystemCoreClock with current core Clock
	 *         retrieved from CPU registers.
	 */

	extern void SystemCoreClockUpdate (void);
	extern uint32_t SysGet_PLLClockFreq(void);

#ifdef __cplusplus
}
#endif

#endif  //__SYSTEM_DT5M1x26_H__


