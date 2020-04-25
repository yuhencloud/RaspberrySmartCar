C_SRCS = ultrasonic.c servo.c engine.c smartcar.c
OBJS = ultrasonic.o servo.o engine.o smartcar.o
LIBS = -lwiringPi
TARGET = smartcar
main:${OBJS}
	cc -g ${C_SRCS} -o ${TARGET} ${LIBS}

clean:
	rm -rf ${OBJS}
	rm -rf ${TARGET}
