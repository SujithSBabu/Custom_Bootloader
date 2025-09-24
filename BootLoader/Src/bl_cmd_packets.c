/*
 * bl_cmd_packets.c
 *
 *  Created on: Sep 16, 2025
 *      Author: Sujith S Babu
 */

#include "bl_cmd_packets.h"
#include "crc_calculation.h"
#include "serailize_packets.h"
#include "bootloader.h"

//bl_packet_struct packet;
void build_bl_packets(uint8_t cmd)
{
	bl_packet_struct packet = {0};
	switch(cmd)
     {
        case '1':
        {
        	packet.length_to_follow = 0x5;
        	packet.cmd_code         = BL_GET_VER;
        	uint32_t crc_value      = crc_calculation_hw(&packet.cmd_code, 1);
            packet.crc[0]           = (uint8_t) (crc_value & 0xFF);
        	packet.crc[1]           = (uint8_t) ((crc_value >> 8)  & 0xFF);
        	packet.crc[2]           = (uint8_t) ((crc_value >> 16) & 0xFF);
        	packet.crc[3]           = (uint8_t) ((crc_value >> 24) & 0xFF);


            serialize_packet(&packet);
    	    break;

        }

        case '2':
		{
			packet.length_to_follow = 0x5;
			packet.cmd_code         = BL_GET_HELP;
			uint32_t crc_value      = crc_calculation_hw(&packet.cmd_code, 1);
			packet.crc[0]           = (uint8_t) (crc_value & 0xFF);
			packet.crc[1]           = (uint8_t) ((crc_value >> 8)  & 0xFF);
			packet.crc[2]           = (uint8_t) ((crc_value >> 16) & 0xFF);
			packet.crc[3]           = (uint8_t) ((crc_value >> 24) & 0xFF);


			serialize_packet(&packet);
			break;

		}

        case '3':
		{
			packet.length_to_follow = 0x5;
			packet.cmd_code         = BL_GET_CID;
			uint32_t crc_value      = crc_calculation_hw(&packet.cmd_code, 1);
			packet.crc[0]           = (uint8_t) (crc_value & 0xFF);
			packet.crc[1]           = (uint8_t) ((crc_value >> 8)  & 0xFF);
			packet.crc[2]           = (uint8_t) ((crc_value >> 16) & 0xFF);
			packet.crc[3]           = (uint8_t) ((crc_value >> 24) & 0xFF);


			serialize_packet(&packet);
			break;

		}


     }
}
