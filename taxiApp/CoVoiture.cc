#include <iostream>
#include <string>

#include "CoVoiture.h"

CoVoiture::CoVoiture(){



}

CoVoiture::~CoVoiture(){
  drivers.clear();
  customers.clear();



}

void CoVoiture::addDriver(const string& name, const int& rating, Size size, Location locate){
    //Create a new driver
    Driver* driv = new Driver(name,rating,size,locate);
    drivers.add(driv);

}

bool CoVoiture::getDriver(const string& name,Driver** driver)const{
     if(drivers.get(name,driver)){
        return true;
     }
     cout<<"ERROR: FAILED TO GET DRIVER \n";
     return false;
}

bool CoVoiture::removeDriver(const string& name){

     Driver* driv;
      if(drivers.remove(name,&driv)){
          cout<<"Driver "<< name << " has been removed\n";
           delete driv;
           return true;
      }
      cout<<"ERROR: FAILED TO REMOVE DRIVER \n";
     delete driv;
    return false;
}

void CoVoiture:: addCustomer(const string& name,const int& rating,Location locate){
    Customer* cust = new Customer(name,rating,locate);
    customers.add(cust);
}

bool CoVoiture::getCustomer(const string& name,Customer** cust){
    if(customers.get(name,cust)){
        return true;
    }
    cout<<"ERROR: FAILED TO GET CUSTOMER \n";
     return false;

}

bool CoVoiture::removeCustomer(const string& name){
    Customer* cust;
    if(customers.remove(name,&cust)){
        cout<<"Customer "<< name << " has been removed\n";
        delete cust;
        return true;
    }
    cout<<"ERROR: FAILED TO REMOVE CUSTOMER \n";
    delete cust;
    return false;

}



bool CoVoiture:: findRide(const string& name, Size size, Driver** driver){
    Customer* cust;
    //Find mathcing customer then find the ride for them
    if(customers.get(name,&cust)){
        if(drivers.findRide(cust->getRating(),size,cust->getLocation(),driver)){
          return true;
        }
    }

    cout<<"ERROR: FAILED TO FIND RIDE \n";
    return false;

}

void CoVoiture:: printCustomers()const{
    customers.print();
}

void CoVoiture:: printDrivers()const{
    drivers.print();
}
