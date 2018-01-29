/*************************
 *Brayden Fidler
 *CPSC 1020 Section 1, Sp17
 *bfidler
*************************/

#include "functions.h"

void readHeader(header_t* myHead, FILE* input) {	
	
	//scans values of the header one by one
	fscanf(input, "%s %d %d %d ", myHead->type, &myHead->w, &myHead->h,
		&myHead->col); 
}

void readImage(header_t* myHead, pixel_t** myPix, FILE* input) {
	
	int i,j;
 
	//double loop to scan pixels into array
	for(i = 0; i < myHead->h; i++) {
		
		for (j = 0; j < myHead->w; j++) {
			
			fscanf(input, "%c%c%c", &myPix[i][j].r, &myPix[i][j].g,
				&myPix[i][j].b);
		}
	}
}

void chooseTransform(header_t* myHead, pixel_t** myPix, FILE* output) {
	
	char userInput;

	printf("\n*************************************************************\n");
	printf("Thank you for using the image transformer.\n");
	printf("There are several transformations you can preform\n");
	printf("on the input image. Choose the number that corresponds to the\n");
	printf("transformation you wish to perform on the image!\n");
	printf("*************************************************************\n");
	printf("\n1.	GrayScale\n2.	Color to Negative\n3.	Flip the Image\n");
	printf("4.	Rotate Right\n5.	Rotate Left\n6.	Reprint\n");
	printf("7.	Mirror Vertically\n8.	Mirror Horizontally\n\n");

	scanf(" %c", &userInput);
	
	//error trapping for user input
	while(userInput < '1' || userInput > '8') {
		
		printf("\n******************************************************"
			"******");
		printf("\nYou entered an incorrect number. Please, choose the\n");
		printf("number that corresponds with the transformation you\n");
		printf("wish to perform on the image.\n");
		printf("************************************************************"); 
		printf("\n\n1.	GrayScale\n2.	Color to Negative\n3.	Flip the Image");
		printf("\n4.	Rotate Right\n5.	Rotate Left\n6.	Reprint\n");
		printf("7.	Mirror Vertically\n8.	Mirror Horizontally\n\n");
		
		scanf(" %c", &userInput);
	}

	printf("\n");

	//appropriate function is used based on user input
	switch(userInput) {
		case '1':
			grayScaleImage(myHead, myPix, output);
			break;
		case '2':
			color2Negative(myHead, myPix, output);
			break;
		case '3':
			flipImage(myHead, myPix, output);
			break;
		case '4':
			rotateRight(myHead, myPix, output);
			break;
		case '5':
			rotateLeft(myHead, myPix, output);
			break;
		case '6':
			reprint(myHead, myPix, output);
			break;
		case '7':
			vertMirror(myHead, myPix, output);
			break;
		case '8':
			horzMirror(myHead, myPix, output);
			break;
		default:
			printf("An unknown error has occured.\n\n");
			break;
	}
}

void printP6Image(header_t* myHead, pixel_t** myPix, FILE* output) {

	int i,j;

   //header info printed out
	fprintf(output, "%s\n%d %d %d\n", myHead->type, myHead->w, myHead->h,
		myHead->col);

	//pixels printed out
	for(i = 0; i < myHead->h; i++) {

		for(j = 0; j < myHead->w; j++) {

      fprintf(output,"%c%c%c", myPix[i][j].r, myPix[i][j].g, myPix[i][j].b);
		}
	}
}

void grayScaleImage(header_t* myHead, pixel_t** myPix, FILE* output) {

	int i, j;
	int pix = 0;

	//header with P5 for grayscale
	fprintf(output, "P5\n%d %d %d\n", myHead->w, myHead->h, myHead->col);

	for(i = 0; i < myHead->h; i++) {
		
		for(j = 0; j < myHead->w; j++) {
			
			//pixels calculated and printed individually
			pix = (.299 * myPix[i][j].r) + (.587 * myPix[i][j].g) + 
				(.114 * myPix[i][j].b);
			fprintf(output, "%c", pix);
		}
	}
}

void flipImage(header_t* myHead, pixel_t** myPix, FILE* output) {

	int i,j;
	
	//allocating memory for pixel array for flip image
	pixel_t **flipPix = (pixel_t**)malloc(myHead->h * sizeof(pixel_t*));
	for(i = 0; i < myHead->h; i++)
		flipPix[i] = (pixel_t*)malloc(myHead->w * sizeof(pixel_t));

	//transferring pixels from orginal array to flip array
	for(i = 0; i < myHead->h; i++){

		for(j = 0; j < myHead->w; j++){

			flipPix[i][j] = myPix[myHead->h - i - 1][myHead->w - j - 1];
		}
	}

	printP6Image(myHead, flipPix, output);

	free(flipPix);
	
}

void rotateRight(header_t* myHead, pixel_t** myPix, FILE* output) {

	int temp;
	int i,j;
	
	//swapping height and width of header to rotate image
	temp = myHead->h;
	myHead->h = myHead->w;
	myHead->w = temp;

	//allocating memory for pixel array for right rotate
	pixel_t **rightPix = (pixel_t**)malloc(myHead->h * sizeof(pixel_t*));
	for(i = 0; i < myHead->h; i++)
		rightPix[i] = (pixel_t*)malloc(myHead->w * sizeof(pixel_t));

	//filling 2d array with swapped pixels
	for(i = 0; i < myHead->h; i++){

		for(j = 0; j < myHead->w; j++) {
			
		  rightPix[i][j] = myPix[myHead->w - 1 - j][i];
		}
	}

	printP6Image(myHead, rightPix, output);
}

void rotateLeft(header_t* myHead, pixel_t** myPix, FILE* output) {

	int temp;
	int i,j;
	
	//swapping height and width of header to rotate image
	temp = myHead->h;
	myHead->h = myHead->w;
	myHead->w = temp;

	//allocating memory for pixel array for left rotate
	pixel_t **leftPix = (pixel_t**)malloc(myHead->h * sizeof(pixel_t*));
	for(i = 0; i < myHead->h; i++)
		leftPix[i] = (pixel_t*)malloc(myHead->w * sizeof(pixel_t));

	//filling 2d array with swapped pixels
	for(i = 0; i < myHead->h; i++){

		for(j = 0; j < myHead->w; j++) {
			
			leftPix[i][j] = myPix[j][myHead->h - 1 - i];
		}
	}

	printP6Image(myHead, leftPix, output);
}

void color2Negative(header_t* myHead, pixel_t** myPix, FILE* output){
	 
   int i,j;

   //header info printed out
   fprintf(output, "%s\n%d %d %d\n", myHead->type, myHead->w, myHead->h,
      myHead->col);

   //pixels printed out
   for(i = 0; i < myHead->h; i++) {

      for(j = 0; j < myHead->w; j++) {
          
          //using 255 to swap to negative values
          fprintf(output,"%c%c%c", 255 - myPix[i][j].r, 255 - myPix[i][j].g,
            255 - myPix[i][j].b);
      }
   }
}

void vertMirror(header_t* myHead, pixel_t** myPix, FILE* output) {
	
	int i, j;
  int midCol = myHead->w / 2;

	//creates 2d array for the mirror
	pixel_t **vertPix = (pixel_t**)malloc(myHead->h * sizeof(pixel_t*));
	for(i = 0; i < myHead->h; i++)
		vertPix[i] = (pixel_t*)malloc(myHead->w * sizeof(pixel_t));

  //fill left side of mirror
  for(i = 0; i < myHead->h; i++) {
  
    for(j = 0; j < myHead->w; j++) {
      
      //filling mirror
      if(j < midCol)
        //left half
        vertPix[i][j] = myPix[i][j];
      else
        //right half
        vertPix[i][j] = myPix[i][myHead->w - 1 - j];
    }
  }

	printP6Image(myHead, vertPix, output);
	free(vertPix);
}

void horzMirror(header_t* myHead, pixel_t** myPix, FILE* output) {
	
	int i, j;
  int midRow = myHead->h / 2;

	//creates 2d array for the mirror
	pixel_t **horzPix = (pixel_t**)malloc(myHead->h * sizeof(pixel_t*));
	for(i = 0; i < myHead->h; i++)
		horzPix[i] = (pixel_t*)malloc(myHead->w * sizeof(pixel_t));

  //fill top half of mirror
  for(i = 0; i < midRow; i++) {
  
    for(j = 0; j < myHead->w; j++) {
    
      horzPix[i][j] = myPix[i][j];
    }
  }
  
  //fill bottom half of mirror
  for(; i < myHead->h; i++) {
  
    for(j = 0; j < myHead->w; j++) {
    
      horzPix[i][j] = myPix[myHead->h - 1 -i][j];
    }
  }

	printP6Image(myHead, horzPix, output);
	free(horzPix);
}

void reprint(header_t* myHead, pixel_t** myPix, FILE* output) {
	
	printP6Image(myHead, myPix, output);
}
