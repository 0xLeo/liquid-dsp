#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "liquid-dsp.h"
#include <time.h>

#ifndef SIZE1
	#define SIZE1 100
#endif
#ifndef SIZE2
	#define SIZE2 100
#endif
#define SIZEMAX 30000

float vec1[SIZEMAX] = {.0f};
float vec2[SIZEMAX] = {.0f};

#ifdef TEST3
void testVECTOR_add(float* vec1, float* vec2, const unsigned int size) {

	// output to write to
	float* out = (float*) malloc(sizeof(float) * SIZE1);
	struct timeval before, after;
		
	gettimeofday(&before, NULL);

	VECTOR_add(vec1, vec2, size, out);
	gettimeofday(&after, NULL);
	printf(" [+] vector addition for %d el/s took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);

	free(out);
}
#endif

void testVECTOR_mul (float* vec1, float* vec2, const unsigned int size) {

	// output to write to
	float* out = (float*) malloc(sizeof(float) * SIZE1);
	struct timeval before, after;
		
	gettimeofday(&before, NULL);

	VECTOR_mul(vec1, vec2, size, out);
	gettimeofday(&after, NULL);
	printf(" [+] vector mul for %d el/s took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);

	free(out);
}

#ifdef TEST1

void testdotprod_rrrf_run (float* vec1, float* vec2, const unsigned int size) {

	// output to write to
	float out;  
	struct timeval before, after;
		
	gettimeofday(&before, NULL);

	dotprod_rrrf_run (vec1, vec2, size, &out);
	gettimeofday(&after, NULL);
	printf(" [+] vector dot prod for %d el/s took %ld us\n", size, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);

	//free(out);
}
#endif

#ifdef TEST2
void testliquid_filter_crosscorr(float *      _h,
                              unsigned int _h_len,
                              int          _lag)
{
	// output to write to
	float out;  
	struct timeval before, after;
	int i;
		
	gettimeofday(&before, NULL);

	for (i = 0; i < _h_len; i++) {
		liquid_filter_autocorr (_h,
                              _h_len,
                              i);
	}	
	gettimeofday(&after, NULL);
	printf(" [+] autocorr for %d el/s took %ld us\n", _h_len, (after.tv_sec - before.tv_sec) * 1000000 + after.tv_usec - before.tv_usec);

	//free(out);
}

#endif



int main() {
	
	int i = 0, r;
	srand(time(NULL));

	for (; i < SIZE1; i++) {
		r = rand();
		// to avoid overflows, otherwise remove the %
		*(vec1 + i) = *(vec2 + i) = (float) (r % 100000);
	}
	#ifdef TEST1 // dot prod 
		testdotprod_rrrf_run(vec1, vec2, SIZE1);
	#endif
	#ifdef TEST2 // autocorr
		testliquid_filter_crosscorr(vec1, SIZE1, 0);
	#endif
	#ifdef TEST3
		testVECTOR_add(vec1, vec2, SIZE1);
	#endif
}

