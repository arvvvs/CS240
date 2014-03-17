all: tester
tester: Driver.o Tester.o
	g++ -Wall -Wextra -g -std=c++0x Tester.o -o tester
	g++ -Wall -Wextra -g -std=c++0x Driver.o -o grader 
Tester.o: Tester.cpp  LinkedList.cc LinkedList.h
	g++ -g -c -W -Wextra -Wall -std=c++0x Tester.cpp -o Tester.o
makeInteresting.o: Driver.cpp LinkedList.h LinkedList.cc
	g++ -g -c -W -Wextra -Wall -std=c++0x Driver.cpp -o Driver.o
clean:
	rm *.o  grader driver *~
