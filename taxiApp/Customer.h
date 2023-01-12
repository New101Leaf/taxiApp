#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "User.h"


class Customer: public User{

  public:
    Customer(const string& name, const int& rating, Location location);
    Customer(const string& name);
    void print()const;

  private:
    static const char type;
    static int nextId;


};




#endif
