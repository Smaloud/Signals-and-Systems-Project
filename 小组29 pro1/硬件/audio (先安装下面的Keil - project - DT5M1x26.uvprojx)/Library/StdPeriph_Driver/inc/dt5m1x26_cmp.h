/*****************************************************************************
* @file    		dt5m1x26_cmp.h
* @brief    	DT5M1x26 series cmp drives Include
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
#ifndef __DT5M1x26_CMP_H__
#define __DT5M1x26_CMP_H__

#include "DT5M1x26.h"

void CMP_Init(void);
void CMP_Int_Enalbe(IRQn_Type IRQn);
void CMP_Int_Disable(IRQn_Type IRQn);
uint8_t CMP_Get_Result(void);
#endif //__DT5M1x26_CMP_H__
