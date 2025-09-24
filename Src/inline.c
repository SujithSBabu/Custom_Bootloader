/*
 * inline.c
 *
 *  Created on: Sep 15, 2025
 *      Author: Sujith S Babu
 */

#include "inline.h"

void __set_msp(uint32_t top_of_stack)
{
	__asm volatile(
			"msr msp, %0\n"
			:
			: "r"(top_of_stack)
			:
			);
}
