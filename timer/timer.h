#ifndef _TIMER_TIMER_H_
#define _TIMER_TIMER_H_

#include <avr/io.h>
#include <inttypes.h>

#define TIMER_PRESCALER_MASK ((1<<CS02)|(1<<CS01)|(1<<CS00))
#define TIMER_PRESCALER_NONE ((0<<CS02)|(0<<CS01)|(0<<CS00))
#define TIMER_PRESCALER_1    ((0<<CS02)|(0<<CS01)|(1<<CS00))
#define TIMER_PRESCALER_8    ((0<<CS02)|(1<<CS01)|(0<<CS00))
#define TIMER_PRESCALER_64   ((0<<CS02)|(1<<CS01)|(1<<CS00))
#define TIMER_PRESCALER_256  ((1<<CS02)|(0<<CS01)|(0<<CS00))
#define TIMER_PRESCALER_1024 ((1<<CS02)|(0<<CS01)|(1<<CS00))

typedef void (*_timer_callback)(void);

int timer_init(uint8_t prescale);
void timer_callback_register(uint16_t target, _timer_callback cb);
void timer_callback_clear(void);
void timer_callback_none(void);

#endif /* _TIMER_TIMER_H_ */
