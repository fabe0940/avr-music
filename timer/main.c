#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

extern volatile uint8_t cnt;
volatile uint8_t overflowCnt;

int timer_init(uint8_t prescale) {
	/* Initialize TIMER0 to use the overflow ISR */
	TCCR0 = (TCCR0 & ~PRESCALER_MASK) | prescale;
	TIMSK |= (1 << TOIE0);
	TCNT0 = 0x00;

	return 0;
}

ISR(TIMER0_OVF_vect) {
}
