#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <ctime>
#include <cstdlib>
class Random{
	public:
		Random();
		Random(const Random& rhs);
		const Random& operator=(const Random& rhs);
		friend std::ostream& operator<<(std::ostream& o, Random& r);
		~Random();
	private:
		int size;
		int* rand_data;
};



#endif //RANDOM_H
