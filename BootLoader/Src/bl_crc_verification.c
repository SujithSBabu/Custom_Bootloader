/*
 * bl_crc_verification.c
 *
 *  Created on: Sep 17, 2025
 *      Author: Sujith S Babu
 */

#include "bl_crc_verification.h"

uint8_t bl_crc_verify(volatile uint8_t* packet_Buffer)
{
    uint8_t total_len = 1 + packet_Buffer[0];
    uint32_t CRC_Received = (packet_Buffer[total_len - 4]) |
                            (packet_Buffer[total_len - 3] << 8) |
                            (packet_Buffer[total_len - 2] << 16) |
                            (packet_Buffer[total_len - 1] << 24);


	uint32_t crc_input_len = packet_Buffer[0] - 4;

	uint32_t crc_computed = crc_calculation_hw(&packet_Buffer[1], crc_input_len);

	if(crc_computed == CRC_Received)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
