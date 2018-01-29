/***********************
	Brayden Fidler
	bfidler
	Lab Section 1
***********************/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Date
{
	private:
		int month;
		int day;
		int year;

	public:
		/*Default constructors*/
		Date();

		/*Overloaded constructor*/
		Date(int, int, int);

		/*Setters*/
		void setMonth(int);
		void setDay(int);
		void setYear(int);

		/*Getters*/
		int getMonth();
		int getDay();
		int getYear(); 
    string getWordMonth();
    
};
