/*
 * DC_Motor.c
 *
 *  Created on: Jan 16, 2021
 *      Author: omarh
 */
#include "DC_Motor.h"
void MOTOR_init() {
	// Set direction of the pins
	SET_BIT(INP_PIN_1_DDR, INP_PIN_1);
	SET_BIT(INP_PIN_2_DDR, INP_PIN_2);
	// Put 0 bit for pins to stop the motion of the motor
	CLEAR_BIT(INP_PIN_1_PORT, INP_PIN_1);
	CLEAR_BIT(INP_PIN_2_PORT, INP_PIN_2);
}
void MOTOR_RotateClockWise() {
	// 0x1 for the pins to rotate clock wise
	SET_BIT(INP_PIN_1_PORT, INP_PIN_1);
	CLEAR_BIT(INP_PIN_2_PORT, INP_PIN_2);
}
void MOTOR_RotateAntiClockWise() {
	// 0x2 for the pins to rotate clock wise
	CLEAR_BIT(INP_PIN_1_PORT, INP_PIN_1);
	SET_BIT(INP_PIN_2_PORT, INP_PIN_2);
}

