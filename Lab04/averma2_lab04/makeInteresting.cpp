#include<iostream>
#include <string>
#include <cctype>
#include "makeInteresting.h"
#include <fstream>
#include <stdexcept>
#include<algorithm>
using namespace std;
makeInteresting::makeInteresting(string ifile_name, string ofile_name){
  lineCount=0;   
  totalFound=0;
  iFile.open(ifile_name.data());
  oFile.open(ofile_name.data());
  wFile.open(ofile_name.data());
  eLine=ifile_name;
   if(!iFile.is_open()|!oFile.is_open()){
    std::cerr<<"Error in opening files";
//    exit(EXIT_FAILURE);

  }
}
void makeInteresting::run(){
 // cout<<"in run"<<endl;
  replace();
  countWords();  
  saveFile();

}
makeInteresting::~makeInteresting(){

  

}
int makeInteresting::countWords(){
  /*string temp;
  string temp2;
  iFile.clear();
  while(getline(iFile, temp)){
    temp2.append(temp);
    temp2.append(" ");
    
  }
  lineCount=std::count_if(temp2.begin(), temp2.end(),
                        [](unsigned char c) {return std::isspace(c);})+1;
  cout<<"word count is"<<lineCount<<"\n";*/
  float wordCount=lineCount;
  cout<<"Processing "<< eLine<<" resulted in a change rate of "<<100*(totalFound/wordCount)<<"%"<<endl;
  return lineCount;
}
string makeInteresting::loadLines(){
//  cout<<"in load line"<<endl;
//  cout<<myLine<<'\n';
  string temp;
  string temp2;
  while(getline(iFile, temp)){
   myLine.append(temp);
   temp2.append(temp);
   myLine.append(" ");
   temp2.append("\n");
   myLine.append("\n");    
  }
 /* string tmp2;
  while(getline(iFile, temp)){
      tmp2.append(temp);
      tmp2.append(" ");
      cout<<tmp2<<'\n';  
  }*/
  lineCount=std::count_if(temp2.begin(), temp2.end(),
                          [](unsigned char c) { return std::isspace(c); })+1;
 // cout<<"word count is"<<lineCount<<'\n';

  // cout<<"total word cout is "<<total<<'\n';
//  cout<<myLine<<'\n';
  return myLine;
}
void makeInteresting::replace(){
 // cout<<"in replace"<<endl;
  loadLines(); 
  int found=0;
 // otalFound=0;
  for(int i=0; i<12; i++){
    found=myLine.find(original[i]);
    while(found!= -1){
      myLine.replace(found, original[i].length(), replacement[i]);
   //   cout<<"1 found"<<original[i]<<" at "<<found<<"\n"; 
      totalFound++;
      found= myLine.find(original[i], found+replacement[i].size());
      
      }
//   countWords();
  } 
/* int nFound=0;
    
      nFound=myLine.find(" \n");
  while(nFound!=-1){
      //myLine.erase(nFound-1);
      myLine.replace(nFound, nFound+1, "\n");
      nFound=myLine.find("\n", nFound+1);
  }
  cout<<totalFound<<"\n";
*/


/* string people= " people ";
  string wounded= " wounded ";
  string died= " died ";
  string bullets= " bullets ";
  string cannon= " cannon ";
  string bayonet= " bayonet ";
  string Prince= " Prince ";
  int positionP = myLine.find(people);
  int positionW = myLine.find(wounded);
  int positionD = myLine.find(died);
  int positionB = myLine.find(bullets);
  int positionC = myLine.find(cannon);
  int positionBa = myLine.find(bayonet);
  int positionPr = myLine.find(Prince);
  while(positionP || positionW || positionW || positionD || positionB ||positionC||positionBa || positionPr!=string::npos){
    

  }
*/
}
void makeInteresting::saveFile(){
  string temp;
/*  while(getline(myLine, temp)){
    temp.append(myLine);
    temp.append("\n");
  } 
  while(getline(temp, myLine)){
      myLine.append(temp);
      myLine.append("\n");
  }*/
 oFile<<myLine<<'\n';
  for(;;){
  if(iFile.eof())
    { 
      break;
    }
 
 oFile<<myLine<<endl;
  }
 /* while(getline(wFile, temp)){
    myLine.append(temp);
    myLine.pop_back();
    myLine.append("\n");
  }
  oFile.close();
  oFile.open(eLine.data(),fstream::trunc);
   
 oFile<<myLine<<'\n';
  for(;;){
    if(iFile.eof())
      {
        break;
      }
    oFile<<myLine<<endl;
  }*/ 
  iFile.close();
  oFile.close(); 
 // wFile.close();
}

