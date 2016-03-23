CC := avr-gcc
CFLAGS := -mmcu=atmega32 -Wall -Wextra -Wpedantic -DF_CPU=8000000UL -O2
SRC := $(wildcard *.c)
OBJ := $(patsubst %.c, %.o, $(SRC))

.PHONY : all clean rebuild

all : $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

main.c : ctrl.h data.h defines.h lcd.h util.h
ctrl.c : ctrl.h defines.h
data.c : data.h ctrl.h defines.h
util.c : util.h ctrl.h defines.h data.h

clean :
	\rm -f $(OBJ)

rebuild :
	make clean
	make all
