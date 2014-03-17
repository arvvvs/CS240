#ifndef LIST
#define LIST
typedef int Item
class LinkedList{
private:
class node{
public:
Item data;
int *next;
private:
}
int count;

public:
LinkedList();
empty();
insert_front(Item i);
insert_back(Item i);
delete_front();
delete_back();
print();
}

#endif
