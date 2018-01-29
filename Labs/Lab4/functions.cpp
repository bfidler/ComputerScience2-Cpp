/******************
	Brayden Fidler
	bfidler
	Lab 4
	Lab Section 1
	Nick Glyder
*****************/

#include "functions.h"

int checkPoint(point_t *p, point_t *test) {
	//Barycentric scalars
	double a,b,c;
	int check = 0;
	
	//calculates scalar values
	a = ((p[1].y - p[2].y) * (test->x - p[2].x) + (p[2].x - p[1].x) * (test->y -
		p[2].y)) / ((p[1].y - p[2].y) * (p[0].x - p[2].x) + (p[2].x - p[1].x) *
		(p[0].y - p[2].y));

	b = ((p[2].y - p[0].y) * (test->x - p[2].x) + (p[0].x - p[2].x) * (test->y -
		p[2].y)) / ((p[1].y - p[2].y) * (p[0].x - p[2].x) + (p[2].x - p[1].x) *
		(p[0].y - p[2].y));
	
	c = 1 - a - b;
	
	//checks scalar values to confirm if point is in traingle
	if ((a <= 1 && a >= 0) && (b <= 1 && b >= 0) && (c <= 1 && c >= 0))
		check = 1;

	return check;
}
