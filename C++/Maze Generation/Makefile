maze : main.o Maze.o Cell.o
g++ -o maze main.o Maze.o Cell.o

main.o : main.cpp Maze.h
g++ -c main.cpp

Maze.o : Maze.cpp Maze.h Cell.h
g++ -c Maze.cpp

Cell.o : Cell.cpp Cell.h
g++ -c Cell.cpp
