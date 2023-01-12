#ifndef CoVoiture_H
#define CoVoiture_H

#include <iostream>
#include <string>
#include "DriverList.h"
#include "CustomerList.h"


class CoVoiture{

  public:
    CoVoiture();
    ~CoVoiture();
    void addDriver(const string& name, const int& rating, Size size, Location locate);
    bool getDriver(const string& name, Driver** driver)const;
    bool removeDriver(const string& name);
    void addCustomer(const string& name, const int& rating, Location locate);
    bool getCustomer(const string& name,Customer** customer);
    bool removeCustomer(const string& name);
    bool findRide(const string& name, Size size, Driver** driver);
    void printCustomers()const;
    void printDrivers()const;



  private:
    DriverList drivers;
    CustomerList customers;



};

#endif
