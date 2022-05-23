OBJS = game.o grid.o user.o
//*CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)//

all: main

main: game.o game_mode.o user.o grid.o main.cpp
	g++ game.o game_mode.o user.o grid.o main.cpp -o main

user.o: user.h user.cpp
	g++ user.cpp -c

grid.o: grid.h grid.cpp
	g++ grid.cpp -c
	
game_mode.o: game_mode.h game_mode.cpp
	g++ game_mode.cpp -c
	
game.o: game.h game.cpp user.cpp grid.cpp
	g++ game.cpp -c

clean:
	rm -rf *.o
