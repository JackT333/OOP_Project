OBJS = game.o grid.o user.o
//*CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)//

user.o: user.h user.cpp
	g++ user.cpp -c

grid.o: grid.h grid.cpp
	g++ grid.cpp -c
	
game.o: game.h game.cpp user.cpp grid.cpp
	g++ game.cpp -c

main: game.h user.h main.cpp
	g++ game.o user.o grid.o main.cpp -o main

all: main

clean:
	rm -rf *.o