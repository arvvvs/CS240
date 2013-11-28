all: makeInteresting
makeInteresting: Driver.o lab08.o Skeleton.cpp
	g++ -Wall -Wextra -g -std=c++0x lab08.o Driver.o -o palindrome
	g++ -Wall -Wextra -g -std=c++0x  Skeleton.cpp -o lab08
Driver.o: Driver.cpp
	g++ -g -c -W -Wextra -Wall -std=c++0x Driver.cpp -o Driver.o
makeInteresting.o: lab08.cpp lab08.h  
	g++ -g -c -W -Wextra -Wall -std=c++0x lab08.cpp -o lab08.o
clean:
	rm *.o  averma2_lab08 *~
