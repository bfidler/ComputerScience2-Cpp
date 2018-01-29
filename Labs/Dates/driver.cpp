/*******************************
	Brayden Fidler
	bfidler
	Lab section 1
*******************************/
#include "Date.h"

int main(int argc, char* argv[]) {
	
	ifstream input;
	ofstream output;
	
	//opening files from command line
	input.open(argv[1]);
	output.open(argv[2]);

	//checking to make sure files opened correctly
	if(output.fail() || input.fail()) {

		cout << "Error opening files." << endl;
		exit(0);   
	}

	int numDates;
	int day, month, year;
	int i;

	//creates a Date vector with size based on number given
	input >> numDates;
	vector<Date> dates(numDates);

	for(i = 0; i < numDates; i++) {
		
		input >> month >> day >> year;
		dates.at(i).setMonth(month);
		dates.at(i).setDay(day);
		dates.at(i).setYear(year);
	}

	Date oldestDay = dates.at(0);

	//identifies oldest date
	for(i = 1; i < numDates; i++) {
		
		if(dates.at(i).getYear() < oldestDay.getYear()) {
			
			oldestDay = dates.at(i);
		}
		else if(dates.at(i).getYear() == oldestDay.getYear()) {

			if(dates.at(i).getMonth() < oldestDay.getMonth()) {

				oldestDay = dates.at(i);
			}
			else if(dates.at(i).getMonth() == oldestDay.getMonth()) {
				
				if(dates.at(i).getDay() < oldestDay.getDay()) {
					
					oldestDay = dates.at(i);
				}
			}
		}
	}
	
	//prints oldest date to output file
	output << oldestDay.getWordMonth() << " " << oldestDay.getDay() << ", "
		<< oldestDay.getYear();

	input.close();
	output.close();
	
	return 0;
}
