#ifndef STATISTICS_PROCESSOR_H
#define STATISTICS_PROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

class StatisticsProcessor{
	private:
		//Add your private data members and functions here
		int* statArray;
		int arraySize;
		void Push_back(int);
		int arrayCapacity;
	public:
		StatisticsProcessor();
		StatisticsProcessor(const StatisticsProcessor &s);
		StatisticsProcessor& operator=(const StatisticsProcessor &rhs);
		~StatisticsProcessor();
		void loadData(std::string file_name);
		friend std::istream& operator>>(std::istream &in, StatisticsProcessor &s);
		bool empty();
		void clear();
		int computeMin();
		int computeMax();
		float computeMean();
		int computeRange();
		float computeSDev();
		friend std::ostream& operator<<(std::ostream &out, StatisticsProcessor &s);
		
};

#endif //STATISTICS_PROCESSOR_H
