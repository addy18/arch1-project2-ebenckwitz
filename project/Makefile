# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../project/h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: project_main.elf

#additional rules for files
project_main.elf: ${COMMON_OBJECTS} interrupt_handler.o led.o switches.o main.o buzzer.o stateMachines.o wdInterruptHandler.o ../project/lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project_main.elf
	msp430loader.sh project_main.elf

clean:
	rm -f *.o *.elf *~
led.o: led.c led.h
wdInterruptHandler.o: stateMachines.h
stateMachines.o: led.h stateMachines.h
buzzer.c: buzzer.h
main.c: buzzer.h
