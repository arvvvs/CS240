#include <string>
#include <fstream>
#include "StatisticsProcessor.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <limits.h>
StatisticsProcessor::StatisticsProcessor(){
	arraySize=0;
	statArray=0;
	arrayCapacity=0;
}
StatisticsProcessor::StatisticsProcessor(const StatisticsProcessor &s){
	arraySize=s.arraySize;
	arrayCapacity=s.arrayCapacity;
	std::cout<<arraySize<<std::endl;
	statArray= new int[arraySize];
	if (arraySize>0){
	for(int i=0; i<arraySize; i++){
		statArray[i]=s.statArray[i];
		std::cout<<arraySize<<std::endl;
		std::cout<<statArray[i]<<std::endl;
		}	
	}
	else{
	std::cout<<"Incorrect Size"<<std::endl;
	exit(EXIT_FAILURE);
	}
}



StatisticsProcessor& StatisticsProcessor::operator=(const StatisticsProcessor &rhs){
		
		if(rhs.arraySize>=0){
		if(this !=&rhs){
			//statArray=rhs.statArray;
			arraySize=rhs.arraySize;
			arrayCapacity=rhs.arrayCapacity;
			statArray=new int[arraySize];
			for(int i=0; i<arraySize; i++){
				statArray[i]=rhs.statArray[i];
				

			}}		
		return *this;}
		else{
			std::cout<<"Incorrect size inputted"<<std::endl;
			exit(EXIT_FAILURE);
		}
}

std::istream& operator>>(std::istream &in , StatisticsProcessor &s){
	int arraySize= s.arraySize;
	int* statArray= s.statArray;
	int inputArraySize;
	in>> inputArraySize;
	if(!std::cin){
	std::cout<<"please input a correct array size"<<std::endl;
	}
	else{
	for(int i=0; i<inputArraySize; i++)
	{
		int tempInsert;
		//std::cin>>statArray[i+inputArraySize];
		in>>tempInsert;
		while(!std::cin){
		std::cout<<"please input a correct number"<<std::endl;
		in.clear();
		in>>tempInsert;
		
		}	statArray[i+inputArraySize]=tempInsert;}
	arraySize+=inputArraySize;}
	return in;


}
void StatisticsProcessor::loadData(std::string file_name){
	//const char* stringLoad=file_name.c_str();
	std::ifstream iFile;
	iFile.open(file_name);
	std::cout<<"in loadData function"<<std::endl;
	//std::string stringLoaded;
	//std::getline(iFile, stringLoaded);
	//string stream look it up to use with getline and with stringloaded
	//while loop to input all the data into the array after the first ato and after you setup the array
	//const char* stringLoader=stringLoaded.c_str();
	/*arraySize=atoi(stringLoader);
	statArray=new int[arraySize];
	int i;
	while(std::getline(file_name, stringLoaded)){
		statArray[i]=atoi(stringLoaded);
	i++;*/
	
	if(iFile.is_open()){
		std::cout<<"iFile is open"<<std::endl;
		int temp;
		int temp2;
		iFile>>temp;
		for(int i=0; i<temp; i++){
			iFile>>temp2;
			//std::cout<<"temp is"<<temp2<<std::endl;
			Push_back(temp2);			

		}

	}
}
StatisticsProcessor::~StatisticsProcessor(){
	delete[] statArray;



}
void StatisticsProcessor::Push_back(int e){
arraySize++;
	if(statArray==NULL){
		arrayCapacity=1;
		statArray= new int[arraySize];
		statArray[0]=e;

	}
	else if(arraySize>=arrayCapacity){
		arrayCapacity=arrayCapacity*2;
		int* temp= new int[arrayCapacity];
		for(int i=0; i<arraySize; i++){
			temp[i]=statArray[i];
			temp[arraySize-1]=e;
			
		}
		for(int i=arraySize; i<arrayCapacity; i++){
			temp[i]=1;


		}
		delete[] statArray;
		statArray=temp;
	}
	else{
		statArray[arraySize-1]=e;
	

	}




}

/*
void  StatisticsProcessor::Push_back(int e){

//std::cout<<"array Size is:  "<<arraySize<<std::endl;

		
	int arrayCapacity=arraySize;
		

		arraySize++;

		if(statArray==NULL){

			

		//	arraySize=1;

			statArray= new int[arraySize];

			statArray[0]=e;

		}

		

		else if(arraySize>=arrayCapacity){


			int* temp=new int[arraySize];

			for(int i=0; i<arraySize; i++){

			//	std::cout<<"dynamic array at "<<i<<" is "<<statArray[i]<<std::endl;

				temp[i]=statArray[i];

				temp[arraySize-1]=e;				

			}


			

			delete[] statArray;

			statArray=temp;

			

		}

		else{

			statArray[arraySize-1]=e;



			}

		}
*/




bool StatisticsProcessor::empty(){
	if(statArray==NULL){
		return true;
	}
	else{
		return false;
	}
}
void StatisticsProcessor::clear(){
	for(int i=0; i<arraySize; i++){
		statArray[i]=0;
	}
	delete[] statArray;
	arraySize=0;
}

int StatisticsProcessor::computeMin(){
	if (statArray!=NULL){
	int temp=statArray[0];
	//std::cout<<"array at [0] is (min) "<<statArray[0]<<std::endl;
	for(int i=0; i<arraySize; i++){
		if(statArray[i]<temp){
			temp=statArray[i];
		}

	}
		return temp;
	}

	else{
		std::cout<<"Array does not exist"<<std::endl;


	}
}






int StatisticsProcessor::computeMax(){
	if(statArray!=NULL){
	int temp=statArray[0];
	for(int i=0; i<arraySize; i++){
		if(statArray[i]>temp){
			temp=statArray[i]; 
		}
	}
	return temp;
	}
	else{
		std::cout<<"Array is NULL"<<std::endl;
	}
}


float StatisticsProcessor::computeMean(){
	float temp=0;
	for(int i=0; i<arraySize; i++){
		temp+=statArray[i];
	
	}
	float arraySize2=arraySize;
	return temp/arraySize2;
}

/*int StatisticsProcessor::computeMean(){
	int temp=0;
	for(int i=0; i<arraySize; i++){
		temp+=statArray[i];
	}
	return temp/arraySize;


}
*/

int StatisticsProcessor::computeRange(){
return StatisticsProcessor::computeMax()-StatisticsProcessor::computeMin();



}


float StatisticsProcessor::computeSDev(){
	float mean=StatisticsProcessor::computeMean();	
	float temp=0;
	float* floatStatArray=new float[arraySize];
	for(int i=0; i<arraySize; i++){
		floatStatArray[i]=statArray[i];

	}
	for(int i=0; i<arraySize; i++){
		temp+=pow((floatStatArray[i]-mean), 2);
	
	}
	float sDev=pow((temp/arraySize),.5);
	
	delete[] floatStatArray;
	return sDev;
}



std::ostream& operator<<(std::ostream &out, StatisticsProcessor &s){
	int arraySize= s.arraySize;
	int* statArray= s.statArray;
	for(int i=0; i<arraySize; i++){
		out<<statArray[i]<<std::endl;
	}
	return out;
	} 
