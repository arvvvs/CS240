all: StatisticsProcessor
StatisticsProcessor: Tester.o StatisticsProcessor.o
	g++ -Wall -Wextra -g -std=c++0x StatisticsProcessor.o Tester.o -o averma2_lab03c
Driver.o: Driver.cpp
	g++ -g -c -W -Wextra -Wall -std=c++0x Tester.cpp -o Tester.o
StatisticsProcessor.o: StatisticsProcessor.cpp StatisticsProcessor.h
	g++ -g -c -W -Wextra -Wall -std=c++0x StatisticsProcessor.cpp -o StatisticsProcessor.o
clean:
	rm *.o StatisticsProcessor *~
