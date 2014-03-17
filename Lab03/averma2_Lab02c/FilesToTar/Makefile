all: StatisticsProcessor
StatisticsProcessor: Tester.o StatisticsProcessor.o Driver.o
	g++ -Wall -Wextra -g -std=c++0x StatisticsProcessor.o Tester.o -o Lab03Test
	g++ -Wall -Wextra -g -std=c++0x StatisticsProcessor.o Driver.o -o Lab03
Tester.o: Tester.cpp
	g++ -g -c -W -Wextra -Wall -std=c++0x Tester.cpp -o Tester.o
Driver.o: Driver.cpp
	g++ -g -c -W -Wextra -Wall -std=c++0x Driver.cpp -o Driver.o
StatisticsProcessor.o: StatisticsProcessor.cpp StatisticsProcessor.h
	g++ -g -c -W -Wextra -Wall -std=c++0x StatisticsProcessor.cpp -o StatisticsProcessor.o
clean:
	rm *.o StatisticsProcessor *~ Lab03 Lab03Test
