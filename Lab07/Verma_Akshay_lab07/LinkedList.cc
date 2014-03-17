#include <iostream> 
#include <cctype>
#include "LinkedList.h"
#include <algorithm>
#include <stdexcept>


using namespace std;
LinkedList<Item>::LinkedList(){
  head=NULL;
  tail=NULL;
}
Node<Item>::Node(){
   next=0;
  data=0;
  previous=0;
}
void Node<Item>::setData(Item aData){
  data=aData;
}
void Node<Item>::setNext(Node* aNext){
  next=aNext;
}
void Node<Item>::setPrevious(Node* aPrevious){
  aPrevious=previous;
}
LinkedList<Item>::LinkedList(const LinkedList &s){
  Node<Item>* tmp=new Node<Item>();
  head=tmp;
  if(!s.empty()){
  
  Node<Item>* setTail;
  
    
  Node<Item>* newNode=s.head;
  while(tmp!=NULL){
     // tmp.setData(s.Data());
      tmp->data=newNode->data;
     // tmp.setNext(s.Next());
     tmp->next=newNode->next;
     // tmp.setPrevious(s.Previous());
     tmp->previous=newNode->previous; 
      if(tmp->Next()==NULL){
        setTail=tmp;
      }
      tmp=tmp->next;
    
    } 
  tail=setTail;
   
  }
  else{
    head=NULL;
    tail=NULL;
    }

}
Item Node<Item>::Data(){
  return data;
}
bool LinkedList<Item>::empty() const{
  if(head==0){
    return true;}
  else{
    return false;
  }}
void LinkedList<Item>::insert_front(Item i){
  Node<Item>* newNode= new Node<Item>();
  if(LinkedList::empty()==true){
   // Node<Item>* newNode;
    newNode->data=i;
    newNode->next=NULL;
    newNode->previous=NULL;
    head=newNode; 
    tail=newNode;
  }
  else{
    Node<Item>* temp;
    temp=head;
    Node<Item>* newNode=new Node<Item>();
    newNode -> data=i;
    newNode -> next=temp;
    temp -> previous=newNode;
    head=newNode;
  }
}
LinkedList<Item>::~LinkedList(){
 /* Node<Item>* newNode;
  newNode=head;
  newNode=newNode->next;
  while(newNode!=NULL){
    delete head;
    head=newNode;
    newNode=newNode->next;
  }*/
  if(head==NULL){
    delete head;
  }
  else{
    while(head!=NULL){
      delete_front();
    }
  }
}
LinkedList<Item>& LinkedList<Item>::operator=(const LinkedList<Item> &rhs){
    if(this != &rhs){
      ~this;
      Node<Item>* newNode;
      Node<Item>* temp;
      if(rhs.empty()==false){
        head=NULL;
      }
      else{  
      head=newNode;
      while(newNode->Next()!=NULL){
        newNode.setData(rhs.Data());
        temp=rhs.Next();
        newNode.setNext(temp);  
        Node<Item>* newNode2;
        newNode2=newNode;
        newNode=newNode->next;
        newNode.setPrevious(newNode2);
       }}
    }
    return *this;
}
void LinkedList<Item>::insert_back(Item i){
  if(LinkedList::empty()==true){
    Node<Item>* newNode=new Node<Item>();
    newNode->data=i;
    newNode->next=NULL;
    newNode->previous=NULL;
    head=newNode;
    tail=newNode;
  }
  else{
    Node<Item>* newNode=new Node<Item>();
    newNode->data=i;
    newNode->next=NULL;
    newNode->previous=tail;
    tail->next=newNode;
    tail=newNode;
  }


}
void LinkedList<Item>::delete_front(){
   if(LinkedList::empty()==true){
      cout<<"Linked List is empty"<<endl;
   }
   else{
    Node<Item>* newNode;
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
void LinkedList<Item>::delete_back(){
  if(LinkedList::empty()==true){
    cout<<"Linked LIst is empty"<<endl;
  }
  else{
    Node<Item>* newNode=new Node<Item>();
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

Node<Item>* Node<Item>::Next(){
  return next;
}

Node<Item>* Node<Item>::Previous(){
  return previous;
}

void LinkedList<Item>::print(){
 Node<Item>* currentPtr=head;
  if(LinkedList::empty()==true){
    cout<<"List is empty"<<endl;
  }
  else{
  while(currentPtr!=NULL){
  cout<<currentPtr->data<<endl;
  currentPtr=currentPtr->next;
  }}
}

