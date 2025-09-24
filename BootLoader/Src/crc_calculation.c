/*
 * crc_calculation.c
 *
 *  Created on: Sep 16, 2025
 *      Author: Sujith S Babu
 */


#include "crc_calculation.h"


uint32_t crc_calculation_hw(uint8_t* data, uint32_t len)
{
	CRC_CLK_EN();
	CRC->CRC_CR = 1;

	while(len >= 4)
	{
		uint32_t word = ((data[0]) | (data[1]<<8) | (data[2]<<16) | (data[3]<<24));
		CRC->CRC_DR = word;
		data += 4;
		len  -= 4;
	}

	if(len > 0)
	{
		uint32_t word = 0;
		for(uint32_t i=0; i< len ;i++)
		{
			word |= (data[i] << (8*i));
		}
		CRC->CRC_DR = word;
	}

	return CRC->CRC_DR;
}
