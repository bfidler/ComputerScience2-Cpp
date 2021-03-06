/***********************
	Brayden Fidler
	bfidler
	Lab 10
	Lab Section 1
	Nick Glyder
***********************/

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
  private:
    string name;
    string address;
    string city;
    string state;
    int zip;

  public:
    Person(string, string, string, string, int);
    Person();
    void setName(string);
    void setAddress(string);
    void setState(string);
    void setCity(string);
    void setZip(int);

    void printInfo();
    

};

#endif
