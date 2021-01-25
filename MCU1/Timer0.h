/*
 * Timer0.h
 *
 *  Created on: Dec 5, 2020
 *      Author: omarh
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/****************************************************************************************************
 *										Configurations												*
 *										 															*
 *****************************************************************************************************/
//MODES	WGM bits
#define MODE (0<<3 |0<<6) // Mode to operate the timer : 0x00 -> normal | 0x01 ->PWM | 0x02 -> CTC | 0x03 -> Fast PWM
//PRESCALAR
#define CLOCK_PRESCALAR (0x05) // Prescalar 0x00 -> no clock | 0x01 -> no pre | 0x02 -> 8 | 0x03 -> 64 |
// 0x04 -> 256 | 0x05 -> 1024
//COMPARE OUTPUT MODE
#define OUTPUT_MODE (0x00) // Mode to handle the output
/*NORMAL_OUTPUT 0x00; //non-PWM OC0 disconnected
TOGGLE_OUTPUT 0x01; // Toggle OC0 pin
CLEAR_OUTPUT 0x02;	// Clear OC0 pin
SET_OUTPUT 0x03;	// Set OC0 pin*/
#define INTERRUPT_ENABLE 0x00 // 0x00 -> disable	0x01 -> enable
#define COMPARE_OVERFLOW 0x02 // ox01 -> overflow | 0x02 -> compare match

/****************************************************************************************************
 *										Functions												*
 *										 															*
 *****************************************************************************************************/
void Timer_Init();


#endif /* TIMER0_H_ */
