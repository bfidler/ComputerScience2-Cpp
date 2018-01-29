/***********************
	Brayden Fidler
	bfidler
	Lab Section 1
***********************/

#include "Date.h"

Date::Date() {
	month = 0;
	day = 0;
	year = 0;
}

Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

void Date::setMonth(int m) {
	month = m;
}

void Date::setDay(int d) {
	day = d;
}

void Date::setYear(int y) {
	year = y;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

int Date::getYear() {
	return year;
}

string Date::getWordMonth() {
	string theMonth;

	switch(month) {
		case 1:	theMonth = "January";
					break;
		case 2:	theMonth = "February";
					break;
		case 3:	theMonth = "March";
					break;
		case 4:	theMonth = "April";
					break;
		case 5:	theMonth = "May";
					break;
		case 6:	theMonth = "June";
					break;
		case 7:	theMonth = "July";
					break;
		case 8:	theMonth = "August";
					break;
		case 9:	theMonth = "September";
					break;
		case 10:	theMonth = "October";
					break;
		case 11:	theMonth = "November";
					break;
		case 12:	theMonth = "December";
					break;
		default: theMonth = "";
	}

	return theMonth;
}
