#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;
class makeInteresting{
private:
ifstream iFile;
ofstream oFile;
std::string myLine;
std::string eLine;
int lineCount;
string original[12]={"people ", "wounded ", "died ", "die ", "bullets ", "cannon ball ", "cannon ", "bayonet ", "Prince ", "gloom", "happy", "vanish"};
string replacement[12]={"zombie ", "bitten ", "turned ", "turn ", "teeth marks ", "plague bomb  ", "infected ", "pitchfork ", "Leiche ","GLOOM","HAPPY","vAnIsH"};
ifstream wFile;
float totalFound;

public:
  makeInteresting(string ifile_name, string ofile_name); 
//  void loadData();
  ~makeInteresting();
  string loadLines();
  void replace();   
  void run();
  void saveFile();
  int countWords();
};
