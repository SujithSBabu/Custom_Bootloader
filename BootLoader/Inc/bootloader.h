/*
 * bootloader.h
 *
 *  Created on: Sep 15, 2025
 *      Author: Sujith S Babu
 */

#ifndef BOOTLOADER_INC_BOOTLOADER_H_
#define BOOTLOADER_INC_BOOTLOADER_H_

#include "stm32f407_xx_MemMap.h"
#include "inline.h"
#include "uart_stm32.h"
#include "bl_cmd_handling.h"

/* BootLoader CMD MACROS */
#define BL_GET_VER           0x51
#define BL_GET_HELP          0x52
#define BL_GET_CID           0x53
#define BL_GET_RDP_STATUS    0x54
#define BL_GO_TO_ADDR        0x55
#define BL_FLASH_ERASE       0x56
#define BL_MEM_WRITE         0x57
#define BL_ENDIS_RW_PROTECT  0x58
#define BL_MEM_READ          0x59
#define BL_OTP_READ          0x5A

#define BL_ACK               0xA5
#define BL_NACK              0x7F
#define CRC_ERROR            0x00
#define CRC_SUCCESS          0x01

/*BootLoader version 1.0*/
#define BL_VERSION           0x10



extern volatile uint8_t tx_packet_buffer[6];
/*Function Prototypes*/
void bootloader_uart_read_data();
void bootloader_jump_to_user_app();



#endif /* BOOTLOADER_INC_BOOTLOADER_H_ */
