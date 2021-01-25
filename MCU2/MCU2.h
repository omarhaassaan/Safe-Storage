/*
 * MCU2.h
 *
 *  Created on: Jan 15, 2021
 *      Author: omarh
 */

#ifndef MCU2_H_
#define MCU2_H_
/****************************************************************************************************
 *										Included Libraries												*
 *										 															*
 *****************************************************************************************************/
#include "LCD.h"
#include "UART.h"
#include "external_eeprom.h"
#include "DC_Motor.h"
#include "Protocol.h"
/****************************************************************************************************
 *										Configurations												*
 *										 															*
 *****************************************************************************************************/
// Status of the MCU
#define NEW_PASSWORD 0
#define THERE_IS_PASSWORD_IN_EEPROM 5
#define OPEN_DOOR 10
/****************************************************************************************************
 *										Functions												*
 *										 															*
 *****************************************************************************************************/
void openConnection();
uint8 checkCurrentPassword();
uint8 newPassword();
void storeInEEPROM(uint8*);
void getFromEEPROM(uint8*);
uint8 equals(uint8*, uint8*);


#endif /* MCU2_H_ */
