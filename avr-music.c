#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>
#include "key/key.h"
#include "lcd/lcd.h"
#include "timer/timer.h"
#include "stream.h"

int init(void);
void handler_press(char c);
void handler_release(void);
void handler_toggle(void);

int init(void) {
	int status = 0;

	if (lcd_init()) {
		status = -1;
	} else {
		lcd_power(POWER_ON);
		lcd_clear();
	}

	if (!status && timer_init(TIMER_PRESCALER_1)) {
		status = -1;
	}

	if (!status && key_init(handler_press, handler_release)) {
		status = -1;
	}

	if (!status) {
		DDRC = 0xFF;
		PORTC = 0xFF;
		sei();
	}

	return status;
}

int main(void) {
	char c;

	if (init()) {
		exit(-1);
	}


	while (1) {
		switch (c = key_get_char()) {
			case '*':
				lcd_clear();
				break;
			case '#':
				c = '\n';
			default:
				fprintf(stdlcd, "%c", key_get_char());
		}
	}

	exit(0);
}

void handler_press(char c) {
	switch (c) {
		default:
			timer_callback_register(0x0080, handler_toggle);
	}

	return;
}

void handler_release(void) {
	timer_callback_clear();
	return;
}

void handler_toggle(void) {
	static uint8_t val = 0x00;

	val = (val + 1) % 2;
	PORTC = ~val;

	return;
}
