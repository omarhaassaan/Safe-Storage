/*
 * LCD.h
 *
 *  Created on: Sep 28, 2020
 *      Author: omarh
 */

#ifndef LCD_H_
#define LCD_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/****************************************************************************************************
 *										Configurations												*
 *										 															*
 *****************************************************************************************************/
//Mode
#define FUNCTION_SET 0x38	//0x38 -> 2 lines 8bit, 0x30 -> 1 line 8bit
//BUS
#define LCD_BUS_DDR DDRB
#define LCD_BUS_PORT PORTB
#define LCD_BUS_PIN PINB
//RS-RW-E
#define LCD_RS_RW_E_DDR DDRD
#define LCD_RS_RW_E_PORT PORTD
#define LCD_RS_RW_E_PIN PIND
#define RS PD5
#define RW PD6
#define E PD7
//Commands
#define CLEAR_SCREEN 0x01
#define CURSER_ON 0x0E
#define CURSER_OFF 0x0C
#define CURSER_BLINK 0x0F
#define SHIFT_CURSER_LEFT 0x10
#define SHIFT_CURSER_RIGHT 0x14
#define FIRST_LINE_CURSER 0x80
#define SECOND_LINE_CURSER 0xC0


/****************************************************************************************************
 *										Functions												*
 *										 															*
 *****************************************************************************************************/
void LCD_init();
void LCD_sendCommand(uint8);
void LCD_displayCharacter(uint8);
void LCD_displayString(uint8[]);
#if(FUNCTION_SET == 0x38 || FUNCTION_SET == 0x28)
void LCD_goToRowColumn(uint8,uint8);
void LCD_displayStringRowColumn(uint8[],uint8,uint8);
#else
void LCD_goToRowColumn(uint8,uint8);
void LCD_displayStringRow(uint8[],uint8);
#endif
void LCD_clearScreen();
void LCD_integerToString();



#endif /* LCD_H_ */
