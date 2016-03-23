#ifndef _LCD_DEFINES_H_
#define _LCD_DEFINES_H_

#define REG_CTRL 0
#define REG_DATA 1

#define REG_WRITE 0
#define REG_READ 1

#define MASK_BF 0x80
#define MASK_E  0x01
#define MASK_RS 0x02
#define MASK_RW 0x04

#define BF 7
#define E  0
#define RS 1
#define RW 2

#define MODE_READ 0x00
#define MODE_WRITE 0xFF

#endif /* _LCD_DEFINES_H_ */
