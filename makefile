C	=	g++
A	=	-g -Wall -std=c++0x
O	=	DigitStat

all: DigitStat.o
	$C $A -o $O DigitStat.o

DigitStat.o: DigitStat.cpp
	$C $A -c DigitStat.cpp

clean
	rm -rf *.o $O
