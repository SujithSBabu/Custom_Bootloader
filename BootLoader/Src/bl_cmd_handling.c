/*
 * bl_cmd_handling.c
 *
 *  Created on: Sep 17, 2025
 *      Author: Sujith S Babu
 */

#include "bl_cmd_handling.h"
volatile uint8_t bl_reply_buff[20] = {0};
extern uint8_t cmd_code_array[10];
uint8_t len = (sizeof(bl_reply_buff)/sizeof(bl_reply_buff[0]));
USART_RegDef_Struct* pusartT2 = USART2;
void bootloader_handle_getVersion_cmd(volatile uint8_t* packet_buffer)
{
     if(bl_crc_verify(packet_buffer))
     {
    	 usart_stm32_send_string(pusartT2, "ACK: ");
    	 bl_send_ack(&packet_buffer[1]);
    	 usart_stm32_send_string(pusartT2, "(Positive Response, BL_GET_VER_CMD, CRC_SUCCESS)\r\n");
         uint8_t bl_version = get_bl_version();
         bl_reply_buff[0]   = bl_version;
         usart_send_string(pusartT2, "BL_Version: ");
         bootloader_response((volatile uint8_t*)bl_reply_buff, len);
         usart_send_string(pusartT2, "\r\n\r\n");
         *packet_buffer = 0;
         for(uint8_t i=0;i< len;i++)
         {
        	 bl_reply_buff[i] = 0; //array itself is a pointer
         }

     }
}

void bootloader_handle_getHelp_cmd(volatile uint8_t* packet_buffer)
{

	if(bl_crc_verify(packet_buffer))
	 {
		 usart_stm32_send_string(pusartT2, "ACK: ");
		 bl_send_ack(&packet_buffer[1]);
		 usart_stm32_send_string(pusartT2, "(Positive Response, BL_GET_HELP, CRC_SUCCESS)\r\n");
		 get_bl_commands_into_reply_buff();
		 usart_send_string(pusartT2, "BL_Command_Codes: ");
		 bootloader_response((volatile uint8_t*)bl_reply_buff, len);
		 usart_send_string(pusartT2, "\r\n\r\n");
		 *packet_buffer = 0;
		 for(uint8_t i=0;i< len;i++)
		 {
			bl_reply_buff[i] = 0; //array itself is a pointer
		 }
	 }
}

void bootloader_handle_getChipID_cmd(volatile uint8_t* packet_buffer)
{
	if(bl_crc_verify(packet_buffer))
	 {
		 usart_stm32_send_string(pusartT2, "ACK: ");
		 bl_send_ack(&packet_buffer[1]);
		 usart_stm32_send_string(pusartT2, "(Positive Response, BL_GET_CID, CRC_SUCCESS)\r\n");
		 get_bl_chip_id_into_reply_buff();
		 usart_send_string(pusartT2, "Chip_ID: ");
		 bootloader_response((volatile uint8_t*)bl_reply_buff, len);
		 usart_send_string(pusartT2, "\r\n\r\n");
		 *packet_buffer = 0;
		 for(uint8_t i=0;i< len;i++)
		 {
			bl_reply_buff[i] = 0; //array itself is a pointer
		 }
	 }
}


uint8_t get_bl_version()
{
	return (uint8_t)BL_VERSION;
}

void get_bl_commands_into_reply_buff()
{
    uint8_t cmd_ary_len = (sizeof(cmd_code_array)/sizeof(cmd_code_array[0]));
    for(uint8_t i = 0; i< cmd_ary_len; i++)
    {
    	bl_reply_buff[i] = cmd_code_array[i];
    }
}

void get_bl_chip_id_into_reply_buff()
{
	for(int8_t i = 24,j = 0; i>=0 && j<4; i-=8,j++)
	{
		bl_reply_buff[j] = (MCU_Chip_ID_byte1 >> i) & 0xFF;
	}
	for(int8_t i = 24,j = 0; i>=0 && j<8; i-=8,j++)
	{
		bl_reply_buff[j+4] = (MCU_Chip_ID_byte2 >> i) & 0xFF;
	}
	for(int8_t i = 24,j = 0; i>=0 && j<12; i-=8,j++)
	{
		bl_reply_buff[j+8] = (MCU_Chip_ID_byte3 >> i) & 0xFF;
	}
}
