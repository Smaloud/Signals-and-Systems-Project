/*****************************************************************************
* @file    		dt5m1x26_aes.c
* @brief    	DT5M1x26 series aes drives
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
#include "dt5m1x26_aes.h"


/**
  * @brief  input round constant for key expansion
  * @param  None
  * @retval None
  * @note   ROUND CONSTANTS : 0x08040201 080402010 ff6C361B
  */
void AES_round_constants(void)
{
    AES->AES_ROUNDCONST.constant1 = 0x08040201;
    AES->AES_ROUNDCONST.constant2 = 0x80402010;
    AES->AES_ROUNDCONST.constant3 = 0xff6C361B;
}

/**
  * @brief  AES Key set
  * @param  dat key buffer
  * @param  len key length
  * @retval None
  */
void AES_Key_Set(uint8_t* dat, uint8_t len)
{
	uint8_t i;
	uint32_t tmp;
	uint8_t tmp0, tmp1, tmp2, tmp3;

	for (i = 0; i < len; i = i + 4){
		tmp0 = dat[i + 0];
		tmp1 = dat[i + 1];
		tmp2 = dat[i + 2];
		tmp3 = dat[i + 3];
		tmp = (tmp0 << 24) | (tmp1 << 16) | (tmp2 << 8) | tmp3;
		*(uint32_t*)(&(AES->AES_KEY.key1) + i) = tmp;
	}
}

/**
  * @brief  AES PlainText set
  * @param  dat PlainText buffer
  * @retval None
  */
void AES_PlainText_Set(uint8_t* dat)
{
	uint8_t i;
	uint32_t tmp;
	uint8_t tmp0, tmp1, tmp2, tmp3;
	for (i = 0; i < 16; i = i + 4){
		tmp0 = dat[i + 0];
		tmp1 = dat[i + 1];
		tmp2 = dat[i + 2];
		tmp3 = dat[i + 3];
		tmp = (tmp0 << 24) | (tmp1 << 16) | (tmp2 << 8) | tmp3;
		*(uint32_t*)(&(AES->AES_PLAINTEXT.text1) + i) = tmp;
	}
}

/**
  * @brief  AES Key length set
  * @param  len key length
  * @retval None
  */
void AES_KeyLen(uint16_t len)
{
	switch (len){
        case 256:{
            AES->key_len = 0x02;        //set key length =256 bit
            break;
        }
        case 192:{
            AES->key_len = 0x01;        //set key length =192 bit
            break;
        }
        case 128:{
            AES->key_len = 0x00;        //set key length = 128 bit
            break;
        }
        default:{
            AES->key_len = 0x00;        //set key length = 128 bit
            break;
        }
    }
}

/**
  * @brief  AES Sbox Space Set
  * @param  aes_sbox sbox buffer
  * @param  aes_isbox isbox buffer
  * @retval None
  */
void AES_sbox_Set(const uint8_t *aes_sbox,const uint8_t *aes_isbox)
{
	uint8_t i, j;
	uint32_t temp0, temp1, temp2, temp3;

	i = 0;
	for (j = 0; j < 64; j = j + 1){
		temp0 = aes_sbox[i];
		temp1 = aes_sbox[i + 1];
		temp2 = aes_sbox[i + 2];
		temp3 = aes_sbox[i + 3];
		*(uint32_t*)(0x03001C00ul + i) = temp0 | temp1 << 8 | temp2 << 16 | temp3 << 24;
		i = i + 4;
	}
	/*input decry sbox*/
	i = 0;
	for (j = 0; j < 64; j = j + 1){
		temp0 = aes_isbox[i];
		temp1 = aes_isbox[i + 1];
		temp2 = aes_isbox[i + 2];
		temp3 = aes_isbox[i + 3];
		*(uint32_t*)(0x03001E00ul + i) = temp0 | temp1 << 8 | temp2 << 16 | temp3 << 24;
		i = i + 4;
	}
}


void AES_change(uint8_t* data1, uint8_t flag)  // flag=1: encryption      flag=0: decryption
{
	uint8_t  i;
	uint32_t key_ready;
	uint32_t data_ready;
	uint32_t data_encrypted[4];

	key_ready = 0;
	data_ready = 0;

	/*set control bit*/
	AES->aes_mem_clock_en = 0x80000080; //start key expansion
	/*read status register and check key expansion done*/
	while (1){
		key_ready = AES->AES_PLAINTEXT.text1;
		if (key_ready & 0x01) break;
	}
	if (flag) AES->aes_mem_clock_en = 0x80000081;	//start data encryption
	else AES->aes_mem_clock_en = 0x80000083;	//start data decryption

	/**read status register and check data encryption/decryption done**/
	while (1){
		data_ready = AES->AES_PLAINTEXT.text1;
		if (data_ready & 0x2) break;
	}

	AES->aes_mem_clock_en = AES->aes_mem_clock_en | 0x08;
	AES->aes_mem_clock_en = AES->aes_mem_clock_en & 0xf7;
	data_encrypted[0] = AES->AES_KEY.key1;
	data_encrypted[1] = AES->AES_KEY.key2;
	data_encrypted[2] = AES->AES_KEY.key3;
	data_encrypted[3] = AES->AES_KEY.key4;
	AES->aes_mem_clock_en = 0x00;

	for (i = 0; i < 4; i++){
		data1[i * 4 + 0] = (data_encrypted[i] >> 24) & 0xff;
		data1[i * 4 + 1] = (data_encrypted[i] >> 16) & 0xff;
		data1[i * 4 + 2] = (data_encrypted[i] >> 8) & 0xff;
		data1[i * 4 + 3] = (data_encrypted[i] >> 0) & 0xff;
	}
}
