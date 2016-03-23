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

int init(void) {
	int success = 0;

	if (lcd_init()) {
		success = -1;
	}

	if (timer_init(PRESCALER_NONE)) {
		success = -1;
	}

	if (key_init(handler_press, handler_release)) {
		success = -1;
	}

	DDRC = 0xFF;

	cli();

	return success;
}

int main(void) {
	char c;

	if (init()) {
		exit(-1);
	}

	lcd_power(POWER_ON);
	lcd_clear();

	fprintf(stdlcd, "> ");

	c = '\0';
	while (1) {
		c = key_get_char();

		switch (c) {
			case '*':
				lcd_clear();
				fprintf(stdlcd, "\r> ");
				continue;
				break;
			case '#':
				c = '\n';
			default:
				fprintf(stdlcd, "%c", c);
		}
	}

	exit(0);
}

void handler_press(char c) {
	PORTC = ~c;
	return;
}

void handler_release(void) {
	PORTC = 0xFF;
	return;
}
