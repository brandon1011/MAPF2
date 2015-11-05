TARGET=mapf
CC=g++
CFLAGS=-g -Wall -Wextra -std=c++11 -w
SRCS=src/Grid.cpp
TRASH=${TARGET}

ifdef GPROF
CFLAGS += -pg -O2
TRASH += gmon.out
endif

all: default
	${CC} ${CFLAGS} test/grid_test1.cpp *.o -o ${TARGET} 
debug:
	${CC} ${CFLAGS} -c debug.cpp
default:
	${CC} ${CFLAGS} -c ${SRCS}
clean:
	rm *.o ${TRASH}
