#ifndef LINKEDLIST_H__
#define LINKEDLIST_H__
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>



using namespace std;
//template<class Item>
//class LinkedList{
//public:
template<class Item>
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
template<class Item>
class LinkedList{
 public:
  Node<Item>* head;
  Node<Item>* tail;
  LinkedList();
  ~LinkedList();
  bool empty() const;
  LinkedList& operator=(const LinkedList &rhs);
  LinkedList(const LinkedList &s);
  void insert_front(Item i);
  void insert_back(Item i);
  void delete_front();
  void delete_back();
  void print();  
private:

};
#include "LinkedList.cc"

#endif
