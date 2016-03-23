#ifndef _LCD_CTRL_H_
#define _LCD_CTRL_H_

#include <inttypes.h>

void _lcd_set_ctrl_mode(uint8_t mode);
void _lcd_set_data_mode(uint8_t mode);
void _lcd_set_ctrl(uint8_t rs, uint8_t rw, uint8_t e);

#endif /* _LCD_CTRL_H_ */
