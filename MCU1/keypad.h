/*
 * keypad.h
 *
 *  Created on: Sep 28, 2020
 *      Author: omarh
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
/************************************************************************************************
 * 									Configurations												*								*
 * First 3/4 ports for the columns respectively followed by 4 ports for rows					*
 ************************************************************************************************/
#define KEYPAD_DDR DDRA
#define KEYPAD_PORT PORTA
#define KEYPAD_PIN PINA
#define COLUMNS 4
#define ROWS 4
/*************************************************************************************************
 * 									Functions													*
 * 	Function for each Keypad and a general function to get the pressed key from any keypad		*
 *																								*
 *************************************************************************************************/
#if (COLUMNS ==3)
static uint8 Keypad_4x3_adjustSwitchNumber(uint8);
#elif (COLUMNS ==4)
static uint8 Keypad_4x4_adjustSwitchNumber(uint8);
#endif
uint8 Keypad_getPressedKey();


#endif /* KEYPAD_H_ */
