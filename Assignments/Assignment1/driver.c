/*************************
 *Brayden Fidler
 *CPSC 1020 Section 1, Sp17
 *bfidler
*************************/


#include "functions.h"

int main(int argc, char *argv[]){
	
	//checks to make sure two filenames were in command line
	if(argc != 3){
		printf("Please enter files in the command line\n");
		exit(0);
	}

	int i;
	header_t ppmHeader;
	FILE *inpFile;
	FILE *outFile;
	
	//opens files using command line
	inpFile = fopen(argv[1], "r");
	outFile = fopen(argv[2], "w");
	
	//checks if in/output files opened properly
	if(inpFile == NULL) {
		printf("Input file couldn't be opened.\n");
		exit(0);
	}
	
	if(outFile == NULL) {
		printf("Output file couldn't be opened.\n");
		exit(0);
	}

	readHeader(&ppmHeader, inpFile);
	
	//allocates memory for pixel array
	pixel_t **ppmPixels = (pixel_t**)malloc(sizeof(pixel_t*) * ppmHeader.h);
	for(i = 0; i < ppmHeader.h; i++)
		ppmPixels[i] = (pixel_t*)malloc(sizeof(pixel_t) * ppmHeader.w);
	
	readImage(&ppmHeader, ppmPixels, inpFile);

	chooseTransform(&ppmHeader, ppmPixels, outFile);

	//freeing/closing memory and files
	free(ppmPixels);
	fclose(inpFile);
	fclose(outFile);

	return 0;
}
