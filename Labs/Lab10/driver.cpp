/***********************
	Brayden Fidler
	bfidler
	Lab 10
	Lab Section 1
	Nick Glyder
***********************/

/* Driver for lab  files */

#include "Package.h"
#include "ThreeDay.h"
#include "OvernightPackage.h"
#include "Person.h"
using namespace std;

#include <iostream>
#include <iomanip>

/*You will need to write the implementation for the following functions.  */

void getSenderInfo(Person &);
void getRecipientInfo(Person &);
void calculateAndPrint(Package &, ThreeDay&, OvernightPackage&);
void getPackageInfo(double&, double&, double&, double&, double&);


int main()
{
   double w, cost, fee1, fee2, flat;

   Person s;
   Person r;
   getSenderInfo(s);
   getRecipientInfo(r);
   getPackageInfo(w, cost, fee1, fee2, flat);

   //create the package objects
   Package p1(s, r, w, cost);
   ThreeDay p2(s, r, w, cost, fee1);
   OvernightPackage p3(s, r, w, cost, fee2, flat);

   calculateAndPrint(p1, p2, p3);

}

/*This function is used to request and receive information from the user
 *The information received from this function will be used to instantiate the
 *instances of Package, ThreeDay, and OvernightPackage in the main.  See
 *the sample output in the lab specification document for an example.*/

void getPackageInfo(double& w, double& cost, double& fee1, double& fee2,
                    double& flat)
{
  cout << "What is the weight of the package in ounces? ";
  cin >> w;
  cout << "What is the cost per ounce of the package? "; 
  cin >> cost;
  cout << "What is the additional fee per ounce for three day packages? ";
  cin >> fee1;
  cout << "What is the additional fee per ounce for overnight packages? ";
  cin >> fee2;
  cout << "What is the flat fee for overnight packages? ";
  cin >> flat;
  cout << endl;
}

/*This function is used to request and receive information from the user.
 *The information is used to set the values of a person that will be
 *passed to the instances of Package, ThreeDay, and OverrnightPackage.
 *It represents the "sender" of the Package class.*/

void getSenderInfo(Person& sender)
{
  string nm, ad, ct, st;
  int zip;
  
  cout << "What is the sender's name? ";
  getline(cin, nm);
  sender.setName(nm);
  
  cout << "What is the sender's address? ";
  getline(cin, ad);
  sender.setAddress(ad);

  cout << "In what city does the sender live? ";
  getline(cin, ct);
  sender.setCity(ct);
  
  cout << "In what state does the sender live? ";
  getline(cin, st);
  sender.setState(st);
  
  cout << "What is the zip code of the sender? ";
  cin >> zip;
  sender.setZip(zip);
  
  cout << endl;
}

/*Similar to the getSenderInfo function
 *This function is used to request and receive information from the user.
 *The information is used to set the values of a person that will be
 *passed to the instances of Package, ThreeDay, and OverrnightPackage.
 *It represents the "recipient" of the Package class.*/

void getRecipientInfo(Person& recipient)
{
  string nm, ad, ct, st;
  int zip;
  
  cout << "What is the recipient's name? ";
  cin.ignore();
  getline(cin, nm);
  recipient.setName(nm);
  
  cout << "What is the recipient's address? ";
  getline(cin, ad);
  recipient.setAddress(ad);

  cout << "In what city does the recipient live? ";
  getline(cin, ct);
  recipient.setCity(ct);
  
  cout << "In what state does the recipient live? ";
  getline(cin, st);
  recipient.setState(st);
  
  cout << "What is the zip code of the recipient? ";
  cin >> zip;
  recipient.setZip(zip);
  
  cout << endl;
}

/*The above functions set the information for the sender and recipient
 *and was passed to the constructors of p1, p2, and p3.  In this
 *function you will use the instance of Package to get the sender
 *and recipient information then call printSenderInfo and
 *printRecipientInfo. */

void calculateAndPrint(Package& p1, ThreeDay& p2, OvernightPackage& p3)
{

  /*create an instance of Person and make it equal to the P1's sender
   *information.  Do the same with P1's recipient.  */

  Person sender = p1.getSender();
  Person recipient = p1.getRecipient();

  /*print the sender information*/
  
  cout << "SENDER ADDRESS:" << endl;
  sender.printInfo();
  cout << endl;

  /*print the recipient information*/

  cout << "RECIPIENT ADDRESS:" << endl;
  recipient.printInfo();
  cout << endl;

  /*Since we are dealing with money make sure you set the precision to 2
   *and make sure sure trailing zeros are printed.*/

  cout << setprecision(2) << fixed;



  /*Now you are to calculate and print the cost of the Package, ThreeDay,
   *and OvernightPackage  See the sample output.  */

  cout << "Cost calculation for Package: " << p1.calculateCost() << endl;
  cout << "Cost calculation for Three Day: " << p2.calculateCost() << endl;
  cout << "Cost calculation for Overnight: " << p3.calculateCost() << endl;




}
