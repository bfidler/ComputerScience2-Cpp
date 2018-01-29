/***********************
	Brayden Fidler
	bfidler
	Lab 12
	Lab Section 1
	Nick Glyder
***********************/

#include <iostream>
//#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "functions.h"
using namespace std;


/*********************************************
 *This function should print each element in *
 *the array.                                 *
 *********************************************/
void print_array(int array[], int array_size )
{
	for(int i = 0; i < array_size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

//************************************************
// quickSort uses the quickSort algorithm to     *
// sort arr from arr[start] through arr[end].    *
// This is a recursive algorithm                 *
//************************************************
void quickSort(int array[], int start, int end)
{
  int p = partition(array, start, end);
  
  if (start < p - 1)
  {
    quickSort(array, start, p - 1);
  }
  
  if (p < end)
  {
    quickSort(array, p, end);
  }
}

//***********************************************************
// partition rearranges the entries in the array arr from   *
// start to end so all values greater than or equal to the  *
// pivot are on the right of the pivot and all values less  *
// than are on the left of the pivot.                       *
//***********************************************************
int partition(int arr[], int start, int end)
{

    /*Create two variables --
     *1 that is equal to the element of arr at [start]     *
     *2 that is the position of the pivot                  */

    int i = start, j = end;
    int p = (start + end)/2;

    // Rearrange the rest of the array elements to
    // partition the subrange from start to end
    while (i <= j) 
    {
      while(arr[i] < arr[p])
      {
        i++;
      };
      
      while(arr[j] > arr[p])
      {
        j--;
      };
      
      if (i <= j)
      {
        swap(arr[i], arr[j]);
        i++;
        j--;
      }
      
    };
    
  return i;
}

//**********************************************************
// The binarySearch function performs a recursive binary   *
// search on a range of elements of an integer array. The  *
// parameter first holds the subscript of the range's      *
// starting element, and last holds the subscript of the   *
// ranges's last element. The parameter value holds the    *
// the search value. If the search value is found, its     *
// array subscript is returned. Otherwise, -1 is returned  *
// indicating the value was not in the array.              *
//**********************************************************
int binarySearch(const int array[], int first, int last, int value)
{ 
    if(first <= last)
    {
      // Mid point of search
      int mid = (first + last) / 2; 

      // Base case
      if(value == array[mid])
      {
        return mid;
      }
      else
      {
        if(value > array[mid])
        {
          return binarySearch(array, mid + 1, last, value);
        }
        else
        {
          return binarySearch(array, first, mid - 1, value);
        }
      }
    }
    else
    {
      return -1;
    }  
}
