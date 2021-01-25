#include "Timer0.h"

void Timer_Init() {
	TCCR0 = ((MODE & 2) << 3) | ((MODE & 1) << 6) | CLOCK_PRESCALAR
			| (OUTPUT_MODE << 4);
	OCR0 = 0xFF;
#if(INTERRUPT_ENABLE)
	TIMSK |= COMPARE_OVERFLOW;
	SREG |= (1 << 7);
#endif
}

#if(INTERRUPT_ENABLE)
void (*function)();
void Insert_Function(void (*f)()) {
	function = *f;
}
uint8 counter = 0;
ISR(TIMER0_COMP_vect) {
	SREG &= ~(1 << 7);
	counter++;
	if (counter == 4) {
		function();
		counter = 0;
	}
	SREG |= (1 << 7);

}
#endif
