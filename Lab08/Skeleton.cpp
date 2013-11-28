#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

  
	//declare a few time points
  
	chrono::monotonic_clock::time_point start, finish;

	chrono::monotonic_clock::time_point middle4, middle5, middle6;
	chrono::monotonic_clock::time_point middle4, middle5, middle6;
  //declare a holder for nanoseconds
  chrono::nanoseconds elapsed;
	//seed the random number generator
  srand(time(NULL));
	//For the different sizes
  for(int i=0; i<6; i++)
  {
		//declare and initialize long variables to store the
		//accumulated time needed for each algorithm
    long time1=0;
    long timeSort=0;
    long time2=0;
    long timeBinary=0;
    long timeReverse=0;
    long timeStable=0;
    long time3=0;
    long time4=0;
    long time5=0;
    long time6=0;
		//printout to help decode output
    cout<<i<<endl;
		//For the iterations
    for(int j=0; j<101; j++)
		  {

			//Create a vector full of random data up to size
      vector<double> x(10^i,rand());
      start= chrono::monotonic_clock::now(); 
			//start a timer
				//call sort
        sort(x.begin(), x.end());
			//stop the timer		
      finish = chrono::monotonic_clock::now();
			//compute elapsed time
      time1=finish-start;
			//accumulate the elapsed time into sort's time accumulator
      timeSort+=time1;

			//start a timer
      middle= chrono::monotonic_clock::now()
        binary_search(x.begin(), x.end(), rand());
				//call binary_search on a random data element
			//stop the timer
			middle2= chrono::monotonic_clock::now();

      //compute elapsed time
      time2=middle2-middle;
			//accumulate the elapsed time into search's time accumlator
      timeBinary+=time2;
			//empty out and re-fill the vector
      x.clear();
      x(10^i, rand());
			//start a timer
      middle3=chrono::monotonic_clock::now();
				//call reverse
        reverse(x.begin(), x.end());
			//stop the timer
      middle4=chrono::monotonic_clock::now();
			//compute elapsed time
      time3=middle4-middle3;
			//accumulate the elapsed time into reverse's time accumulator
      timeReverse+=time3;
			//start a timer
      middle5=chrono::monotonic_clock::now();
				//call stable_sort
        stable_sort(x.begin(), x.end());
			//stop the timer
      middle6=chrono::monotonic_clock::now();
			//compute elapsed time
      time4=middle6-middle5;
			//accumulate the elapsed time into stable_sort's time accumulator
      timeStable+=time4;

		}

		//print out the average time (accumulator divided by number of trials)
		//for each of the operations (remember not to use integer division)
  cout<<"Sorting took: "<<(timeSort/(long)100)<<endl;
  cout<<"binary search took:"<<(timeBinary/(long)100)<<endl;
  cout<<"Reverse took"<<(timeReverse/(long)100)<<endl;
  cout<<"stable sort took"<<(timeStable/(long)100)<<endl;
	}
	return 0;
}
