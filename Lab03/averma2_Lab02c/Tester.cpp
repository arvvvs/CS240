#include "StatisticsProcessor.h"

int main(void){

	std::cout << "Making an empty object." << std::endl;
	StatisticsProcessor st;
	try{
		st.computeMin();
	} catch (std::domain_error e){
		std::cout << "Domain error -min- caught" << std::endl;
	}
	try{
		st.computeMax();
	} catch (std::domain_error e){
		std::cout << "Domain error -max- caught" << std::endl;
	}
	try{
		st.computeRange();
	} catch (std::domain_error e){
		std::cout << "Domain error -range- caught" << std::endl;
	}
	try{
		st.computeMean();
	} catch (std::domain_error e){
		std::cout << "Domain error -mean- caught" << std::endl;
	}
	try{
		st.computeSDev();
	} catch (std::domain_error e){
		std::cout << "Domain error -sdev- caught" << std::endl;
	}
	
	std::cout << st << std::endl;
	st.loadData("dataset");
	
	if(st.computeMin() != 2) { 
		std::cout << "Min not computed correctly." << std::endl;
		return -1;
	}
	if(st.computeMax() != 9) {
		std::cout << "Max not computed correctly." << std::endl;
		return -1;
	}
	if(st.computeRange() != 7) {
		std::cout << "Range not computed correctly." << std::endl;
		return -1;
	}

	std::cout << st << std::endl;
	std::cout << "For testing purposes, do not add any data." << std::endl;
	std::cout << "Select a letter or negative number as the number of elements we want to add." << std::endl;
	std::cin >> st;
	std::cout << st << std::endl;
	
	
	if(st.computeSDev() != 2.0f){
		std::cerr << "Did not compute standard deviation correctly." << std::endl;
		return -1;
	}


	std::cout << "Now, to test this, add some data." << std::endl;
	std::cout << "Eight elements:" << std:: endl;
	std::cout << "9, 7, 5, 5, 4, 4, 4, 2" << std::endl;
	std::cout << "Make at least one mistake." << std::endl;

	std::cin >> st;
	std::cout << st << std::endl;

	st.loadData("dataset");
	std::cout << st << std::endl;
	
	return 0;
}
