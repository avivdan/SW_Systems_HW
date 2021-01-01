CC = gcc
FLAGS = -Wall -g

all:mainso mainsf

#static
mainsf: txtfind.o 
	$(CC) $(FLAGS) -o mainsf txtfind.o 

mainso: isort.o
	$(CC) $(FLAGS) -o mainso isort.o


isort.o : isort.c	
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean

clean:
	rm -f *.o mainso mainsf
	
