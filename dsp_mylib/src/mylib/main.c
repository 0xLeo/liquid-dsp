/*
	USAGE:
	compile with:
		gcc
	flags:
		-compulory: -I.
		-recommended: -O2 -g -w
		-tests: -DTEST1x, where x = 1,2,...,9
		-input sizes: -DISZE1=<an integer> -DSIZE2=<an integer>
	comments:
		-test1 = dot product
		-test2 = autocorrelation
		-test3 = convolution
		-test4 = sum vectors
		-test5 = sum vectors unrolled
		-test6 = multiply vectors unrolled
		-test7 = sum all elements in a vector unrolled
		-test8 = sum all elements in a vector 
		-test9 = autocorrelation unrolled
		Only tesst3 requires two sizes to be defined, SIZE1 for input and SIZE2 for the mask. Vectors are filled with randoms numbers.
	example:
		gcc -I. -O2 -g -w main.c DSPlib.c -DSIZE1=12000 -DTEST7 -o test7
*/


#include <arm_neon.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "DSPlib.h"


#define SIZEMAX 30000

#ifndef SIZE1
	#define SIZE1 100
#endif
#ifndef SIZE2
	#define SIZE2 16
#endif

float32_t vec1[SIZEMAX] = {.0};
float32_t vec2[SIZEMAX] = {.0};

void testCorr(float32_t* vec, const unsigned int size) {

	struct timeval before, after;
		
	gettimeofday(&before, NULL);

	dsp_autocorr(vec, size);
	gettimeofday(&after, NULL);
	printf(" [+] autocorr for %d el/s took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}

void testDotProd(float32_t* vec1, float32_t* vec2, const int unsigned size) {

	struct timeval before, after;
	float32_t* prod = (float32_t*) malloc(sizeof(float32_t) * size), sum;
		
	gettimeofday(&before, NULL);

	// prod = dsp_mul_el(vec1, vec2, size);	
	// sum = dsp_sum_all_els(prod, size);
	sum = dsp_dot_prod_2(vec1, vec2, size);
	gettimeofday(&after, NULL);
	printf(" [+] dot prod for %d el/s took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);

}

void testdsp_conv(float32_t* vec1, float32_t* vec2, const unsigned int size1, const unsigned int size2 ) {
	
	struct timeval before, after;
		
	gettimeofday(&before, NULL);
	dsp_conv(vec1, vec2, size1, size2);
	gettimeofday(&after, NULL);

	printf(" [+] for input size %d, k size %d, dsp_conv took %ld us\n", size1, size2, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);

}

void testSumVec(float32_t* vec1, float32_t* vec2, const unsigned int size){

	struct timeval before, after;
		
	gettimeofday(&before, NULL);
	// functionality tested
	// output correct
	dsp_sum_vec(vec1, vec2, size);
	gettimeofday(&after, NULL);
	printf(" [+] for input size %d, sum took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}



void testSumVecUnr(float32_t* vec1, float32_t* vec2, const unsigned int size){

	struct timeval before, after;
		
	gettimeofday(&before, NULL);
	// functionality tested
	// output correct
	dsp_sum_vec_unrolled(vec1, vec2, size);
	gettimeofday(&after, NULL);
	printf(" [+] for input size %d, sum unr took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}



void testMulUnr(float32_t* vec1, float32_t* vec2, const unsigned int size){

	struct timeval before, after;
		
	gettimeofday(&before, NULL);
	// functionality not tested yet
	dsp_mul_el_unrolled(vec1, vec2, size);
	gettimeofday(&after, NULL);
	printf(" [+] for input size %d, mul unr took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}


void testSumUnr(float32_t* vec1, const unsigned int size){

	struct timeval before, after;
		
	gettimeofday(&before, NULL);
	// functionality not tested yet
	dsp_sum_all_els_unrolled(vec1, size);
	gettimeofday(&after, NULL);
	printf(" [+] for input size %d, sum of el/s unr took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}




void testSum(float32_t* vec1, const unsigned int size){

	struct timeval before, after;
		
	gettimeofday(&before, NULL);
	// functionality not tested yet
	dsp_sum_all_els(vec1, size);
	gettimeofday(&after, NULL);
	printf(" [+] for input size %d, sum of el/s unr took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}


void testCorrUnr(float32_t* vec, const unsigned int size) {

	struct timeval before, after;
		
	gettimeofday(&before, NULL);

	dsp_autocorr_unrolled(vec, size);
	gettimeofday(&after, NULL);
	printf(" [+] dsp_autocorr for %d el/s took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);
}


int main(){

	int i, r;
	srand(time(NULL));

	for (i = 0; i < SIZE1; i++) {
		r = rand();
		//*(vec1 +i ) = (i + 1); 
		*(vec1 +i ) = (float32_t) (r % 100000);
	}


	for (i = 0; i < SIZE2; i++) {
		r = rand();
		*(vec2 + i) = (float32_t) (r % 100000);
	}
	// define each test e.g. as -DTEST2 to test each function
	// dot prod 
	#ifdef TEST1
		testDotProd(vec1,vec1,SIZE1);
	#endif
	// autocorrelation
	#ifdef TEST2
		testCorr(vec1, SIZE1);
	#endif
	// convolution
	#ifdef TEST3
		testdsp_conv(vec1,vec2,SIZE1,SIZE2);
	#endif
	// vec sum
	#ifdef TEST4
		testSumVec(vec1, vec1, SIZE1);
	#endif
	// vec sum unrolled
	#ifdef TEST5
		testSumVecUnr(vec1, vec1, SIZE1);
	#endif
	// mul el unrolled
	#ifdef TEST6
		testMulUnr(vec1, vec1, SIZE1);
	#endif
	// sum all el/s unrolled
	#ifdef TEST7
		testSumUnr(vec1, SIZE1);
	#endif
	// sum all el/s
	#ifdef TEST8
		testSum(vec1, SIZE1);
	#endif
	#ifdef TEST9 // autocorr unrolled
		testCorrUnr(vec1, SIZE1);
	#endif
	return 0; 
} 
