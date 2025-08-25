/*****************************************************************************
* @file    		dt5m1x26_flash.c
* @brief    	DT5M1x26 series flash drives
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
#include "dt5m1x26_flash.h"

/**
 * @brief Erase Sector in Flash Memory
 * @param adr address of Sector
 * @retval None
*/
void Flash_EraseSector(unsigned long adr)
{
	unsigned long tmp;
	tmp = (adr>>9);
	tmp = (((tmp<<15)));

    //*(unsigned long *)0x04000040 = 0x4E05;
    *(unsigned long *)0x04000040 = 0x4E200;    //set sector erase recover time count	
    *(unsigned long *)0x04000044 = 0xC80C350;    //set erase time count and write time count
    //	//sector erase command
    *(unsigned long *)0x0400002C = 0xA0 + tmp;
    *(unsigned long *)0x0400002C = 0x52 + tmp;
    *(unsigned long *)0x0400002C = 0x00; 
}

/**
 * @brief Erase Full Chip in Flash Memory
 * @param None
 * @retval None
*/
void Flash_EraseChip(void)
{
    unsigned char i;
	unsigned long addr = 0;
	unsigned long tmp;

	*(unsigned long *)0x04000040 = 0x4E05;
	*(unsigned long *)0x04000040 |= 0x4E200;    //set sector erase recover time count
	*(unsigned long *)0x04000044 = 0xC80C350;   //set erase time count and write time count
	
	for (i=0;i<128;i++){
		tmp = (addr<<15); 
		*(unsigned long *)0x0400002C = 0xA0 + tmp;
		*(unsigned long *)0x0400002C = 0x52 + tmp;
		addr++;
	}
	*(unsigned long *)0x0400002C = 0x00;
	*(unsigned long *)0x04000040 = 0x4E00;   
}

/**
 * @brief Write a byte Data
 * @param adr address of flash
 * @param dat Data
 * @retval None
*/
void Flash_Write_Byte(unsigned long adr, unsigned long offset, unsigned char dat)
{
    *(unsigned long *)0x04000040 = 0x4E05;      //enable flash write
	*(unsigned long *)0x04000044 = 0x90000 + (0x96<<20);    //set erase time count and write time count
    *(unsigned long *)(adr+offset) = dat;
    *(unsigned long *)0x04000040 = 0x4E00;      //disable flash write
}

/**
 * @brief Read Data from flash
 * @param adr address of data
 * @retval data read from flash
*/
unsigned char Flash_Read_Byte(unsigned long adr, unsigned long offset)
{
    unsigned char dat;
    *(unsigned long *)0x04000040 = 0x4E05;      //enable flash write
	*(unsigned long *)0x04000044 = 0x90000 + (0x96<<20);    //set erase time count and write time count
    dat = (unsigned char)(*(unsigned long *)(adr+offset));
    *(unsigned long *)0x04000040 = 0x4E00;      //disable flash write
    return(dat);
}
/**
 * @brief Write Data into Page
 * @param adr address of Sector
 * @param sz Data Size
 * @param buf Data
 * @retval None
*/
void Flash_Write_buf(unsigned long adr, unsigned long sz, unsigned char *buf)
{
	*(unsigned long *)0x04000040 = 0x4E05;      //enable flash write
	*(unsigned long *)0x04000044 = 0x90000 + (0x96<<20);    //set erase time count and write time count
	while(sz){
		*(unsigned long *)adr = *(unsigned long *)buf;
		adr += 4;
		buf += 4;
		sz -= 4;
	}
	*(unsigned long *)0x04000040 = 0x4E00;      //disable flash write
}
