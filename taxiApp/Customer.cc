#include <iostream>
#include <string>
#include "Customer.h"

int Customer::nextId = 1;
const char Customer:: type = 'C';

Customer:: Customer(const string& name, const int& rating, Location location): User(type,nextId,name,rating,location){
    // this ->nextId = nextId++;

}


Customer:: Customer(const string& name):User(type,nextId++,"Bob",5,Location(0,0)){

}


void Customer:: print()const{
  cout<<"Customer stats: \n";
  User::print();
  cout<<"\n";
}
