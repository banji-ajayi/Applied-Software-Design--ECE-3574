#Thomas Elliott
#HW6 makefile
CC = g++
CFLAGS = -Wall -g

all: generator consumer dispatcher

generator.o: generator.cpp
	${CC} ${CFLAGS} -c $<

generator: generator.o
	${CC} ${CFLAGS} -o $@ $<   

consumer.o: consumer.cpp
	${CC} ${CFLAGS} -c $<

consumer: consumer.o
	${CC} ${CFLAGS} -o $@ $<

dispatcher.o: dispatcher.cpp

dispatcher: dispatcher.o

clean:
	rm -f *.o *~ core tmp
	rm generator
	rm consumer
	rm dispatcher