/***          DigitStat.cpp v1.0          ***/
/***       (C) 2013 DigitStat Corp.       ***/
/*** The Leading Name in Digit Statistics ***/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "DigitStat.h"

#define ERROR_INVALID_ARGS	1
#define ERROR_INVALID_FILE	2
#define ERROR_BAD_FORMAT	3

using namespace std;

int main(int argc, char* argv[]) {
	// Variables...
	ofstream outFile;
	ifstream inFile;
	LinkedNode *head;
	int integers = 0, fractions = 0;
	int firstDigCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	if (argc != 3) { // Check argument count...
		cout << "Format: " << argv[0] << " infile outfile" << endl;
		return ERROR_INVALID_ARGS;
	}
	else { // Check for good files...
		inFile.open(argv[1]);
		outFile.open(argv[2], ofstream::trunc);
		
		if (!inFile.good() || !outFile.good()) {
			cout << "Invalid file(s)! (In: " << argv[1] << ", out: " << argv[2] << ")" << endl;
			return ERROR_INVALID_FILE;
		}
	}

	// So now our input and output files are initialized, we need to read the numbers in one by one and insert them into a doubly linked list.
	for (string line; getline(inFile, line); ) {
		// Convert the string into a stringstream
		istringstream ss(line);
		// And read it into a double. Exit with a bad format if we can't read a double.
		double val;
		if (!(ss >> val))
			return ERROR_BAD_FORMAT;

		// Now we create a new LinkedNode to store our value...
		LinkedNode *temp = new LinkedNode;
		temp->value = &line;
		temp->actualValue = val;

		//Counting first digit occurrences.
		firstDigCount[(int)line.at(0)]++;

		//Checking whether or not the value is a fraction or an integer
		if(val == (int)val)
			integers++;
		else 
			fractions++;

		// And we set up the DigitCounts struct.
		// Note: b + 30 is converting byte b into a char with a value of '0', '1', etc
		// "count" is from the algorithms import, and operates on templated collections.
		// Since string is a templated collection of chars, this works.
		for (byte b = 0; b < 10; b++) { // Iterate 0-9
			temp->digitCounts[b] = count(line.begin(), line.end(), (b + 30));
		}

		// Now we need to insert this in the current array. In a sorted fashion, mind you.
		if (head == nullptr) // CASE: list is empty.
			head = temp;
		else { // CASE: List is not empty.

			// Determine the node we need to insert before.
			LinkedNode *before = head;
			while (*before->actualValue < val && before->next != nullptr)
				before = before->next;

			if (before->actualValue < val && before->next == nullptr) { // CASE: insert on tail
				before->next = temp;
				temp->prev = before;
			}
			else { // CASE: insert in the middle or at the head.
				temp->next = before;
				temp->prev = before->prev;

				if (before == head)
					head = temp;

				if (before->prev != nullptr)
					before->prev->next = temp;
				before->prev = temp;
			}
		}
	}

	/******   TODO:   ******/
	// Output what we have so far to the file.
	// Prompt console for input
	// We're almost done!


	/* Start of file output */

	//Printing ordered list to the outfile.
	LinkedNode* holder = head;
	while(holder != nullptr) {

		outFile << holder->value << "\n";

		//Need to specify C++11 for compiling
		outFile << "[0-9]: ";
		for(int &x : holder->digitCounts) 
			outFile << *x << ", ";

		outFile << "\n";

		holder = holder->next;
	}

	//Printing integer value occurrence
	outFile << "There were " << integers << " integer values in the data set.\n";

	//Printing fraction occurrence
	outFile << "There were " << fractions << " fractional values in the data set.\n";

	//Printing first digit occurrence distrivbution.
	outFile << "Distribution of first digit [0-9]: \n";
	for(int &x : firstDigCount)
		outFile << *x << ", ";

	outFile << "\n";

	outFile.close();

	/*End of file output*/

}
