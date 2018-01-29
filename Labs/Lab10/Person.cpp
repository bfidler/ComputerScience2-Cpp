/***********************
	Brayden Fidler
	bfidler
	Lab 10
	Lab Section 1
	Nick Glyder
***********************/

#include "Person.h"
#include <iostream>
using namespace std;

/*Use initialization list to initialize the two following constructors */

Person::Person(string name, string address, string city, string state, int zip)
{
	this->name = name;
	this->address = address;
	this->city = city;
	this->state = state;
	this->zip = zip;
}
Person::Person()
{
	name = "";
	address = "";
	city = "";
	state = "";
	zip = 0;
}

/*Setters*/
void Person::setName(string name)
{
    this->name = name;
}
void Person::setAddress(string address)
{
    this->address = address;
}
void Person::setState(string state)
{
    this->state = state;
}
void Person::setCity(string city)
{
    this->city = city;
}
void Person::setZip(int zip)
{
    this->zip = zip;
}


/*The next two functions are used to print the Sender and Recipient's
 *mailing information*/

void Person::printInfo()
{
	cout << name << endl << address << endl << city << ", " << state;
	cout << " " <<zip << endl; 
}




