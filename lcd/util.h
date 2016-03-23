#ifndef _LCD_UTIL_H_
#define _LCD_UTIL_H_

#include <inttypes.h>

uint8_t _lcd_read(uint8_t rs);
void _lcd_write(uint8_t rs, uint8_t val);
void _lcd_wait(void);

#endif /* _LCD_UTIL_H_ */
