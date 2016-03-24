#ifndef _LCD_LCD_H_
#define _LCD_LCD_H_

#include <stdio.h>

#define LCD_POWER_ON 1
#define LCD_POWER_OFF 0

int lcd_init(void);
int lcd_clear(void);
int lcd_power(uint8_t pwr);
int lcd_putchar(char ch, FILE *stream);

#endif /* _LCD_LCD_H_ */
