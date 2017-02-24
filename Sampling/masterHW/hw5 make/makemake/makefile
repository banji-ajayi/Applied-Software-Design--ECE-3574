#Thomas Elliott
#HW5 Make a makefile
CC = g++
CFLAGS = -Wall -g
OBJS = exprtest.o driver.o parser.tab.o scanner.o

all: exprtest

driver.cpp: scanner.hpp driver.hpp

scanner.hpp: parser.tab.hpp

parser.tab.cpp: expression.hpp scanner.hpp driver.hpp

parser.tab.hpp parser.tab.cpp: parser.ypp
	bison parser.ypp

scanner.cpp: scanner.ll scanner.hpp
	flex -t scanner.ll > scanner.cpp

exprtest: ${OBJS}
	${CC} ${CFLAGS} -o $@ ${OBJS}   

exprtest.o: exprtest.cpp
	${CC} ${CFLAGS} -c $<

driver.o: driver.cpp scanner.hpp driver.hpp
	${CC} ${CFLAGS} -c $<

scanner.o: scanner.cpp parser.tab.hpp scanner.hpp
	${CC} ${CFLAGS} -c $<

parser.tab.o: parser.tab.cpp parser.tab.hpp expression.hpp scanner.hpp driver.hpp
	${CC} ${CFLAGS} -c $<

clean:
	rm -f *.o *~ core tmp
	rm -f *.d *~ core tmp
	rm -f *.hh *~core tmp
	rm -f *.gch *~core tmp
	rm -f parser.tab.cpp
	rm -f parser.tab.hpp
	rm -f scanner.cpp
	rm exprtest
