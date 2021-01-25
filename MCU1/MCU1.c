#include "MCU1.h"

int main() {
	LCD_init();
	UART_init();
	uint8 MCU_state = 0;
	while (1) {
		if (MCU_state == NEW_PASSWORD) {
			MCU_state = newPassword();
		} else if (MCU_state == OPTIONS_SCREEN) {
			MCU_state = optionsScreen();
		} else if (MCU_state == CHANGE_PASSWORD) {
			MCU_state = changePassword();
		} else if (MCU_state == OPEN_DOOR) {
			LCD_clearScreen();
			LCD_displayString("Opening the door");
			uint8 password[16];
			checkPassword(password);
			openConnection();
			UART_sendByte(OPEN_THE_DOOR);
			_delay_ms(5000);
			MCU_state = OPTIONS_SCREEN;
		}

	}
//	while (1) {
//		openConnection();
//		uint8 *password = "asd\0";
//		UART_sendString(password);
//		password = "K123\0";
//		LCD_displayCharacter('A');
//		openConnection();
//		uint8 *password2 = "KRE\0";
//		UART_sendString(password2);
//		LCD_displayCharacter('A');
//
//	}
}

void openConnection() {
	UART_sendByte(ACK);
	while (UART_receiveByte() != ACK)
		;
}

void getPassword(uint8 *fpassword) {
	uint8 flag = 0;
	uint8 i;
	for (i = 0; i < 16; i++)
		fpassword[i] = '\0';
	for (i = 0; i < 16; i++) {
		uint8 s = Keypad_getPressedKey();
		flag = (s == '=' ? 1 : 0);
		if (flag)
			break;
		if (s >= 0 && s <= 9)
			// Convert from digit to the ASCII number of such a number
			s += 48;
		fpassword[i] = s;
		LCD_displayCharacter('*');
	}

}

uint8 newPassword() {
	// Array to hold the password
	uint8 password[16];
	uint8 password1[16];
	LCD_clearScreen();
	LCD_displayString("Enter Password:");
	// Go to the second row first column
	LCD_goToRowColumn(1, 0);
	// Read password and put it in password array from user
	getPassword(password);
	// make sure that both MCU listen to each other
	openConnection();
	// Send password array to the second MCU
	UART_sendString(password);
	LCD_clearScreen();
	LCD_goToRowColumn(0, 0);
	LCD_displayString("Re-Enter:");
	LCD_goToRowColumn(1, 0);
	// Read password confirmation from the user and put to password array
	getPassword(password1);
	// Send the second password to the second MCU and return the response received from other MCU
	uint8 returnValue = checkPassword(password1);
	LCD_clearScreen();
	// Check if not confirmed, show invalid on the screen and return the status of MCU with new_password again
	if (returnValue == NOT_CONFIRMED_PASSWORD) {
		LCD_displayString("Invalid");
		_delay_ms(1000);
		return NEW_PASSWORD;
	} // Check if confirmed,show that password saved on the screen and proceed to the next step and return password_saved status
	else if (returnValue == CONFIRMED_PASSWORD) {
		LCD_displayString("Password Saved");
		_delay_ms(1000);
		return OPTIONS_SCREEN;
	}
	// In case any other error away from previous mentioned states
	return UNDEFINED_ERROR;
}

uint8 checkPassword(uint8 *fpassword) {
	// make sure that both MCU listen to each other
	openConnection();
	// Send password to the other MCU
	UART_sendString(fpassword);
	// make sure that both MCU listen to each other
	openConnection();
	// Receive response from the other MCU, by looking to Protocol.h
	// you will understand how the 2 MCU communicate using this protocol for messages to be meaningful
	return UART_receiveByte();
}

uint8 changePassword() {
	LCD_clearScreen();
	LCD_displayString("Enter Old Pass:");
	LCD_goToRowColumn(1, 0);
	uint8 *password[16];
	getPassword(password);
	uint8 returnValue = checkPassword(password);
	openConnection();
	UART_sendByte(PASSWORD_CHANGING);
	if (returnValue == NOT_CONFIRMED_PASSWORD) {
		LCD_clearScreen();
		LCD_displayString("Invalid");
		_delay_ms(2000);
		return OPTIONS_SCREEN;
	} else if (returnValue == CONFIRMED_PASSWORD) {
		LCD_clearScreen();
		LCD_displayString("Correct !!");
		_delay_ms(1000);
		return NEW_PASSWORD;
	}
	return UNDEFINED_ERROR;
}

uint8 optionsScreen() {
	LCD_clearScreen();
	LCD_displayString("+: Change Pass");
	LCD_goToRowColumn(1, 0);
	LCD_displayString("-: Open Door");
	uint8 key = '0';
	while (key != '+' && key != '-')
		key = Keypad_getPressedKey();
	return key == '+' ? CHANGE_PASSWORD : OPEN_DOOR;
}
