#include <string>
#include <fstream>
#include "StatisticsProcessor.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <limits.h>
#include <stdexcept>

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
		
		try{
		if(this !=&rhs){
			//statArray=rhs.statArray;
			arraySize=rhs.arraySize;
			arrayCapacity=rhs.arrayCapacity;
			delete[] statArray;
			statArray=new int[arraySize];
			
			for(int i=0; i<arraySize; i++){
				statArray[i]=rhs.statArray[i];
				

			}}		
		return *this;}
		catch(std::domain_error e) {
			std::cout<<"Domain error"<<std::endl;
		}
}

std::istream& operator>>(std::istream &in , StatisticsProcessor &s){
	int arraySize= s.arraySize;
	int* statArray= s.statArray;
	int inputArraySize;
	
	do{
	in>>inputArraySize;
	in.clear();
	in.ignore();
	
	}while(!in);
	
	for(int i=0; i<inputArraySize; i++)
	{
		int tempInsert;
		//std::cin>>statArray[i+inputArraySize];
		do{
		in>>tempInsert;
		in.clear();
		in.ignore();
	//	in>>tempInsert;
		
		}while(!in);
	statArray[i+inputArraySize]=tempInsert;}
	arraySize+=inputArraySize;
	return in;


}
void StatisticsProcessor::loadData(std::string file_name){
	//const char* stringLoad=file_name.c_str();
	std::ifstream iFile;
	iFile.open(file_name);
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
		int temp;
		int temp2;
		iFile>>temp;
		for(int i=0; i<temp; i++){
			iFile>>temp2;
			//std::cout<<"temp is"<<temp2<<std::endl;
			Push_back(temp2);			
		}

	}
	iFile.close();
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




bool StatisticsProcessor::empty() const{
	if(statArray==NULL){
		return true;
	}
	else{
		return false;
	}
}
void StatisticsProcessor::clear(){
	delete[] statArray;
	arraySize=0;
	arrayCapacity=0;
	statArray=nullptr;
}

int StatisticsProcessor::computeMin() const{
	int temp=0;
	if (statArray!=NULL){
	temp=statArray[0];
	//std::cout<<"array at [0] is (min) "<<statArray[0]<<std::endl;
	for(int i=0; i<arraySize; i++){
		if(statArray[i]<temp){
			temp=statArray[i];
		}

	}
		return temp;
	}

	else{
		std::cout<<"domain error"<<std::endl;

	}
}






int StatisticsProcessor::computeMax() const{
	int temp=0;
	if(statArray!=NULL){
	temp=statArray[0];
	for(int i=0; i<arraySize; i++){
		if(statArray[i]>temp){
			temp=statArray[i]; 
		}
	}
	return temp;
	}
	else{
		std::cout<<"Domain Error"<<std::endl;
		return temp;
	}
}


float StatisticsProcessor::computeMean() const{
	if(statArray!=NULL){
	float temp=0;
	for(int i=0; i<arraySize; i++){
		temp+=statArray[i];
	
	}
	float arraySize2=arraySize;
	return temp/arraySize2;
	}
	else{
		std::domain_error("set is empty");
}}
int StatisticsProcessor::computeMode() const{

	int placeBegin=0;
	int placeEnd=arraySize-1;
	int temp1=1;
	int temp2=1;
	bool life=false;
	
	while(life=false){
	for(int i=0; i<arraySize; i++){

		if(statArray[placeBegin]==statArray[i]){
		temp1++;

		}

	}
	for(int i=0; i<arraySize; i++){
		if(statArray[placeEnd]==statArray[i]){
			temp2++;
		}


	}
	if(temp1>temp2){
		placeEnd++;
		temp2=1;
	}
	else if(temp2>temp1){
		placeBegin--;
		temp1=1;
	}
	else if(temp1==temp2){
		life=false;
	}
	
	


}
	std::cout<<statArray[placeEnd]<<std::endl;
	return statArray[placeBegin];

}

/*int StatisticsProcessor::computeMean(){
	int temp=0;
	for(int i=0; i<arraySize; i++){
		temp+=statArray[i];
	}
	return temp/arraySize;


}
*/

int StatisticsProcessor::computeRange() const{
return StatisticsProcessor::computeMax()-StatisticsProcessor::computeMin();



}


float StatisticsProcessor::computeSDev() const{
	float mean=computeMean();	
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
	std::ofstream myFile;
	myFile.open("readOut.txt");
	for(int i=0; i<arraySize; i++){
		if(i%4==0){
			out<<'\n';
			out<<statArray[i]<<'\t';
		}
		else{
		out<<statArray[i]<<'\t';
		}
		myFile<<statArray[i]<<std::endl;
	}
	myFile.close();
	return out;
	} 
