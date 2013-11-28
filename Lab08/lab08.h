#include<iostream>
#include<string>
#include <cctype>
#include <fstream>
#include <list>
using namespace std;

class lab08{
  private:
  ifstream iFile;
  int lineCount;
  public:
  lab08(string ifile_name);
  void run();
  string removePunctuation(const string&);
//  string makeLower(const string&);
  std::list<char> normalList;
  std::list<char> reverseList;
  bool  isAlphaNumeric(const string&);
  void makeList(const string&);
  string makeLower(const string&);
};
