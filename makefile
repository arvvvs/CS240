<<<<<<< HEAD
C	=	g++
A	=	-g -Wall -std=c++0x
O	=	DigitStat

all: DigitStat.o
	$C $A -o $O DigitStat.o

DigitStat.o: DigitStat.cpp
	$C $A -c DigitStat.cpp
=======
C = g++
F = -g -Wextra -Wall -std=c++0x
O = Graph

all: Graph.o Driver.o
	$C $F -o $O Graph.o Driver.o

Graph.o: Graph.cpp Graph.h
	$C $F -c Graph.cpp

Driver.o: Driver.cpp
	$C $F -c Driver.cpp
>>>>>>> e746c2ff96b2fae8f6caf2a5ea2cb41c2ecd2aca

clean:
	rm -rf *.o $O
