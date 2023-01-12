#ifndef DRIVERLIST_H
#define DRIVERLIST_H

#include <iostream>
#include <string>
#include "Driver.h"



class DriverList{
    class Node{
      public:
        Driver* data;
        Node* next;
    };

  public:
    DriverList();
    ~DriverList();
    bool isEmpty()const;
    void add(Driver* driver);
    bool get(const string& name, Driver** driver)const;
    bool remove(const string& name, Driver** driver);
    void print()const;
    void clear();
    bool findRide(const int& rating, Size size,Location locate, Driver** driv);



  private:
    Node* head;




};

#endif
