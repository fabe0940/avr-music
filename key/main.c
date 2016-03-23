#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>
#include "key.h"

#define ROW2 0
#define ROW3 1
#define COL1 2
#define ROW4 3
#define COL2 4
#define COL3 5
#define COL4 6
#define ROW1 7

#define SIZE 4

uint8_t DDR;
uint8_t IN_MASK;
uint8_t rows[SIZE] = { ROW1, ROW2, ROW3, ROW4 };
uint8_t cols[SIZE] = { COL1, COL2, COL3, COL4 };
char keys[SIZE][SIZE] = {
	{ '1', '2', '3', 'A' },
	{ '4', '5', '6', 'B' },
	{ '7', '8', '9', 'C' },
	{ '*', '0', '#', 'D' }
};

int key_init(void) {
	IN_MASK = 0x00;
	IN_MASK |= (0x01 << COL1);
	IN_MASK |= (0x01 << COL2);
	IN_MASK |= (0x01 << COL3);
	IN_MASK |= (0x01 << COL4);

	DDR = 0x00;
	DDR |= (0x01 << ROW1);
	DDR |= (0x01 << ROW2);
	DDR |= (0x01 << ROW3);
	DDR |= (0x01 << ROW4);

	return 0;
}

char key_get_char(void) {
	char ch;
	uint8_t i;
	uint8_t j;

	DDRB = DDR;

	ch = '\0';
	while (ch == '\0') {
		for (i = 0; i < SIZE; i++) {
			PORTB = 0xFF ^ (0x01 << rows[i]);
			for (j = 0; j < SIZE; j++) {
				if (~(PINB & IN_MASK) & (0x01 << cols[j])) {
					ch = keys[i][j];
					_delay_us(5);
					while (~(PINB & IN_MASK) & (0x01 << cols[j]));
					break;
				}
			}
		}
	}

	return ch;
}
