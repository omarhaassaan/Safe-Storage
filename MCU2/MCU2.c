#include "MCU2.h"

int main() {
	LCD_init();
	UART_init();
	EEPROM_init();
	MOTOR_init();
	uint8 MCU_state = 0;
	while (1) {
		if (MCU_state == NEW_PASSWORD) {
			MCU_state = newPassword();
		} else if (MCU_state == THERE_IS_PASSWORD_IN_EEPROM) {
			MCU_state = checkCurrentPassword();
			openConnection();
			if(UART_receiveByte()==OPEN_THE_DOOR)
				MCU_state = OPEN_DOOR;
		} else if (MCU_state == OPEN_DOOR) {
			MOTOR_RotateClockWise();
			_delay_ms(2500);
			MOTOR_RotateAntiClockWise();
			_delay_ms(2500);
			MOTOR_Stop();
			MCU_state = THERE_IS_PASSWORD_IN_EEPROM;
		}

	}
//	while (1) {
//		openConnection();
//		uint8 password[16];
//		UART_receiveString(password);
//		LCD_displayString(password);
//		openConnection();
//		UART_receiveString(password);
//		LCD_displayString(password);
//	}
}

void openConnection() {
	while (UART_receiveByte() != ACK)
		;
	UART_sendByte(ACK);
}

uint8 checkCurrentPassword() {
	LCD_clearScreen();
	LCD_displayString("Changing");
	uint8 password[16];
	uint8 currentPassword[16];
	// make sure that both MCU listen to each other
	openConnection();
	UART_receiveString(password);
	_delay_ms(1000);
	getFromEEPROM(currentPassword);
	if (equals(password, currentPassword) == 'f') {
		// make sure that both MCU listen to each other
		openConnection();
		UART_sendByte(NOT_CONFIRMED_PASSWORD);
		return THERE_IS_PASSWORD_IN_EEPROM;
	} else {
		// make sure that both MCU listen to each other
		openConnection();
		UART_sendByte(CONFIRMED_PASSWORD);
		return NEW_PASSWORD;
	}
}

uint8 newPassword() {
	LCD_clearScreen();
	LCD_displayString("NEW");
	// Array to receive first trial for password
	uint8 password[16] = "\0";
	// Array to receive second trial for password
	uint8 passwordConfirm[16] = "\0";
	// make sure that both MCU listen to each other
	openConnection();
	// receive password
	UART_receiveString(password);
	// Store in memory
	storeInEEPROM(password);
	// make sure that both MCU listen to each other
	openConnection();
	UART_receiveString(passwordConfirm);
	if (equals(password, passwordConfirm) == 'f') {
		// make sure that both MCU listen to each other
		openConnection();
		UART_sendByte(NOT_CONFIRMED_PASSWORD);
		return NEW_PASSWORD;
	} else {
		// make sure that both MCU listen to each other
		openConnection();
		UART_sendByte(CONFIRMED_PASSWORD);
		LCD_clearScreen();
		LCD_displayString("Password Saved");
		return THERE_IS_PASSWORD_IN_EEPROM;
	}
}

void storeInEEPROM(uint8 *password) {
	uint8 i = 0;
	while (password[i] != '\0') {
		EEPROM_writeByte(i, password[i++]);
		_delay_ms(10);
	}
	EEPROM_writeByte(i, '\0');
}

void getFromEEPROM(uint8 *password) {
	uint8 i = 0;
	while (password[i] != '\0') {
		EEPROM_readByte(i, &password[i++]);
		_delay_ms(10);
	}
}

uint8 equals(uint8 *str1, uint8 *str2) {
	uint8 i = 0;
	while (str1[i] == str2[i]) {
		if (str1[i] == '\0' && str2[i] == '\0')
			return 't';
		i++;
	}
	return 'f';

}
