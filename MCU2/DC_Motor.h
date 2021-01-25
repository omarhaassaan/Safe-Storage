/*
 * DC_Motor.h
 *
 *  Created on: Jan 16, 2021
 *      Author: omarh
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/****************************************************************************************************
 *										Included Libraries												*
 *										 															*
 *****************************************************************************************************/
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"
/****************************************************************************************************
 *										Configurations												*
 *										 															*
 *****************************************************************************************************/
#define INP_PIN_1 PA0
#define INP_PIN_2 PA1
#define INP_PIN_1_DDR DDRA
#define INP_PIN_2_DDR DDRA
#define INP_PIN_1_PORT PORTA
#define INP_PIN_2_PORT PORTA

/****************************************************************************************************
 *										Functions												*
 *										 															*
 *****************************************************************************************************/
void MOTOR_init();
void MOTOR_RotateClockWise();
void MOTOR_RotateAntiClockWise();
void MOTOR_Stop();

#endif /* DC_MOTOR_H_ */
