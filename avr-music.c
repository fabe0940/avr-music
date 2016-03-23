#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>
#include "key/key.h"
#include "lcd/lcd.h"
#include "stream.h"

void init(void);

int main(void) {
	char c;

	init();

	lcd_power(POWER_ON);
	lcd_clear();

	fprintf(stdlcd, "> ");

	c = '\0';
	while (1) {
		c = key_get_char();
		PORTC = ~c;
		c = c == '*' ? '\r' : c;
		c = c == '#' ? '\n' : c;
		if (c == '\r') lcd_clear();
		fprintf(stdlcd, "%c", c);
	}

	exit(0);
}

void init(void) {
	key_init();
	lcd_init();

	DDRC = 0xFF;

	cli();

	return;
}
