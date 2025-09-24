/*
 * bootloader.c
 *
 *  Created on: Sep 15, 2025
 *      Author: Sujith S Babu
 */

#include "bootloader.h"

uint8_t cmd_code_array[10] = {BL_GET_VER,
		                      BL_GET_HELP,
							  BL_GET_CID,
							  BL_GET_RDP_STATUS,
		                      BL_GO_TO_ADDR,
							  BL_FLASH_ERASE,
							  BL_MEM_WRITE,
							  BL_ENDIS_RW_PROTECT,
							  BL_MEM_READ,BL_OTP_READ};

void bootloader_uart_read_data()
{

     uint8_t recieve_len = 0;

     switch(tx_packet_buffer[1])
     {
         case BL_GET_VER:
         {
           bootloader_handle_getVersion_cmd(tx_packet_buffer);
    	   break;
         }

         case BL_GET_HELP:
		 {
		   bootloader_handle_getHelp_cmd(tx_packet_buffer);
		   break;
		 }

         case BL_GET_CID:
		 {
		   bootloader_handle_getChipID_cmd(tx_packet_buffer);
		   break;
		 }
     }

}


void bootloader_jump_to_user_app()
{

	/*Function pointer to store the address of the reset handler of the user application.*/
	void (*app_reset_handler) (void);

	/*1.Configure MSP by reading base address of the Sector2 of flash memory which is the starting address of the user app*/
	uint32_t msp_value = (*(volatile uint32_t*)FLASH_SECTOR2_BASEADDR);

	//__disable_irq();
	/*2.Set the MSP value by putting base address of the sector2 of flash memory,which is the starting address of the user app*/
    __set_msp(msp_value);

    SCB_VTOR = FLASH_SECTOR2_BASEADDR;

    /*3.Fetch the reset handler address of the user application,which is base address of sector2 of flash m/y + 0x4;*/
    uint32_t app_reset_handler_address = (*(volatile uint32_t*)(FLASH_SECTOR2_BASEADDR + 0x4));
    app_reset_handler = (void (*) (void)) (app_reset_handler_address);

    /*4. Jump to reset handler of the user application */
    app_reset_handler();
}
