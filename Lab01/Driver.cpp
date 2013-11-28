#include <iostream>
#include <cstdlib>

#include "Lab01.h"

int main(int argc, char** argv)
{
	Lab01* testobj = new Lab01;
	testobj->question1a({5,6,7}, 3)
	
	cout << question1a({5,6,7}, 3);
	cout << question2(2, 4);
	cout << question3("abc", "bcd");
	cout << question4("abcd");
	cout << question5;
	cout << question6;

	delete testobj;
	return 0;
}
