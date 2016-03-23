#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdio.h>
#include "ctrl.h"
#include "data.h"
#include "defines.h"
#include "lcd.h"
#include "util.h"

int lcd_init(void) {
	_delay_ms(20);

	_lcd_write(REG_CTRL, 0x38);
	_lcd_write(REG_CTRL, 0x38);
	_lcd_write(REG_CTRL, 0x38);
	_lcd_write(REG_CTRL, 0x08);
	_lcd_write(REG_CTRL, 0x01);
	_lcd_write(REG_CTRL, 0x06);
	
	return 0;
}

int lcd_power(uint8_t pwr) {
	_lcd_write(REG_CTRL, 0x0A | pwr << 2);

	return 0;
}

int lcd_clear(void) {
	_lcd_write(REG_CTRL, 0x01);

	return 0;
}

int lcd_putchar(char ch, FILE *stream) {
	switch (ch) {
		case '\n':
			_lcd_write(REG_CTRL, 0x80 | 0x40);
			break;
		case '\r':
			_lcd_write(REG_CTRL, 0x80 | 0x00);
			break;
		default:
			_lcd_write(REG_DATA, ch);
	}

	return 0;
}
