#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "defs.h"
#include "User.h"

using namespace std;


class Driver: public User{
  public:
    Driver(const string& name);
    Driver(const string& name, const int& rating, Size size, Location loca);
    bool match(const int& rating, Size size);
    int getDistance(Location& location);
    void print()const;


  private:
    Size size;
    static const char type;
    static int nextId;


};

#endif
