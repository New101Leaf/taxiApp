
#include <iostream>
#include <string>

#include "User.h"


User::User(const char& type,int id, const string& name, const int& rating, Location location){
  this -> name = name;
  this -> rating = rating;
  this -> location = location;
  this -> id = type + to_string(id);


}


void User::setLocation(Location location){
      setLocation(location.getX(), location.getY());

}


void User:: setLocation(int x, int y){
  setLocation(x,y);
}


bool User:: lessThan(const User& user){
  return this -> name < user.getName();

}

void User:: print()const{
  cout<<"ID: " <<id << "\n";
  cout<<"Name: "<< name << "\n";
  cout<<"Rating: "<< rating<< "\n";
  cout<<"Location : ";
  location.print();
  cout<<"\n";




}
