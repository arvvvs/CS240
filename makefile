C = g++
F = -g -Wextra -Wall -std=c++0x
O = Graph

all: Graph.o
	$C $F -o $O Driver.o

Graph.o: Graph.cpp Graph.h
	$C $F -c Graph.cpp

clean:
        rm -rf *.o $O