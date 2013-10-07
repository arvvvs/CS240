#include <fstream>
#include <iostream>
#include "makeInteresting.h"
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
//  cout<<argc<<endl;
/*  if(argc!=3){
    cout<<"really"<<"\n";
    


  }
  else{*/
    string iFile;
    string oFile;
    iFile= argv[1];
    oFile= argv[2];
    makeInteresting mI(iFile, oFile);
    mI.run();
    


 // }
}







