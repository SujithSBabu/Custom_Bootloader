/*
 * bl_ack_nack_impl.h
 *
 *  Created on: Sep 18, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_BL_ACK_NACK_IMPL_H_
#define INC_BL_ACK_NACK_IMPL_H_

#include "stm32f407_xx_MemMap.h"
#include "bootloader.h"
#include "uart.h"

void bl_send_ack(volatile uint8_t*);


#endif /* INC_BL_ACK_NACK_IMPL_H_ */
