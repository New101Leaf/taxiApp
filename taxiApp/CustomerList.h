#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include <iostream>
#include <string>
#include "Customer.h"


class CustomerList{


    class Node{
      public:
        Customer* data;
        Node* next;
    };

  public:
    CustomerList();
    ~CustomerList();
    bool isEmpty()const;
    void add(Customer* cust);
    bool get(string name, Customer** cust)const;
    bool remove(const string& name, Customer** cust);
    void print()const;
    void clear();



  private:
    Node* head;








};

#endif
