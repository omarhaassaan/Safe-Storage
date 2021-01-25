#include "UART.h"

void UART_init() {
	UCSRA = (1 << U2X);
	UCSRB = (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_RATE;
	UBRRH = (BAUD_RATE >> 8);
}

void UART_sendByte(uint8 data) {
	while (BIT_IS_CLEAR(UCSRA, UDRE))
		;
	UDR = data;
}

uint8 UART_receiveByte() {
	while (BIT_IS_CLEAR(UCSRA, RXC));
	return UDR;
}

void UART_sendString(uint8 str[]) {
	uint8 i;
	for (i = 0; str[i] != '\0'; i++)
		UART_sendByte(str[i]);
	//Symbol indicate that the string has ended
	UART_sendByte('#');
}

void UART_receiveString(uint8 *str) {
	uint8 i = 0;
	str[i] = UART_receiveByte();
	while(str[i] != '#'){
		i++;
		str[i] = UART_receiveByte();
	}

	str[i] = '\0';
}

