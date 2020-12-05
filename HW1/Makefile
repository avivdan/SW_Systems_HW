CC = gcc
FLAGS = -Wall -g
AR = ar

all : mymathd.so mymaths.a maind mains
mymaths: mymaths.a
mymathd: mymathd.so
<<<<<<< HEAD

=======
>>>>>>> 605165372d0998c4d9a8ecb0a528faec2c947b03

#static
mains: main.o mymaths.a
	$(CC) $(FLAGS) -o mains main.o basicMath.o power.o
 
#dynamic
maind: main.o mymathd.so
	$(CC) $(FLAGS) -o maind main.o ./mymathd.so

#static libary creator
mymaths.a :  basicMath.o power.o
	$(AR) -rcs mymaths.a basicMath.o power.o 

#dynamic libary creator
mymathd.so: basicMath.o power.o
	$(CC) -shared -o mymathd.so basicMath.o power.o

main.o	: main.c myMath.h 
	$(CC) $(FLAGS) -c main.c

basicMath.o : basicMath.c myMath.h 
	$(CC) $(FLAGS) -c basicMath.c 

power.o : power.c myMath.h
	 $(CC) $(FLAGS) -c power.c

.PHONY: clean

clean: 
	rm -f *.o *.so *.a maind mains

