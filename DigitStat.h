typedef struct LinkedNode {
	double actualValue;
	LinkedNode *prev;
	LinkedNode *next;
	std::string *value;
	int digitCounts[10];
} LinkedNode;
