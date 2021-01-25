/*
 * UART.h
 *
 *  Created on: Oct 4, 2020
 *      Author: omarh
 */

#ifndef UART_H_
#define UART_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/****************************************************************************************************
 *										Configurations												*
 *										 															*
 *****************************************************************************************************/

#define SYNC_MODE 1
#define ASYNC_MODE 0
#define STOP_BIT 0
#define CHAR_SIZE 0b011
#define CLOCK_POLAR 0
#define BAUD_RATE 12

/****************************************************************************************************
 *										Functions													*
 *										 															*
 *****************************************************************************************************/
void UART_init();
void UART_sendByte(uint8 data);
uint8 UART_receiveByte();
void UART_sendString(uint8[]);
void UART_receiveString(uint8*);

#endif /* UART_H_ */
