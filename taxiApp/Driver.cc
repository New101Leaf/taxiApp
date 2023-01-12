#include <iostream>
#include <string>
#include "Driver.h"


int Driver:: nextId = 1;
const char Driver:: type = 'D';


Driver::Driver(const string& name, const int& rating, Size size, Location loca): User(type,nextId++,name,rating,loca){
     this -> size = size;

}



Driver:: Driver(const string& name):User(type,nextId++,"Bob",5,Location(0,0)){
  this -> size = medium;


}


int Driver::getDistance(Location& loca){

  return User::location.getDistance(loca);

}



bool Driver:: match(const int& rating, Size s){
  if((this -> rating - rating <=2) && (rating - this -> rating <= 2) && this -> size >= s){
      return true;
  }
  return false;

}

void Driver::print()const{
  cout<<"\nDriver stats:\n";
  User::print();
  cout<<"\n";
}
