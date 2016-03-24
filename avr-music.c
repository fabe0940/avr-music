#include <avr/interrupt.h>
#include <stdlib.h>
#include <util/delay.h>
#include "key/key.h"
#include "lcd/lcd.h"
#include "timer/timer.h"
#include "defines.h"
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
		lcd_power(LCD_POWER_ON);
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
	if (init()) {
		exit(-1);
	}


	while (1) {
		key_get_char();
	}

	exit(0);
}

void handler_press(char c) {
	uint16_t target;

	switch (c) {
		case '1':
			target = NOTE_A3;
			break;
		case '2':
			target = NOTE_A3S;
			break;
		case '3':
			target = NOTE_B3;
			break;
		case 'A':
			target = NOTE_C4;
			break;
		case '4':
			target = NOTE_C4S;
			break;
		case '5':
			target = NOTE_D4;
			break;
		case '6':
			target = NOTE_D4S;
			break;
		case 'B':
			target = NOTE_E4;
			break;
		case '7':
			target = NOTE_F4;
			break;
		case '8':
			target = NOTE_F4S;
			break;
		case '9':
			target = NOTE_G4;
			break;
		case 'C':
			target = NOTE_G4S;
			break;
		case '*':
			target = NOTE_A4;
			break;
		case '0':
			target = NOTE_A4S;
			break;
		case '#':
			target = NOTE_B4;
			break;
		case 'D':
			target = NOTE_C5;
			break;
	}

	timer_callback_register(target, handler_toggle);

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
