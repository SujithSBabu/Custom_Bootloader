/*
 * bl_cmd_packets.h
 *
 *  Created on: Sep 16, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_BL_CMD_PACKETS_H_
#define INC_BL_CMD_PACKETS_H_

#include "stm32f407_xx_MemMap.h"

void build_bl_packets(uint8_t);


typedef struct
{
	uint8_t length_to_follow;
	uint8_t cmd_code;
	uint8_t crc[4];
}bl_packet_struct;

#endif /* INC_BL_CMD_PACKETS_H_ */
