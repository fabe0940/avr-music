#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>
#include "key/key.h"
#include "lcd/lcd.h"
#include "stream.h"

void init(void);
void handler_press(char c);
void handler_release(void);

void init(void) {
	key_init(handler_press, handler_release);
	lcd_init();

	DDRC = 0xFF;

	cli();

	return;
}

int main(void) {
	char c;

	init();

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
