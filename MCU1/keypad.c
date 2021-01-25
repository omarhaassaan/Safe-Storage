#include "keypad.h"

uint8 Keypad_getPressedKey() {
	uint8 cols, rows;
	while (1) {
		for (cols = 0; cols < COLUMNS; cols++) {
			KEYPAD_DDR = (0x01 << cols);
			KEYPAD_PORT = (~(0x01 << cols));
			for (rows = 0; rows < ROWS; rows++) {
				if (BIT_IS_CLEAR(KEYPAD_PIN, rows+COLUMNS)){
					while(BIT_IS_CLEAR(KEYPAD_PIN, rows+COLUMNS));
#if (COLUMNS == 3)
					return Keypad_4x3_adjustSwitchNumber(
							(rows * COLUMNS) + cols + 1);
#elif (COLUMNS == 4)
					return Keypad_4x4_adjustSwitchNumber(
							(rows * COLUMNS) + cols + 1);
#endif
				}
			}
		}
	}
}

#if (COLUMNS == 3)
static uint8 Keypad_4x3_adjustSwitchNumber(uint8 butNum) {
	switch (butNum) {
	case 10:
		return '*';
		break;
	case 11:
		return 0;
		break;
	case 12:
		return '#'; // ASCII Code of #
		break;
	default:
		return butNum;
	}
}

#elif (COLUMNS ==4)
static uint8 Keypad_4x4_adjustSwitchNumber(uint8 butNum) {
	switch (butNum) {
	case 1:
		return 7;
		break;
	case 2:
		return 8;
		break;
	case 3:
		return 9;
		break;
	case 4:
		return '%'; // ASCII Code of %
		break;
	case 5:
		return 4;
		break;
	case 6:
		return 5;
		break;
	case 7:
		return 6;
		break;
	case 8:
		return '*'; /* ASCII Code of '*' */
		break;
	case 9:
		return 1;
		break;
	case 10:
		return 2;
		break;
	case 11:
		return 3;
		break;
	case 12:
		return '-'; /* ASCII Code of '-' */
		break;
	case 13:
		return 13; /* ASCII of Enter */
		break;
	case 14:
		return 0;
		break;
	case 15:
		return '='; /* ASCII Code of '=' */
		break;
	case 16:
		return '+'; /* ASCII Code of '+' */
		break;
	default:
		return butNum;
	}
}
#endif

