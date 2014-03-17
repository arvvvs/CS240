#include "Random.h"

using namespace std;

Random::Random(){
	size = rand()%100;
	if(size > 0){
		rand_data = new int[size];
		for(int i = 0; i < size; i++){
			rand_data[i] = rand();
		}
	} else {
		rand_data = nullptr;
	}
}

Random::Random(const Random& rhs){
	size = rhs.size;
	rand_data = new int[size];
	for(int i = 0; i < size; i++){
		rand_data[i] = rhs.rand_data[i];
	}
}

const Random& Random::operator=(const Random& rhs){
	//alias test
	if(&rhs != this){
		if(rand_data != nullptr){
			delete[] rand_data;
		}
		if(rhs.size > 0){
			size = rhs.size;
			rand_data = new int[size];
			for(int i = 0; i < size; i++){
				rand_data[i] = rhs.rand_data[i];
			}
		} else {
			rand_data = nullptr;
			size = 0;
		}
	}
	return *this;
}

ostream& operator<<(ostream& o, Random& r){
	if(r.size > 0){
		o << "There are " << r.size << " pieces of random data: " << endl;
		for(int i = 0; i < r.size; i++){
			o << "\t" << r.rand_data[i];
			if( i%5 == 4){
				o << endl;
			}
		}
		o << endl;
	} else {
		o << "Randomly had no random data." << endl;
	}
	return o;
}

Random::~Random(){
	delete[] rand_data;
}
