typedef struct LinkedNode {
	double actualValue;
	LinkedNode *prev;
	LinkedNode *next;
	string *value;
	int digitCounts[10];
} LinkedNode;