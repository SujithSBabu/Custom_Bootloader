/*
 * serailize_packets.h
 *
 *  Created on: Sep 16, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_SERAILIZE_PACKETS_H_
#define INC_SERAILIZE_PACKETS_H_
#include "stm32f407_xx_MemMap.h"
#include "bl_cmd_packets.h"

extern volatile uint8_t tx_packet_buffer[6];
extern volatile uint32_t  tx_index;
extern volatile uint32_t  tx_length;

void serialize_packet(bl_packet_struct*);


#endif /* INC_SERAILIZE_PACKETS_H_ */
