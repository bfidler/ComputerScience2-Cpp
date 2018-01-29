/***********************
	Brayden Fidler
	bfidler
	Lab 10
	Lab Section 1
	Nick Glyder
***********************/

/* Class definitions for package */

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include "Person.h"
using namespace std;

class Package
{
  public:
	  Package(Person, Person, double, double);
	  double calculateCost();
    Person& getSender();
    Person& getRecipient();

  protected:
	  Person sender;
	  Person recipient;
	  double weight;
	  double cost;
};
#endif
