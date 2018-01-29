/***********************
	Brayden Fidler
	bfidler
	Lab 11
	Lab Section 1
	Nick Glyder
***********************/

#include "functions.h"

void print_array(vector<int> &nums, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << nums.at(i) << " ";
	}
	
	cout << endl;
}

void selection_sort(vector<int> &num, int asize)
{
  for(int i = 0; i < asize; i++)
  {
    int min = i;
    
    for(int j = i + 1; j < asize; j++)
    {
      if(num.at(j) < num.at(min))
      {
        min = j;
      }
    }
    
    if(min != i)
    {
      int temp = num.at(i);
      num.at(i) = num.at(min);
      num.at(min) = temp;
    }
  }
}

int linear_search(vector<int> &nums, int asize, int search)
{
  int position = -1;
  int i = 0;
  while((i < asize) && (position == -1))
  {
    if(search == nums.at(i))
    {
      position = i;
    }
    i++;
  }
  
  return position;
}
