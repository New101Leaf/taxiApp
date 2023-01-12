#include <iostream>
#include <string>

#include "CustomerList.h"

CustomerList:: CustomerList():head(NULL){}

CustomerList::~CustomerList(){
  Node* currNode = head;
  Node* nextNode = NULL;

  while (currNode != NULL){
    nextNode = currNode -> next;
    delete currNode;
    currNode = nextNode;
  }



}


bool CustomerList::isEmpty()const{
  if(head -> next == NULL){
    return true;
  }
  return false;
}


void CustomerList::add(Customer* cust){
  Node *newNode = new Node();
  newNode -> data = cust;
  newNode -> next = NULL;

  Node* currNode = head;
  Node* prevNode = NULL;

  while(currNode != NULL){
    if(newNode -> data -> lessThan(*currNode -> data)){
      break;
    }
    prevNode = currNode;
    currNode = currNode -> next;
  }

  if(prevNode == NULL){
    head = newNode;
  }else{
    prevNode -> next = newNode;
  }
  newNode -> next = currNode;


}




bool CustomerList::get(string name, Customer** cust)const{
  Node* currNode;


  currNode = head;
 //cout<<"IN HERE";
  while(currNode != NULL){

    if(currNode -> data -> getName() == name){
      break;
    }
    currNode = currNode -> next;
  }

  if(currNode == NULL){
    *cust = NULL;
    return false;
  }
  *cust = currNode -> data;
  return true;

}



bool CustomerList::remove(const string& name, Customer** cust){
  Node* currNode;
  Node* prevNode;
  currNode = head;
  prevNode = NULL;

  while (currNode != NULL){
    if(currNode -> data -> getName() == name){
      break;
    }
    prevNode = currNode;
    currNode = currNode -> next;
  }

  if(currNode == NULL){
    *cust = NULL;
    return false;
  }

  if(prevNode == NULL){
    head = currNode -> next;
  }else{
    prevNode -> next = currNode -> next;
  }
  *cust = currNode -> data;
  delete currNode;
  return true;

}


void CustomerList::print()const{
  Node* currNode = head;
  cout<<"Printing Customer list"<< endl;

  if(currNode == NULL){
    cout<<"Customer List is empty"<< endl;
  }
  while(currNode != NULL){
    currNode -> data -> print();
    currNode = currNode -> next;
  }
}

//Deleting node and the data
void CustomerList::clear(){
  Node* currNode = head;
  Node* nextNode = NULL;

  while (currNode != NULL){
    nextNode = currNode -> next;
    delete currNode -> data;
    delete currNode;
    currNode = nextNode;
  }
  head = currNode;


}
