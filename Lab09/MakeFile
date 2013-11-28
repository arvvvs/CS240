all: makeInteresting
makeInteresting: Driver.o makeInteresting.o
	g++ -Wall -Wextra -g -std=c++0x makeInteresting.o Driver.o -o averma2_lab04c
Driver.o: Driver.cpp
	g++ -g -c -W -Wextra -Wall -std=c++0x Driver.cpp -o Driver.o
makeInteresting.o: makeInteresting.cpp makeInteresting.h
	g++ -g -c -W -Wextra -Wall -std=c++0x makeInteresting.cpp -o makeInteresting.o
clean:
	rm *.o  averma2_lab04 *~
