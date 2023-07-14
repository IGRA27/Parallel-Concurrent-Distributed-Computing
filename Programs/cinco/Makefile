# Makefile para programas cicno (Unidad 2)

CINCOOBJ= cinco.o
CINCO-SLEEPOBJ= cinco-sleep.o
ALLOBJ= cinco.o cinco-sleep.o

all:    cinco cinco-sleep

cinco:  $(CINCOOBJ)
        cc -o cinco $(CINCOOBJ)

cinco-sleep:    $(CINCO-SLEEPOBJ)
        cc -o cinco-sleep $(CINCO-SLEEPOBJ)

clean:
        rm -f $(ALLOBJ)

