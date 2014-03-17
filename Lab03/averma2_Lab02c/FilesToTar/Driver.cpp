#include<iostream>
#include "StatisticsProcessor.h"
int main(){
	StatisticsProcessor SP1;
	SP1.loadData("testdata");
	std::cout<<"I1"<<std::endl;
	std::cout<<SP1<<std::endl;
	StatisticsProcessor SP2=SP1;
	std::cout<<"I2"<<std::endl;
	std::cout<<SP2<<std::endl;
	SP1.loadData("testdata2");
	std::cout<<"M1:"<<std::endl;
	std::cout<<SP1<<std::endl;
	std::cout<<"M2:"<<std::endl;
	std::cout<<SP2<<std::endl;
	StatisticsProcessor SP3;
	SP3.loadData("testdata3");
	SP3=SP1;
	SP1.clear();
	std::cout<<"F1:"<<std::endl;
	std::cout<<SP1<<std::endl;
	std::cout<<"F2:"<<std::endl;
	std::cout<<SP2<<std::endl;
	std::cout<<"F3:"<<std::endl;
	std::cout<<SP3<<std::endl;
}
