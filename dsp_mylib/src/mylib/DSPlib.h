#include <arm_neon.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SIZE
	#define SIZE 20000
#endif

float32_t dsp_sum_all_els(float32_t* arr, const unsigned intsize);
float32_t* dsp_mul_el(float* vec1, float* vec2, const unsigned int size);
float32_t* dsp_conv(float* vec1, /* input */
		float* vec2, /* kernel */
		const unsigned int size1, 
		const unsigned int size2);
float32_t* dsp_autocorr(float* vec1, const unsigned int size1); 
float32_t* dsp_sum_vec(float* vec1, float* vec2, const unsigned int size); 
