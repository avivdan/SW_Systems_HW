CC = gcc
FLAGS = -Wall -g
AR = ar

all : BankProg.a mains

#static
mains: main.o BankProg.a
	$(CC) $(FLAGS) -o mains main.o myBank.o

#static libary creator
BankProg.a :  myBank.o
	$(AR) -rcs BankProg.a myBank.o 

main.o : main.c myBank.h
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY: clean

clean:
	rm -f *.o *.a mains

