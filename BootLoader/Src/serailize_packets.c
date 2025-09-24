/*
 * serailize_packets.c
 *
 *  Created on: Sep 16, 2025
 *      Author: Sujith S Babu
 */


#include "serailize_packets.h"
volatile uint8_t tx_packet_buffer[6] = {0};
volatile uint32_t  tx_index  = 0 ;
volatile uint32_t  tx_length = 0;
USART_RegDef_Struct* pUsartt = USART2;
void serialize_packet(bl_packet_struct* packet)
{
	tx_packet_buffer[0] = packet->length_to_follow;
	tx_packet_buffer[1] = packet->cmd_code;
	tx_packet_buffer[2] = packet->crc[0];
	tx_packet_buffer[3] = packet->crc[1];
	tx_packet_buffer[4] = packet->crc[2];
	tx_packet_buffer[5] = packet->crc[3];

	tx_index  = 0;
	tx_length = 1 + packet->length_to_follow;

	/*pUsartt->USART_CR1 &= ~(1U<<7);//Clearing TXEIE)
	if (pUsartt->USART_SR & (1U << 7))  // TXE is set
	{
	    pUsartt->USART_CR1 |= (1U << 7);  // Enable TXE interrupt
	}*/
}
