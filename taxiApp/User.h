#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

#include "Location.h"

using namespace std;


class User{
  public:

    User(const char& type,int id,const string& name, const int& rating, Location location);
    void setLocation(Location location);
    void setLocation(int x, int y);
    void print()const;
    bool lessThan(const User& name);
    string getName()const{return name;}
    string getId()const{return id;};
    int getRating()const{return rating;}
    Location getLocation()const{return location;}


  protected:
    string id;
    string name;
    int rating;
    Location location;



};

#endif
