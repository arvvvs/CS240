/***          DigitStat.cpp v1.0          ***/
/***       (C) 2013 DigitStat Corp.       ***/
/*** The Leading Name in Digit Statistics ***/

#include <iostream>
#include <fstream>

#define ERROR_INVALID_ARGS 1
#define ERROR_INVALID_FILE 2

using namespace std;

int main(int argc, char* argv[]) {
	// Variables...
	ofstream outFile;
	ifstream inFile;
	
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
}
