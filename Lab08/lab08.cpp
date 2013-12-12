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
#include <list>
using namespace std;

lab08::lab08(string ifile_name){
  lineCount=1;
  iFile.open(ifile_name.data());
  if(!iFile.is_open()){
    std::cerr<<"error in operning files";
  } 

}

bool lab08::isAlphaNumeric(const string& s){
bool flag=false;
//cout<<s<<endl;
for(int i=0; i<s.size(); i++){
//    cout<<i<<endl;
    if(isalnum(s[i])){
  //  cout<<"true"<<endl;
    bool flag=true;
   // cout<<flag<<endl;
    return true;
    break;
  }
}
  return false;
}
void lab08::run(){
  string temp;
    
  while(getline(iFile, temp)){
   if(isAlphaNumeric(temp)){
    //  cout<<temp<<endl;
//      lineCount++;
  //    string lowerString= makeLower(temp);
      string noPunct=removePunctuation(temp);
      makeList(noPunct); 
    //  cout<<endl;
   } 
  else{
   makeList(temp);
  // cout<<endl; 
  }
  
 reverseList=normalList;   
 reverseList.reverse();
   
/*  for(list<char>::iterator it=reverseList.begin(); it!=reverseList.end(); ++it){
    cout<<' '<<*it;
//    cout<<'\n';
  }
  cout<<endl;*/
//  if(isPalindrome()==true){
  if(normalList==reverseList){
    //cout<<"palindrome lines are:"<<endl;
    
//    cout<<temp<<endl;
    cout<<lineCount<<endl;
  }
lineCount++;}
//  normalList.clear();
//  reverseList.clear();
}
string lab08::makeLower(const string& higherString){
  string temp(higherString);
  string temp2(higherString);
  char c;
  for(int i=0; i<higherString.length(); i++){
    c=temp2[i];
    temp[i]=::tolower(c);
     }
//cout<<temp<<endl;
return temp;}

string lab08::removePunctuation(const string& withPunc){
    string noPunct;
    int pLength=withPunc.length();
    int found=0;
    string punctuation [8]={",",";",".","?","!"," "};
    
  //  string punctuation1=",;:.?![](){}<>-|/%!@#$%^&*()_-+=*-+""\\~`'\" ";
  //string punctuation1("~`!@#$%^&*()_-+=/*{}[]|<>-,;:.?!'\" ");  
 
  string punctuation1("\\!`@#%^&*()_-+=/*{}[]|<>-,;:.?!'\" ");  

for(int i=0; i<pLength; i++){
    
   // string punctuation1=",;:.?!'\" ";
    string aChar=withPunc.substr(i,1);
    int location=punctuation1.find(aChar,0);
    if(location<0 || location>=punctuation1.length()){
      noPunct=noPunct+aChar;
    }}    
  //cout<<noPunct<<endl;
  return noPunct;
}  
void lab08::makeList(const string& s){
   normalList.clear();
   list<char>::iterator iter;
    //cout<<"in makelist"<<endl; 
  for(int i=0; i<s.size();i++){
      normalList.push_back(s[i]);
   } /*  
  for(list<char>::iterator it=normalList.begin(); it!=normalList.end(); ++it){
    cout<<' '<<*it;
//    cout<<'\n';
  }

  for(list<char>::iterator it=reverseList.begin(); it!=reverseList.end(); ++it){
    cout<<' '<<*it;
//    cout<<'\n';
  }*/
} 
  
