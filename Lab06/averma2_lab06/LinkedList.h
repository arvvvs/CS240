#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "Random.h"


using namespace std;
typedef Random Item;
class Node{
public:
  Item data;
  Node* next;
  Node* previous;
  Node();
  void setData(Item aData);
  void setNext(Node* aNext);
  void setPrevious(Node* aPrevious);
  Item Data();
  Node* Next();
  Node* Previous(); 
};

class LinkedList{
 public:
  LinkedList();
  Node* head;
  Node* tail;  
  bool empty() const;
  void insert_front(Item i);
  void insert_back(Item i);
  void delete_front();
  void delete_back();
  void print();  
private:

};


#endif
