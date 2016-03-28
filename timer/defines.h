#ifndef _TIMER_DEFINES_H_
#define _TIMER_DEFINES_H_

#include <avr/io.h>

#define _TIMER_MODE_CTC_A ((0x0 << WGM11) | (0x0 << WGM10))
#define _TIMER_MODE_CTC_B ((0x0 << WGM13) | (0x1 << WGM12))
#define _TIMER_MODE_NORMAL_PORT ((0x0 << COM1A1) | (0x0 << COM1A0))

#endif /* _TIMER_DEFINES_H_ */
