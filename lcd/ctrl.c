#include <avr/io.h>
#include <inttypes.h>
#include "defines.h"
#include "ctrl.h"

void _lcd_set_ctrl_mode(uint8_t mode) {
	DDRA = mode;
	return;
}

void _lcd_set_data_mode(uint8_t mode) {
	DDRD = mode;
	return;
}

void _lcd_set_ctrl(uint8_t rs, uint8_t rw, uint8_t e) {
	_lcd_set_ctrl_mode(LCD_MODE_WRITE);
	PORTA = ((rs << LCD_RS) | (rw << LCD_RW) | (e << LCD_E));
	return;
}
