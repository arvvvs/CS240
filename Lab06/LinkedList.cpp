#include <iostream> 
#include <cctype>
#include "LinkedList.h"
#include <algorithm>
#include <stdexcept>


using namespace std;
typedef Random Item;
LinkedList::LinkedList(){
  head=NULL;
  tail=NULL;
}
Node::Node(){
   next=NULL;
  
  previous=NULL;
}
void Node::setData(Item aData){
  data=aData;
}

void Node::setNext(Node* aNext){
  next=aNext;
}

//void Node::setPrevious(Node* aPrevious){
  //aPrevious=previous;
//}


Item Node::Data(){
  return data;
}

bool LinkedList::empty() const{
  if(head==0){
    return true;}
  else{
    return false;
  }}

void LinkedList::insert_front(Item i){
  Node* newNode= new Node();
  if(LinkedList::empty()==true){
    newNode->data=i;
    newNode->next=NULL;
    newNode->previous=NULL;
    head=newNode; 
    tail=newNode;
  }
  else{
    Node* temp;
    temp=head;
    Node* newNode=new Node();
    newNode -> data=i;
    newNode -> next=temp;
    temp -> previous=newNode;
    head=newNode;
  }
}


void LinkedList::insert_back(Item i){
  if(LinkedList::empty()==true){
    Node* newNode=new Node();
    newNode->data=i;
    newNode->next=NULL;
    newNode->previous=NULL;
    head=newNode;
    tail=newNode;
  }
  else{
    Node* newNode=new Node();
    newNode->data=i;
    newNode->next=NULL;
    newNode->previous=tail;
    tail->next=newNode;
    tail=newNode;
  }


}
void LinkedList::delete_front(){
   if(LinkedList::empty()==true){
      cout<<"Linked List is empty"<<endl;
   }
   else{
    Node* newNode;
    newNode=head;
    if(newNode->next!=NULL)
    {newNode=newNode->next;
    newNode->previous=NULL;
    head=NULL;
    head=newNode;}
    else{
      head=NULL;
    } 
  }

}
void LinkedList::delete_back(){
  if(LinkedList::empty()==true){
    cout<<"Linked LIst is empty"<<endl;
  }
  else{
    Node* newNode=new Node();
    newNode=tail;
    if(newNode->previous!=NULL){
      newNode=newNode->previous;
      delete tail;
      tail=newNode;
    }
    else{
    delete tail;
  }
}}


Node* Node::Next(){
  return next;
}

Node* Node::Previous(){
  return previous;
}

void LinkedList::print(){
 Node* currentPtr=head;
  if(LinkedList::empty()==true){
    cout<<"List is empty"<<endl;
  }
  else{
  while(currentPtr!=NULL){
  cout<<currentPtr->data<<endl;
  currentPtr=currentPtr->next;
  }}
}

