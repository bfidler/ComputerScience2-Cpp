/********************
   Brayden Fidler
	bfidler
	Lab 3
	Lab Section 1
	Nick Glyder
*********************/


#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char magic[3];
    int height, width, maxval;
}header_t;

typedef struct
{
  unsigned char r, g, b;
}pixel_t;


void readHeader(FILE*, header_t *);

void createHeader(FILE*, header_t *);

void readPixels(FILE*, header_t *, pixel_t**);

void writePixels(FILE*, header_t *, pixel_t** );
