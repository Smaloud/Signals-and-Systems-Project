/*****************************************************************************
* @file    		dt5m1x26_aes.h
* @brief    	DT5M1x26 series aes drives Include
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
#ifndef __DT5M1x26_AES_H__
#define __DT5M1x26_AES_H__

#include "DT5M1x26.h"

void AES_round_constants(void);
void AES_Key_Set(uint8_t* dat, uint8_t len);
void AES_PlainText_Set(uint8_t* dat);
void AES_KeyLen(uint16_t len);
void AES_sbox_Set(const uint8_t *aes_sbox, const uint8_t *aes_isbox);
void AES_change(uint8_t* data1, uint8_t flag);

#endif //__DT5M1x26_AES_H__
