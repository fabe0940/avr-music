#ifndef _LCD_DEFINES_H_
#define _LCD_DEFINES_H_

#define LCD_REG_CTRL 0
#define LCD_REG_DATA 1

#define LCD_REG_WRITE 0
#define LCD_REG_READ 1

#define LCD_MASK_BF 0x80
#define LCD_MASK_E  0x01
#define LCD_MASK_RS 0x02
#define LCD_MASK_RW 0x04

#define LCD_BF 7
#define LCD_E  0
#define LCD_RS 1
#define LCD_RW 2

#define LCD_MODE_READ 0x00
#define LCD_MODE_WRITE 0xFF

#endif /* _LCD_DEFINES_H_ */
