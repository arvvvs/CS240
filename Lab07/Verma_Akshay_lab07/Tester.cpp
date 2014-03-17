#include "LinkedList.h"
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
//Using tester provided to us for previous lab as it performs a lot of tests and
//is very through in it's testing

int main(){

	//Initialize the pseudo-random number generator with a see of the time
	//Initialize the first linked list
	LinkedList<int> l1;
  LinkedList<string> l4;
  
//  l4.insert_front("Hello My dear");
//	l4.insert_front("String linked list");
//  l4.print();
  //Verify it was initialized empty
	if(!l1.empty()){
		cout << "Empty list is not empty." << endl; 
	} else {
		cout << "Passed the empty list as default constructor test." << endl;
	}
	cout << "----------------------------------" << endl;

	//Call the copy constructor on the empty list to create a second empty list
	LinkedList<int> l2 = l1;

	//Verify the copied list is empty
	if(!l2.empty()){
		cout << "Empty list is not empty when using copy constructor." << endl;
	} else {
		cout << "Passed the empty list as a copy constructor test." << endl;
	}

	cout << "----------------------------------" << endl;

	//Add something to list 1
	cout << "Adding something to the front of the first list" << endl;
	cout << "..." << endl;
	l1.insert_front(10000);

	cout << "The following is the first list:" << endl;
	l1.print();

	cout << "The following is the second list:" << endl;
	l2.print();

	cout << "----------------------------------" << endl;


	//Add something to the back of list 1
	cout << "Adding something to the back  of the first list" << endl;
	cout << "..." << endl;
	l1.insert_back(2342202);

	cout << "The following is the first list now:" << endl;
	l1.print();

	cout << "The following is the second list now:" << endl;
	l2.print();

	cout << "----------------------------------" << endl;

	cout << "----------------------------------" << endl;

	//Add something to the front of list 2
	cout << "The second list (0):" << endl;
	l2.print();

	cout << "Adding something to the back of the second list" << endl;
	cout << "..." << endl;
	l2.insert_back(394832009);

	cout << "The second list (1):" << endl;
	l2.print();

	cout << "Adding something to the back of the second list" << endl;
	cout << "..." << endl;	
	l2.insert_back(892348742);

	cout << "The second list (2):" << endl;
	l2.print();

	cout << "Adding something to the front of the second list" << endl;
	cout << "..." << endl;
	l2.insert_front(2094423);

	cout << "The second list (3):" << endl;
	l2.print();

	cout << "----------------------------------" << endl;

	cout << "----------------------------------" << endl;
	
	cout << "----------------------------------" << endl;

	cout << "Commencing stress test:" << endl;

	LinkedList<int> l3;

	int insertions=0, deletions=0, frontops=0, backops=0;

	int numops = rand()%1000000;


	int val;

	clock_t finish, start = clock();

	while( numops > (insertions + deletions)){
		val = rand();
   // int insertFront= 0;
    //int insertBack= 0;
   // int deleteFront= 0;
   // int deleteBack= 0;
    //int total= (insertFront+insertBack-deleteFront-deleteBack);
	//	cout<<total<<"\n";
    if(val%4==0){
	//		cout<<"insert front1"<<"\n";
     // insertFront++;
      l3.insert_front(rand()%200);	
			insertions++;
			frontops++;
	
  } else if (val%4 == 1){
//			cout<<"insert back 2"<<"\n";
    //  insertBack++;
    //  cout<<total<<"\n";
      l3.insert_back(rand()%100+1);
			insertions++;
			backops++;
		} else if (val%4 == 2){
		//	cout<<"delte front 3"<<"\n";
  //    deleteFront++;
      l3.delete_front();
			deletions++;
			frontops++;
		} else {
  //    cout<<"delete back 4"<<"\n";
      l3.delete_back();
		//	deleteBack++;
      deletions++;
			backops++;
		}
	}

	finish = clock();

	cout << "Performed " << insertions << " insertions and " << deletions << " deletions" << endl;
	cout << "\t " << 100.0f*((float)frontops/(float)numops) << "\% at the front " << endl;
	cout << "\t " << 100.0f*((float)backops/(float)numops) << "\% at the back" << endl;

	cout << endl << "This took " << ((float)finish - (float)start) / (float)CLOCKS_PER_SEC;
	cout << " seconds" << endl;



	return 0;
}
