#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SIZEONE 
	#define SIZEONE 100
#endif

#ifndef SIZETWO 
	#define SIZETWO 20
#endif

float sumAllElementsR(float* arr, const unsigned int size);

float* mul_elR(float* vec1, float* vec2, const int size);
float dot_prodR(float* vec1, float* vec2, const unsigned int size);
float* autocorrR(float* vec1, const unsigned int size);
float* sum_vecR(float* vec1, float* vec2, const unsigned int size);
float* convR(float* vec1, float* vec2, const unsigned int size1, const unsigned int size2);

