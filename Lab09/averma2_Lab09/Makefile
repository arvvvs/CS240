all: Lab09
Lab09: Driver.o Lab09.o
	g++ -Wall -Wextra -g -std=c++0x Lab09.o Driver.o -o Lab09
Driver.o: Driver.cpp
	g++ -g -c -W -Wextra -Wall -std=c++0x Driver.cpp -o Driver.o
Lab09.o: Lab09.o
	ar -rcs Lab09.a Lab09.o
	rm Lab09.o
Lab09.o: preLab09.cpp preLab09.h
	g++ -g -c -W -Wextra -Wall -std=c++0x preLab09.cpp -o Lab09.o
clean:
	rm *.o Lab09  *~
