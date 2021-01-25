/*
 * MCU1.h
 *
 *  Created on: Jan 15, 2021
 *      Author: omarh
 */

#ifndef MCU1_H_
#define MCU1_H_
/****************************************************************************************************
 *										Included Libraries												*
 *										 															*
 *****************************************************************************************************/
#include "keypad.h"
#include "LCD.h"
#include "Timer0.h"
#include "UART.h"
#include "Protocol.h"
/****************************************************************************************************
 *										Configurations												*
 *										 															*
 *****************************************************************************************************/
// Status of the MCU
#define OPTIONS_SCREEN 5
#define NEW_PASSWORD 0
#define CHANGE_PASSWORD 10
#define PASSWORD_CHANGED 11
#define OPEN_DOOR 20
#define UNDEFINED_ERROR 99	// error during password entry
/****************************************************************************************************
 *										Functions												*
 *										 															*
 *****************************************************************************************************/
void openConnection();
void getPassword(uint8*);
uint8 newPassword();
uint8 checkPassword(uint8*);
uint8 changePassword();
uint8 optionsScreen();

#endif /* MCU1_H_ */
