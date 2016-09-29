#include <arm_neon.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "DSPlib.h"

float32_t dsp_sum_all_els(float32_t* arr, const unsigned int size) {

	// try: __builtin_prefetch(&array[SIZE]); // preload the cache
	//__builtin_prefetch(array);

	float32_t result, *arrP;		// i points @ array el/s
	float32x2_t vec64a, vec64b;		// to group 2/4 lanes of the 128 byte
	float32x4_t vec128 = vdupq_n_f32(0.0);	// init accum to all 0's
	float32x4_t temp128;			// buffer





	// dirty looping... but works 
	for (arrP = arr; (int)arrP < arr + (int)size; arrP += 4){ 

		temp128 = vld1q_f32(arrP);
		// 4 32-bit values in parallel (4 lanes)
		vec128 = vaddq_f32(vec128, temp128);	
	}

	// parallelise addition
	vec64a = vget_low_f32(vec128);		// split 128-bit vector
	vec64b = vget_high_f32(vec128); 	// into two 64-bit vectors
	vec64a = vadd_f32 (vec64a, vec64b); 	// add 64-bit vectors together

	result = vget_lane_f32(vec64a, 0);	// extract lanes and
	result += vget_lane_f32(vec64a, 1);	// add together scalars

	#ifdef DBG
		printf("sum all el/s = %f\n", result);
	#endif
	
	return result;
}

/*
	Assumes input size is a multiple of 16
	Otherwise it may produce seg faults or calculate wrong output
	functionality: output correct
*/
float32_t dsp_sum_all_els_unrolled(float32_t* arr, const unsigned int size) {

	// look up: __builtin_prefetch(&s[64]); // preload the cache

	float32_t result, *arrP;		// i points @ array el/s
	float32x2_t vec64a, vec64b;		// to group 2/4 lanes of the 128 byte
	float32x4_t vec128 = vdupq_n_f32(0.0);	// init accum to all 0's
	float32x4_t temp128;			// buffer
	unsigned int i, j, sizeMul16 = size &~ 15, sizeMod16 = size & 15;



	for (i = 0; i < sizeMul16; i += 16) {
		temp128 = vld1q_f32((int)arr + i);
		vec128 = vaddq_f32(vec128, temp128);

		#ifdef DBG
			for ( j = 0; j < 4; j++)
				printf("buff[%d] = %fi\n", j, temp128[j]);
		#endif
		temp128 = vld1q_f32((int)arr + i + 4);
		vec128 = vaddq_f32(vec128, temp128);
		#ifdef DBG
			for ( j = 0; j < 4; j++)
				printf("buff[%d] = %fi\n", j, temp128[j]);
		#endif

		temp128 = vld1q_f32((int)arr + i + 8);
		vec128 = vaddq_f32(vec128, temp128);
	
		#ifdef DBG
			for ( j = 0; j < 4; j++)
				printf("buff[%d] = %fi\n", j, temp128[j]);
		#endif
		temp128 = vld1q_f32((int)arr + i + 12);
		vec128 = vaddq_f32(vec128, temp128);

		#ifdef DBG
			for ( j = 0; j < 4; j++)
				printf("buff[%d] = %fi\n", j, temp128[j]);
		#endif

	}

	int indexMul16 = i;


	// handle leftovers (up to 16)
	// they are handled fine
	for (j = 0; j < 16; ++j) {
	
		if  ( j < sizeMod16 ) {
			temp128[j & 3] = *(arr + indexMul16 + j);
		} else {
			temp128[j & 3] = .0f;
		}

		if (( (j+1) & 3) == 0 ) { // if j + 1 mult of 4 find sum
			vec128 = vaddq_f32(vec128, temp128);
		}

	}

	// parallelise addition
	vec64a = vget_low_f32(vec128);		// split 128-bit vector
	vec64b = vget_high_f32(vec128); 	// into two 64-bit vectors
	vec64a = vadd_f32 (vec64a, vec64b); 	// add 64-bit vectors together
	
	result = vget_lane_f32(vec64a, 0);	// extract lanes and
	result += vget_lane_f32(vec64a, 1);	// add together scalars

	#ifdef DBG
		printf("sum all el/s = %f\n", result);
	#endif
	
	return result;
}



float32_t* dsp_mul_el(float* vec1, float* vec2, const unsigned int size) {
	float* res = (float*) malloc( sizeof(float) * size);
	int i;


	for (i = 0; i < size; i += 4)
		vst1q_f32(res + i, vmulq_f32(vld1q_f32(vec1 + i),vld1q_f32(vec2 + i)));


	return res;
}


float32_t* dsp_mul_el_unrolled(float* vec1, float* vec2, const int size) {

	float* res = (float*) malloc( sizeof(float) * size);
	int i;
	
	// best loop unrolling factor was found as 4
	// the following loop handles leftovers too
	for (i = 0; i < size; i += 4) {

		vst1q_f32(res + i, vmulq_f32(vld1q_f32(vec1 + i),vld1q_f32(vec2 + i)));
		vst1q_f32(res + i + 1, vmulq_f32(vld1q_f32(vec1 + i + 1),vld1q_f32(vec2 + i + 1)));
		
		vst1q_f32(res + i + 2, vmulq_f32(vld1q_f32(vec1 + i + 2),vld1q_f32(vec2 + i + 2)));
		vst1q_f32(res + i + 3, vmulq_f32(vld1q_f32(vec1 + i + 3),vld1q_f32(vec2 + i + 3)));

	}

        #ifdef DBG
                for (i = 0; i < SIZE1; i++) 
                        printf("%f * %f = mul el = %f\n",*(vec1+i), *(vec2 + i), *(res+i));
	#endif

	res -= size;
	return res;
}
/*
	input: two float vectors and their size
	output: a scalar float
	NOTES: this implementation is slower than dsp_dot_prod_2
*/

float32_t dsp_dot_prod (float* vec1, float* vec2, const unsigned int size) {
	#if defined UNR || defined UNROLLED || defined UNROLL
		return dsp_sum_all_els(dsp_mul_el_unrolled(vec1, vec2, size), size);
	#else
		return dsp_sum_all_els(dsp_mul_el(vec1, vec2, size), size);
	#endif
}


/*
	dot product using MACs
*/
float32_t dsp_dot_prod_2 (float* vec1, float* vec2, const unsigned int size) {


	float32x4_t vec1_x4, vec2_x4;
	float32x4_t sumvec_x4 = {0.0, 0.0, 0.0, 0.0};
	float32x2_t sum_x2_1, sum_x2_2;
	float result;
	unsigned int i, j, sizeMod4 = size & 3, sizeMul4 = size &~ 3 ;


	for(i = 0; i < sizeMul4; i += 4)
	{
 	 	// load 4 elements
	   	vec1_x4=vld1q_f32(&vec1[i]);
    		vec2_x4=vld1q_f32(&vec2[i]);
    		// = sumq + vec1_x4 *. vec2_x4
		sumvec_x4 = vmlaq_f32(sumvec_x4, vec1_x4, vec2_x4 );
	}
	
	// handle tail (last 0,1,2 or 3 el/s)
	for (j = 0; j < 4; ++j) {
		if (j < sizeMod4) {
			vec1_x4[j] = *(vec1 + i + j);
			vec2_x4[j] = *(vec2 + i + j);
			#ifdef DBG
				printf("leftovers: %f, %f\n",*(vec1 + j), *(vec2 + j));
			#endif
		} else {
			vec1_x4[j] = .0f; 
			vec2_x4[j] = .0f;
		}

	}
	// vec1 and vec2 store the last 4 el/s
	// do the final MAC
	sumvec_x4 = vmlaq_f32(sumvec_x4, vec1_x4, vec2_x4 );
	
	// same way as in element addition
	// high and low in parallel
	sum_x2_1 = vget_high_f32(sumvec_x4);
	sum_x2_2 = vget_low_f32(sumvec_x4);
	sum_x2_1 = vpadd_f32(sum_x2_1, sum_x2_2);
	sum_x2_1 = vpadd_f32(sum_x2_1, sum_x2_1);
	result = vget_lane_f32(sum_x2_1, 0);

	#ifdef DBG
		printf("el/s left = %d\n", size & 3);
		printf("dot prod = %f\n", result);
	#endif

	return result;

}
/* 
	Simulates the vector slide using two buffers.
	Takes into account 3 cases:
		- initial partial overlap
		- full overlap
		- final partial overlap
*/
float32_t* dsp_conv(float* vec1, float* vec2, const unsigned int size1, const unsigned int size2){
	// check against Octave or: 
	// https://g2384.github.io/collection/dsp_convolutionCalculator.html

	const int sizeOut = size1 + size2 - 1;
	float32_t* res = (float32_t*) calloc(sizeOut, sizeof(float32_t) );
	float32_t* buff1 = (float32_t*) calloc(size1, sizeof(float32_t) ); // input 
	float32_t* buff2 = (float32_t*) calloc(size2, sizeof(float32_t) ); // kernel
	float32_t* prod = (float32_t*) calloc(size2 + 1, sizeof(float32_t) ); // d.p. buffer
	float32_t sum;
	// TODO: don't forget to free buffers
	unsigned int i, inCtr, buffMax = 0, buffCtr, inOffset = 0;

	for (inCtr = 0; inCtr < sizeOut; inCtr++) {
		
		for (buffCtr = 0; buffCtr <= buffMax; buffCtr++) {
			if (buffMax < size2)
				*(buff1 + buffCtr) = *(vec1 + buffCtr);
			else {
				//inOffset++;
				*(buff1 + buffCtr) = *(vec1 +inOffset + buffCtr);
			}
			//inOffset++;
			*(buff2 + buffCtr) = *(vec2 + size2 - buffCtr - 1);
		}
			inOffset++;

		sum = dsp_dot_prod_2(buff1,buff2,buffMax);

		if (buffMax < size2)
			buffMax++;
		else if (inCtr < sizeOut - size2)
			inOffset++;
		
		#ifdef DBG
			for (buffCtr = 0; buffCtr < buffMax; buffCtr++) 
				printf("buffi[%d]=%f\n",buffCtr, *(buff1 + buffCtr));
			for (buffCtr = 0; buffCtr < buffMax; buffCtr++) 
				printf("buffk[%d]=%f\n",buffCtr, *(buff2 + buffCtr));
			printf("dsp_conv [%d]/%d = %f, in offs = %d\n", inCtr, buffMax, sum, inOffset);

		#endif

	}


	//free(buff);
	//free(buff2);
	// freeing both -> double free error (why?), no problems in output though
	
	return res;
}



/*
	steps: append size1 0's to vec1
	dot product for lag 0,
	dot product for lag 1
	... untill lag <= size
*/
float32_t* dsp_autocorr(float* vec1, const unsigned int size1) {
	float32_t* res = (float32_t*) malloc (sizeof(float) * size1);
	float32_t* vec2 = (float32_t*) malloc (sizeof(float) * 2 * size1);
	
	//if (size1 % 2 == 1) {
	//	float32_t* vec2 = (float32_t*) malloc (sizeof(float) * 2 * size1 + 1);
	//}
	int start = 0, end = size1 - 1, lag = 0;
	float32_t res_current;

	if (SIZE1 <= 10000) {
		// initial implementation
		memcpy(vec2, vec1, size1*sizeof(float32_t));
	} 
	// can copy up to 20000 elements
	else {
		memcpy(vec2, vec1, 10000 * sizeof(float32_t));
		memcpy(vec2 + 10000, vec1 + 10000, (size1 - 10000) * sizeof(float32_t));
	}

	while (lag <= end) {
		//*(res + lag ) = dsp_sum_all_els(dsp_mul_el(vec1, vec2+lag,size1),size1);
		*(res + lag) = dsp_dot_prod_2(vec1, vec2 + lag, size1);
		#ifdef DBG
			printf("dsp_autocorr = %f ",*(res+ lag));
		#endif
		lag++;
	}
	return res;			
}

/*
	TODO
*/
float32_t* dsp_autocorr_unrolled(float* vec1, const unsigned int size1) {

	float32_t* res = (float32_t*) malloc (sizeof(float) * size1);
	float32_t* vec2 = (float32_t*) malloc (sizeof(float) * 2 * size1);
	
	//if (size1 % 2 == 1) {
	//	float32_t* vec2 = (float32_t*) malloc (sizeof(float) * 2 * size1 + 1);
	//}
	int start = 0, end = size1 - 1, lag = 0;
	float32_t res_current;

	if (SIZE1 <= 10000) {
		// initial implementation
		memcpy(vec2, vec1, size1*sizeof(float32_t));
	} 
	// can copy up to 20000 elements
	else {
		memcpy(vec2, vec1, 10000 * sizeof(float32_t));
		memcpy(vec2 + 10000, vec1 + 10000, (size1 - 10000) * sizeof(float32_t));
	}

	while (lag <= end) {
		//*(res + lag ) = dsp_sum_all_els(dsp_mul_el(vec1, vec2+lag,size1),size1);
		*(res + lag + 0) = dsp_dot_prod_2(vec1, vec2 + lag + 0, size1);

		#ifdef DBG
			printf("dsp_autocorr = %f ",*(res+ lag));
		#endif
		lag ++;
	}
	return res;			

}


/*
        input: two vectors to be added and their size
        output: writes to float32_t* res 
*/
float32_t* dsp_sum_vec_unrolled(float* vec1, float* vec2, const unsigned int size) {
        float32_t* res = (float32_t*) malloc (sizeof(float) * size);
    
        // TODO: deal with leftovers (1,2,...,7), otherw assume input = n * 8
        unsigned int i, sizeBy16 = (int)(size /2); 
        float32x4_t f1, f2, f3, f4, f5, f6, f7, f8, fSum; 
    
    
        for (i = 0; i < 12500; i++) {
                f1 = vld1q_f32(vec1);
                f2 = vld1q_f32(vec2);
    		
                f3 = vld1q_f32(vec1 + 4);
                f4 = vld1q_f32(vec2 + 4);
                
		
		
		fSum = vaddq_f32(f1,f2); 
                vst1q_f32(res ,fSum);

		fSum = vaddq_f32(f3,f4); 
                vst1q_f32(res + 4,fSum);
    


		vec1 += 8;
                vec2 += 8;
                res += 8;
	}
    
        res -= size;    
	vec1 -= size;
	vec2 -= size;
        // do it also for vec1,2
    
        #ifdef DBG
                for (i = 0; i < SIZE1; i++) 
                        printf("%f/%d\n", *(res+i),SIZE1);
        #endif

        return res;
}

/*
        input: two vectors to be added and their size
        output: writes to float32_t* res 
*/
float32_t* dsp_sum_vec(float* vec1, float* vec2, const unsigned int size) {
        float32_t* res = (float32_t*) malloc (sizeof(float) * size);
    
        // TODO: deal with leftovers (1,2, or 3), otherw assume input = n * 4
        // UPDATE: they are already computed?
        unsigned int i, sizeBy4 = (int)(size >> 2); 
        float32x4_t f1, f2; 
        float32x4_t fSum;
    
    
        for (i = 0; i < sizeBy4; i++) {
                f1 = vld1q_f32(vec1);
                f2 = vld1q_f32(vec2);
    

                fSum = vaddq_f32(f1,f2); 
                vst1q_f32(res ,fSum);
    
                vec1 += 4;
                vec2 += 4;
                res += 4;
        }
    
        res -= size;    
	vec1 -= size;
	vec2 -= size;
        // do it also for vec1,2
    
        #ifdef DBG
                for (i = 0; i < size; i++) 
                        printf("vec sum = %f\n", *(res+i));
        #endif

        return res;
}
