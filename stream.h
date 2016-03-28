#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>
#include "lcd/lcd.h"

static FILE stream = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
#define stdlcd (&stream)

#endif /* _IO_H_ */
