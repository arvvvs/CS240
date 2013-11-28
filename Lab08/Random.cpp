#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	/** On a computer random number generation is not 
	  truly random. It is actually calculated following an
	  algorithm that tries to approximate random numbers
	  using a pseudo-random number generator.

	  This generation requires what is referred to as a seed
	  value. Two programs with the same seed will generate
	  the same sequence of "random" numbers. As a result, we
	  lose the illusion of randomness if a bad seed is chosen.

	  To fix this problem, we seed based upon the time the
	  program is run -- restoring the illusion of randomness as
	  it will be very difficult to have two programs start with
	  the same seed value.
	**/

	srand(time(NULL));

	int random_int = rand();
	cout << "random int: " << random_int << endl;

	unsigned int random_unsigned = (unsigned) rand();
	cout << "random unsigned: " << random_unsigned << endl;

	float random_float = (float) rand();
	cout << "random float: " << random_float << endl;

	double random_double = (double) rand();
	cout << "random double: " << random_double << endl;
}
