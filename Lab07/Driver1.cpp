#include "LinkedList.h"

using namespace std;

int main(){
	//Initialize the pseudo-random number generator with a see of the time
	srand(time(NULL));
	
	//Initialize the first linked list
	LinkedList<Random> l1;

	//Verify it was initialized empty
	if(!l1.empty()){
		cout << "Empty list is not empty." << endl; 
	} else {
		cout << "Passed the empty list as default constructor test." << endl;
	}
	cout << "----------------------------------" << endl;

	//Call the copy constructor on the empty list to create a second empty list
	LinkedList<Random> l2 = l1;

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
	l1.insert_front(Random());

	cout << "The following is the first list:" << endl;
	l1.print();

	cout << "The following is the second list:" << endl;
	l2.print();

	cout << "----------------------------------" << endl;


	//Add something to the back of list 1
	cout << "Adding something to the back  of the first list" << endl;
	cout << "..." << endl;
	l1.insert_back(Random());

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
	l2.insert_back(Random());

	cout << "The second list (1):" << endl;
	l2.print();

	cout << "Adding something to the back of the second list" << endl;
	cout << "..." << endl;	
	l2.insert_back(Random());

	cout << "The second list (2):" << endl;
	l2.print();

	cout << "Adding something to the front of the second list" << endl;
	cout << "..." << endl;
	l2.insert_front(Random());

	cout << "The second list (3):" << endl;
	l2.print();

	cout << "----------------------------------" << endl;

	cout << "----------------------------------" << endl;
	
	cout << "----------------------------------" << endl;

	cout << "Commencing stress test:" << endl;

	LinkedList<Random> l3;

	int insertions=0, deletions=0, frontops=0, backops=0;

	int numops = rand()%1000000;


	int val;

	clock_t finish, start = clock();

	while( numops > (insertions + deletions)){
		val = rand();

		if(val%4==0){
			l3.insert_front(Random());	
			insertions++;
			frontops++;
		} else if (val%4 == 1){
			l3.insert_back(Random());
			insertions++;
			backops++;
		} else if (val%4 == 2){
			l3.delete_front();
			deletions++;
			frontops++;
		} else {
			l3.delete_back();
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
