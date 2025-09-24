/*
 * bl_response.c
 *
 *  Created on: Sep 18, 2025
 *      Author: Sujith S Babu
 */

#include "bl_response.h"

USART_RegDef_Struct* pusartTwo = USART2;
void bootloader_response(volatile uint8_t* reply_buffer, uint8_t len)
{
	usart_send_bytes(pusartTwo, (uint8_t*)reply_buffer, len);
}
