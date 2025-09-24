/*
 * bl_ack_nack_impl.c
 *
 *  Created on: Sep 18, 2025
 *      Author: Sujith S Babu
 */

#include "bl_ack_nack_impl.h"


USART_RegDef_Struct* pUsartt2 = USART2;
void bl_send_ack(volatile uint8_t* cmd_code)
{
     uint8_t ack_buffer[3];

     uint8_t len = (sizeof(ack_buffer)/sizeof(ack_buffer[0]));
     ack_buffer[0] = BL_ACK;
     ack_buffer[1] = *(cmd_code);
     ack_buffer[2] = CRC_SUCCESS;
     usart_send_bytes(pUsartt2, ack_buffer, len);

}
