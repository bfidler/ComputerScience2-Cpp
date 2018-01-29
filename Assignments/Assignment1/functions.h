/*************************
 *Brayden Fidler
 *CPSC 1020 Section 1, Sp17
 *bfidler
*************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char type[3];
	int w, h, col;
} header_t;

typedef struct {
	unsigned char r, g, b;
} pixel_t;

void readHeader(header_t*, FILE*);
void readImage(header_t*, pixel_t **, FILE*);
void chooseTransform(header_t *, pixel_t **, FILE*);
void printP6Image(header_t*, pixel_t **, FILE*);
void grayScaleImage(header_t *, pixel_t **, FILE*);
void flipImage(header_t *, pixel_t **, FILE*);
void rotateLeft(header_t * , pixel_t **, FILE*);
void rotateRight(header_t *, pixel_t **, FILE*);
void color2Negative(header_t*, pixel_t **, FILE*);
void vertMirror(header_t*, pixel_t**, FILE*);
void horzMirror(header_t*, pixel_t**, FILE*);
void reprint(header_t*, pixel_t**, FILE*);

#endif //ifndef FUNCTIONS_H

