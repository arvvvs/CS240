#include <iostream>
#include <string>
#include <cctype>
#include "lab08.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <ctype.h>
using namespace std;

lab08::lab08(string ifile_name){
  lineCount=0;
  dLines=0;
  pLines[lineCount];
  iFile.open(ifile_name.data());
  stringArray[0];
  reverseArray[0]; 
  if(!iFile.is_open()){
    std::cerr<<"error in opening files";
  }} 
void lab08::print(){
  cout<<"in print function total lines are: "<<lineCount<<endl;
  for(int i=0; i<3; i++){
    cout<<"final print (line number)  "<<pLines[i]<<endl;
  }

}
void lab08::run(){
  string temp;
  string noPunct;
  string lowerString;
  char* stringArray;
  char* reverseArray;
  string tempA;
    while(std::getline(iFile, temp)){
    string temp2;
    temp2=temp;
    lineCount++; 
   cout<<"1 "<<lineCount<<endl; 
    // if(isalnum(temp)==true){
    int j=0; 
      while(isalnum(temp[j]))j++;
       if(j>0){
        (string) temp;  
//          string noPunct = removePunctuation(temp);

          string lowerString = makeLower(temp);  
          cout<<"lower case string is "<<lowerString<<endl;
          string noPunct=removePunctuation(lowerString);
          cout<<"string without punctuation "<<noPunct<<endl;
          makeArray(noPunct);
          tempA=noPunct;
        }
       //remove punctuation and spaces and make lower
     //append string to array
  
   
  else{
    //append string to array
    makeArray(temp);
    tempA=noPunct;
   }
  //create a reverse string array
  reverse(tempA);
  
  int i=0;
  if(stringArray==reverseArray){
   cout<<"LOOK HERE EHERE 2 "<<lineCount<<endl;
    pLines[i]=lineCount;
    i++;
    dLines++;
  }*/
//  if(strcmp(stringArray, reverseArray)==0){
 //   pLines[i]=lineCount;
   // i++;
   // dLines++;
 // } 
  //if(ispanlindrome(arraystring)){;
  //append line number to line array
  //}
   }
  //print(arrayoflines)
  print();
  }

/*void lab08::print(){
  for(i=0; i<lineCount; i++){
    cout<<pLines[i]<<endl;
  }


}*/
/*
void lab08::reverse(const string& carrier){
  
 int arrayLength=carrier.size();
  cout<<"array length in function reverse is  "<<arrayLength<<endl;
  for(int i=0; i<arrayLength; i++){
    reverseArray[i]=stringArray[i];
  }

//reverseArray=stringArray; 
 int start=0;
  int end=arrayLength;
  
  while(start<end){
    end--;
    cout<<"swapping"<<endl;
    swap(reverseArray[start], reverseArray[end]);
    start++;
  } 
 // string temp;
  //temp(reverseArray);
  //  for(int i=0; i<arrayLength; i++){
    //  temp.append(reverseArray[i]);
   // }
    //cout<<"reverse string is  "<<temp<<endl;
}
void lab08::swap(char& v1, char& v2){
  char temp=v1;
  v1=v2;
  v2=temp;

}
void lab08::makeArray(const string& nArrayString){
  stringArray [nArrayString.size()];
  
  for(int i=0; i<nArrayString.size(); i++){
      stringArray[i]=nArrayString[i];
  }
}
string lab08::removePunctuation(const string& withPunc){
// string punctuation(",;:.?!'\" ");
  string noPunct;
  int pLength=withPunc.length();
  string punctuation [8]={",",";",".","?","!"," "};
  string punctuation1=",;:.?!'\" ";
  int found=0;
  for(int i=0; i<pLength; i++){
    found=withPunc.find(punctuation[i]);
    while(found!=-1){
      noPunct.replace(found, punctuation[i].length(), "");
      found=noPunct.find(punctuation[i], found);
    }
 
  string aChar=withPunc.substr(i,1);
  int location=punctuation1.find(aChar,0);
  //cout<<"initial string is "<<withPunc<<endl;
  if(location<0 || location>=pLength){
    noPunct=noPunct+aChar;}
   // cout<<"changes with punctuation "<<noPunct<<endl;
 // }
   }

  return noPunct;
  }
string lab08::makeLower(const string& higherString){
  string temp(higherString);
  string temp2(higherString);
  char c;
  for(int i=0; i<higherString.length(); i++){
    c=temp2[i];
    temp[i]=::tolower(c);
//    return temp;
    }
  return temp;
  }
bool lab08::arrayEqual(const string& s){
  bool hello=true;
  while(hello==true){
  for(int i=0; i<s.size(); i++){
    if(stringArray[i]!=reverseArray[i]){
      hello==false;
      break;
    } 

  }
}return hello;
  }*/



