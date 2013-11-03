CC = gcc
OPTIONS = -O2 -g -Wall
INCLUDES = -I .
OBJS = main.o prime.o
TARGET = prime
.PHONY: all clean

all: ${OBJS}
	@echo "Building.."
	${CC} ${OPTIONS} ${INCLUDES} ${OBJS} -o ${TARGET}
main.o: main.c prime.h
	gcc -I . -c main.c
prime.o: prime.c prime.h
	gcc -I . -c prime.c
clean:
	rm -rf *.o
	rm ${TARGET}
