#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "defines.h"

_timer_callback active_callback;

int timer_init(uint8_t prescale) {
	TCCR1A = _TIMER_MODE_CTC_A | _TIMER_MODE_NORMAL_PORT;
	TCCR1B = _TIMER_MODE_CTC_B | prescale;

	TIMSK |= (0x1 << OCIE1A);

	TCNT1H = 0x00;
	TCNT1L = 0x00;

	OCR1A = 0x0000;

	timer_callback_clear();

	return 0;
}

void timer_callback_register(uint16_t target, _timer_callback cb) {
	OCR1A = target;
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	active_callback = cb;

	return;
}

void timer_callback_clear(void) {
	timer_callback_register(0xFFFF, timer_callback_none);

	return;
}

void timer_callback_none(void) {
	return;
}

ISR(TIMER1_COMPA_vect) {
	active_callback();
}
