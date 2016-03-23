#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>
#include "lcd/lcd.h"
#include "io.h"

void init(void);

int main(void) {
	init();

	lcd_power(POWER_ON);
	lcd_clear();

	while (1) {
	}

	exit(0);
}

void init(void) {
	lcd_init();

	DDRB = 0xFF;
	PORTB = 0x00;

	cli();

	return;
}
