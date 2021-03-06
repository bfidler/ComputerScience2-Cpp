/***********************
	Brayden Fidler
	bfidler
	Lab 10
	Lab Section 1
	Nick Glyder
***********************/

/* Class definitions for overnight package */

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"
#include <string>
using namespace std;

class OvernightPackage:public Package
{
    public:
        OvernightPackage(Person, Person, double, double, double, double);
        double calculateCost();

    private:
        double additionalFee;
        double flatFee;
};
#endif
