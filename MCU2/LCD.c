#include "LCD.h"
uint8 number = 0;
void LCD_init() {
	LCD_BUS_DDR = 0xFF;
	LCD_RS_RW_E_DDR |= (1 << RS) | (1 << RW) | (1 << E);
	LCD_sendCommand(FUNCTION_SET);
	LCD_sendCommand(CURSER_BLINK);
	LCD_sendCommand(CLEAR_SCREEN);
}


void LCD_sendCommand(uint8 command) {
	CLEAR_BIT(LCD_RS_RW_E_PORT,RS);
	CLEAR_BIT(LCD_RS_RW_E_PORT,RW);
	_delay_ms(1);
	SET_BIT(LCD_RS_RW_E_PORT,E);
	_delay_ms(1);
	LCD_BUS_PORT = command;
	_delay_ms(1);
	CLEAR_BIT(LCD_RS_RW_E_PORT,E);
	_delay_ms(1);
}


void LCD_displayCharacter(uint8 c) {
	if(number==16){
		LCD_sendCommand(SECOND_LINE_CURSER);
	}
	SET_BIT(LCD_RS_RW_E_PORT,RS);
	CLEAR_BIT(LCD_RS_RW_E_PORT,RW);
	_delay_ms(1);
	SET_BIT(LCD_RS_RW_E_PORT,E);
	_delay_ms(1);
	LCD_BUS_PORT = c;
	_delay_ms(1);
	CLEAR_BIT(LCD_RS_RW_E_PORT,E);
	_delay_ms(1);
	LCD_BUS_PORT = 0;
	number++;
}


void LCD_displayString(uint8 str[]) {
	uint8 i=0;
	while(str[i] != '\0')
		LCD_displayCharacter(str[i++]);
}
#if(FUNCTION_SET == 0x38 || FUNCTION_SET == 0x28)
void LCD_goToRowColumn(uint8 row, uint8 col) {
	row == 0 ? LCD_sendCommand(FIRST_LINE_CURSER):LCD_sendCommand(SECOND_LINE_CURSER);
	for(;col>0;col--)
		LCD_sendCommand(SHIFT_CURSER_RIGHT);
}
void LCD_displayStringRowColumn(uint8 str[], uint8 row, uint8 col) {
	LCD_goToRowColumn(row,col);
	LCD_displayString(str);
}
#else
void LCD_goToRowColumn(uint8 row,uint8 col){
	uint8 Address;

		/* first of all calculate the required address */
		switch(row)
		{
			case 0:
					Address=col;
					break;
			case 1:
					Address=col+0x40;
					break;
			case 2:
					Address=col+0x10;
					break;
			case 3:
					Address=col+0x50;
					break;
		}
		/* to write to a specific address in the LCD
		 * we need to apply the corresponding command 0b10000000+Address */
		LCD_sendCommand(Address | FIRST_LINE_CURSER);
}
void LCD_displayStringRowColumn(uint8 str[],uint8 row,uint8 col){
	LCD_goToRowColumn(row,col);
	LCD_displayString(str);
}
#endif
void LCD_clearScreen() {
	LCD_sendCommand(CLEAR_SCREEN);
}
void LCD_integerToString() {

}

