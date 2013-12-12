C = g++
F = -g -Wextra -Wall -std=c++0x
O = Graph

all: Graph.o Driver.o
	$C $F -o $O Graph.o Driver.o

Graph.o: Graph.cpp Graph.h
	$C $F -c Graph.cpp

Driver.o: Driver.cpp
	$C $F -c Driver.cpp

clean:
	rm -rf *.o $O
