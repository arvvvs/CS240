#include <fstream>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void){
ifstream iFile;
ofstream oFile;
string mystr;
iFile.open("needleTest.txt");
oFile.open("needleResults.txt");
//getline(iFile, mystr);
/*for(;;){
  getline(iFile, mystr);
  if(iFile.eof()){

  break;
  }*/
//getline(iFile, mystr);
//  getline(iFile,mystr);
  
/*while(getline(iFile, mystr)){
 cout<<mystr<<'\n';
 if(iFile.eof()){
  break;
  }
  else{
*/
cout<<mystr<<'\n';
string str1="lets test this testBi. Needle test Testing needle needleHaystack.";
string str2="test";
string str3=" test ";
string str4=" needle ";
int found=0;
int lineNumber=0;
while(getline(iFile, mystr)){
  lineNumber++;
  
  cout<<mystr<<endl; 
  
}
cout<<lineNumber<<'\n';
cout<<mystr<<endl;
//cout<<str1<<'\n';
/*while(getline(iFile, mystr)){
  cout<<"in while loop"<<'\n';
 //if(iFile.eof()){
 // break;
 // }
  found=mystr.find(str3);
  if(found!=-1){
  mystr.replace(found, str2.length(), str4)<<"\n";
  cout<<"1found "<<str2<<" at "<<found<<"\n";
  found++;
  cout<<"found "<<str2<<" at "<<found<<"\n";
  }
}*/
//while(found!=std::string::npos);}

//cout<<str1<<'\n';
oFile<<mystr<<'\n';
for(;;){
  getline(iFile, mystr);
  if(iFile.eof()){
    break;
  }
  oFile<<mystr<<endl;
}
iFile.close();
oFile.close();
}
