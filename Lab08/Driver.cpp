#include <fstream>
#include <iostream>
#include "lab08.h"
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
  string iFile;
  string oFile;
  iFile=argv[1];
  lab08 l8(iFile);
  l8.run();
}
