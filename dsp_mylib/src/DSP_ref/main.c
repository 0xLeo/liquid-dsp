#include <arm_neon.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "refLib.h"

#define SIZE1MAX 40000
#define SIZE2MAX 40000

#ifndef SIZEONE
	#define SIZEONE 100
#endif
#ifndef SIZETWO
	#define SIZETWO 16
#endif

float32_t vec1[SIZE1MAX];
float32_t vec2[SIZE2MAX];

void testCorrR(float32_t* vec, const unsigned int size) {

	struct timeval before, after;
		
	gettimeofday(&before, NULL);

	autocorrR(vec, size);
	gettimeofday(&after, NULL);
	printf(" [+] autocorr for %d el/s took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}

void testDotProdR(float32_t* vec1, float32_t* vec2, const int unsigned size) {

	struct timeval before, after;
	float32_t* prod = (float32_t*) malloc(sizeof(float32_t) * size), sum;
		
	gettimeofday(&before, NULL);

	prod = mul_elR(vec1, vec2, size);	
	sum = sumAllElementsR(prod, size);
	gettimeofday(&after, NULL);
	printf(" [+] dot prod for %d el/s took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);

}

void testConvR(float32_t* vec1, float32_t* vec2, const unsigned int size1, const unsigned int size2 ) {
	
	struct timeval before, after;
		
	gettimeofday(&before, NULL);
	convR(vec1, vec2, size1, size2);
	gettimeofday(&after, NULL);

	printf(" [+] for input size %d, k size %d, conv took %ld us\n", size1, size2, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);

}

void testSumVecR(float32_t* vec1, float32_t* vec2, const unsigned int size){

	struct timeval before, after;
		
	gettimeofday(&before, NULL);
	sum_vecR(vec1, vec2, size);
	gettimeofday(&after, NULL);
	printf(" [+] for input size %d, sum took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}

int main(){

	int i;
		
	for (i = 0; i < SIZEONE; i++)
		*(vec1 +i ) = (float32_t) i;

	// [E]: did not replace SIZEONE with SIZETWO.
	//	run conv test again, this created garbage

	for (i = 0; i < SIZETWO; i++)
		*(vec2 + i) = (float32_t) i;

	// define each test e.g. as -DTEST2 to test each function
	// dot prod 
	#ifdef TEST1
		testDotProdR(vec1,vec1,SIZEONE);
	#endif
	// autocorr
	#ifdef TEST2
		testCorrR(vec1, SIZEONE);
	#endif
	// convol
	#ifdef TEST3
		testConvR(vec1,vec2,SIZEONE,SIZETWO);
	#endif
	// vec sum
	#ifdef TEST4
		testSumVecR(vec1, vec1, SIZEONE);
	#endif

	return 0; 
} 
