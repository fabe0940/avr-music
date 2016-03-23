APPLICATION_NAME := avr-music
CC := avr-gcc
CFLAGS := -mmcu=atmega32 -Wall -Wextra -Wpedantic -DF_CPU=8000000UL -O2
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))
KEY_SRC := $(wildcard key/*.c)
KEY_OBJ := $(patsubst %.c, %.o, $(KEY_SRC))
LCD_SRC := $(wildcard lcd/*.c)
LCD_OBJ := $(patsubst %.c, %.o, $(LCD_SRC))
TIMER_SRC := $(wildcard timer/*.c)
TIMER_OBJ := $(patsubst %.c, %.o, $(TIMER_SRC))

DEV := /dev/ttyS0

CLOCK_1MHz = 0xE1
CLOCK_2MHz = 0xE2
CLOCK_4MHz = 0xE3
CLOCK_8MHz = 0xE4

.PHONY : all lcd install clean rebuild

all : $(APPLICATION_NAME)

install : $(APPLICATION_NAME)
	avrdude -q -q -p atmega32 -P $(DEV) -c stk500v2 \
		-U lfuse:w:$(CLOCK_1MHz):m \
		-U flash:w:$(APPLICATION_NAME).hex:i

$(APPLICATION_NAME) : $(OBJ) $(KEY_OBJ) $(LCD_OBJ) $(TIMER_OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	objcopy -S -O ihex $(APPLICATION_NAME) $(APPLICATION_NAME).hex

$(KEY_OBJ) : $(KEY_SRC)
	$(MAKE) -C key/

$(LCD_OBJ) : $(LCD_SRC)
	$(MAKE) -C lcd/

$(TIMER_OBJ) : $(TIMER_SRC)
	$(MAKE) -C timer/

%.o : %.c
	$(CC) $(CFLAGS) -c $<

avr-lcd.c : io.h

clean :
	\rm -f $(APPLICATION_NAME) $(APPLICATION_NAME).hex $(OBJ)
	$(MAKE) clean -C lcd/
	$(MAKE) clean -C key/

rebuild :
	make clean
	make all
