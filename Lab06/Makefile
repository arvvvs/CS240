all: tester
tester: Driver.o Random.o LinkedList.o
	g++ -Wall -Wextra -g -std=c++0x LinkedList.o Random.o Driver.o -o lab06rand
Random.o: Random.cpp 
	g++ -g -c -W -Wextra -Wall -std=c++0x Random.cpp -o Random.o
LinkedList.o: LinkedList.cpp 
	g++ -g -c -W -Wextra -Wall -std=c++0x LinkedList.cpp -o LinkedList.o
Driver.o: Driver.cpp 
	g++ -g -c -W -Wextra -Wall -std=c++0x Driver.cpp -o Driver.o
clean:
	rm *.o  lab06rand *~

