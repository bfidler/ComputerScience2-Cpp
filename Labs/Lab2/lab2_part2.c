/* This file creates a ppm */

/***********************
	Brayden Fidler
	bfidler
	Lab 2
	Lab Section 1
	Nick Glyder
************************/

#include <stdio.h>

int main (void) {
	
	//header printed out
	printf("P6\n400 600 255\n");
	int i = 0;
	
	//orange
	for(i = 0; i < (400 * 600 / 3); i++)
		printf("%c%c%c", 234, 106, 32);
	
	//white
	for(i = 0; i < (400 * 600 / 3); i++)
		printf("%c%c%c", 255, 255, 255);
	
	//purple
	for(i = 0; i < (400 * 600 / 3); i++)	
		printf("%c%c%c", 82, 45, 128);

	return 0;
}
