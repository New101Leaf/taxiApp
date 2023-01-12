#include <iostream>
#include <string>

#include "DriverList.h"

DriverList:: DriverList():head(NULL){}

DriverList::~DriverList(){
  Node* currNode = head;
  Node* nextNode = NULL;

  while (currNode != NULL){
    nextNode = currNode -> next;
    delete currNode;
    currNode = nextNode;
  }



}


bool DriverList::isEmpty()const{
  if(head -> next == NULL){
    return true;
  }
  return false;
}


void DriverList::add(Driver* driver){

  Node *newNode = new Node();
  newNode -> data = driver;
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

bool DriverList::get(const string& name, Driver** driver)const{
  Node* currNode;



  currNode = head;

  while(currNode != NULL){
    if(currNode -> data -> getName() == name){
      break;
    }
    currNode = currNode -> next;
  }

  if(currNode == NULL){
    *driver = NULL;
    return false;
  }
  *driver = currNode -> data;
  return true;

}


bool DriverList::remove(const string& name, Driver** driver){

  Node* currNode;
  Node* prevNode;
  currNode = head;
  prevNode = NULL;

  while (currNode != NULL){
    if(currNode -> data ->User::getName() == name){

      break;
    }
    prevNode = currNode;
    currNode = currNode -> next;

  }

  if(currNode == NULL){
    *driver = NULL;
    return false;
  }

  if(prevNode == NULL){
    head = currNode -> next;
  }else{
    prevNode -> next = currNode -> next;
  }
  *driver = currNode -> data;
  delete currNode;
  return true;

}


bool DriverList::findRide(const int& rating, Size size, Location locate, Driver** driv){

    Node* currNode;
    Node* low = NULL;
    currNode = head;


  

   if(currNode != NULL){
     low = currNode;
   }else{
     *driv = NULL;
     return false;
   }


    while(currNode != NULL){

            if((low -> data -> getLocation().getDistance(locate)) > (currNode -> data -> getLocation().getDistance(locate))){
              if(currNode -> data -> match(rating,size)){
                low = currNode;

            }
          }

      currNode = currNode -> next;
    }


     if(low -> data -> match(rating,size)){
       *driv = low -> data;
       return true;
     }

  *driv = NULL;
   return false;



}


void DriverList::print()const{
  Node* currNode = head;
  cout<<"Printing Driver list"<< endl;

  if(currNode == NULL){
    cout<<"Driver List is empty"<< endl;
  }
  while(currNode != NULL){
    currNode -> data -> print();
    currNode = currNode -> next;
  }
}


void DriverList::clear(){
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
