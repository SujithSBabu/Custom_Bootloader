/*
 * bl_crc_verification.h
 *
 *  Created on: Sep 17, 2025
 *      Author: Sujith S Babu
 */

#ifndef INC_BL_CRC_VERIFICATION_H_
#define INC_BL_CRC_VERIFICATION_H_

#include "stm32f407_xx_MemMap.h"
#include "crc_calculation.h"
uint8_t bl_crc_verify(volatile uint8_t*);


#endif /* INC_BL_CRC_VERIFICATION_H_ */
