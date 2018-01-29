/****************
	Brayden Fidler
	bfidler
	Lab 4
	Lab Section 1
	Nick Glyder
****************/

#include "functions.h"

int main(void) {

	double width, height;
	point_t triPt[3];
	double i,j;
	int count;
	point_t testPt;

	cout << "Enter the dimensions of the plane(width then height)" << endl;
	cin >> width >> height;
	
	//ask the user for the coordinates of the triangle
	cout << "Enter point 1 x then y:" << endl;
	cin >> triPt[0].x >> triPt[0].y;
	cout << "Enter point 2 x then y:" << endl;
	cin >> triPt[1].x >> triPt[1].y;
	cout << "Enter point 3 x then y:" << endl;
	cin >> triPt[2].x >> triPt[2].y;
	
	cout << endl << endl << "HIT POINTS:" << endl;

	for(i = 0; i <= height; i++){
		for (j = 0; j <= width; j++) {
			//creates a point to test
			testPt.y = i;
			testPt.x = j;
			
			count = checkPoint(triPt, &testPt);
			//prints out points that are confirmed to be inside the triangle	
			if (count == 1) {
				cout << fixed << showpoint << setprecision(1) << j << ", ";
				cout << fixed << showpoint << setprecision(1) << i << endl;
			}
		}
	}

	return 0;
}

