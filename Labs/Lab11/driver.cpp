/***********************
	Brayden Fidler
	bfidler
	Lab 11
	Lab Section 1
	Nick Glyder
***********************/

#include <fstream>
#include <cstdlib>
#include "functions.h"

int main( int argc, char* argv[] )
{
    // Using the command line arguments check for a valid input file
    // If there is not one, give the user a message and exit the program
	ifstream input(argv[1]);

	if(argc != 2)
  	{
    	cout << "USAGE ERROR:  ./executable outPutFileName";
    	exit(EXIT_FAILURE);
  	}
  	if(input.fail())
 	{
    	cout << argv[1] << " did not open successfully\n";
  	}
	

    // Read the other items from the file and store them
	vector<int> numbers;	
	
	while(input.good())
	{
		int newInt;
		input >> newInt;
		numbers.push_back(newInt);
	}
		

    // Close the file you are reading
    // Then print the array
    input.close();
	  print_array(numbers, numbers.size());

    // Using selection sort, sort the array
    // Then print the array
    selection_sort(numbers, numbers.size());
    print_array(numbers, numbers.size());

    // Ask the user for a number
    int search;
    cout << endl << "Enter search number: ";
    cin >> search;

    // Using linear search, search the array for the user's number
    int position = linear_search(numbers, numbers.size(), search);

    // Print if the number was or was not found in the array
    if(position != -1)
    {
      cout << "<" << search << "> found at index <" << position << ">" << endl;
    }
    else
    {
      cout << "<" << search << "> not found in the" << endl;
    }

    return 0;
}
