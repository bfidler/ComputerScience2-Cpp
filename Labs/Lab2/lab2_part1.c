/* This program reads in a ppm and outputs it 
	exactly the same */

/******************
	Brayden Fidler
	bfidler
	Lab 2
	Lab Section 2
	Nick Glyder
******************/

#include <stdio.h>

int main (int argc, char *argv[]) {
	char type[3];
	int height;
	int width;
	int max;

	FILE *InputPPM;
	FILE *OutputPPM;

	//Opens input/output files from command line
	InputPPM = fopen(argv[1], "r");
	OutputPPM = fopen(argv[2], "w");
	
	//Scans header from input then prints it to the output
	fscanf(InputPPM, "%s %d %d %d", type, &height, &width, &max);
	fprintf(OutputPPM, "%s\n%d %d %d\n", type, height, width, max);

	int i = 0;
	char color1;
	char color2;
	char color3;
	
	//scans and prints color values one by one
	for (; i < height * width; i++) {
		fscanf(InputPPM, " %c%c%c", &color1, &color2, &color3);
		fprintf(OutputPPM, "%c%c%c", color1, color2, color3);
	}

	return 0;
}

