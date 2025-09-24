/*
 * bl_cmd_handling.h
 *
 *  Created on: Sep 17, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_BL_CMD_HANDLING_H_
#define INC_BL_CMD_HANDLING_H_

#include "stm32f407_xx_MemMap.h"
#include "bl_crc_verification.h"
#include "bl_ack_nack_impl.h"
#include "bl_response.h"


extern volatile uint8_t bl_reply_buff[20];

void bootloader_handle_getVersion_cmd(volatile uint8_t*);
void bootloader_handle_getHelp_cmd(volatile uint8_t*);
void bootloader_handle_getChipID_cmd(volatile uint8_t*);
void get_bl_chip_id_into_reply_buff();
uint8_t get_bl_version();
void get_bl_commands_into_reply_buff();
void get_bl_chip_id_into_reply_buff();

#endif /* INC_BL_CMD_HANDLING_H_ */
