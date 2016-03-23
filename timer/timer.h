#ifndef _TIMER_H_
#define _TIMER_H_

#include <avr/io.h>
#include <inttypes.h>

#define OVERFLOWS_PER_SECOND 16
#define PRESCALER_MASK ((1<<CS02)|(1<<CS01)|(1<<CS00))
#define PRESCALER_NONE ((0<<CS02)|(0<<CS01)|(0<<CS00))
#define PRESCALER_1    ((0<<CS02)|(0<<CS01)|(1<<CS00))
#define PRESCALER_8    ((0<<CS02)|(1<<CS01)|(0<<CS00))
#define PRESCALER_64   ((0<<CS02)|(1<<CS01)|(1<<CS00))
#define PRESCALER_256  ((1<<CS02)|(0<<CS01)|(0<<CS00))
#define PRESCALER_1024 ((1<<CS02)|(0<<CS01)|(1<<CS00))

int timer_init(uint8_t prescale);

#endif /* _TIMER_H_ */
