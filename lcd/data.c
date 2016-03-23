#include <avr/io.h>
#include <inttypes.h>
#include "data.h"

void _lcd_set_data(uint8_t dat) {
	PORTD = dat;
	return;
}

uint8_t _lcd_get_data(void) {
	return PIND;
}
