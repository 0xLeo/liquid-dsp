#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float sumAllElementsR(float* arr, const unsigned int size) {
	int i;
	float sum = .0;
	
	for (i = 0; i < size; i++)
		sum += *(arr + i);
	
	return sum;
}

float* mul_elR(float* vec1, float* vec2, const int size) {
	float* res = (float*) malloc(sizeof(float) * size);
	int i;

	for (i = 0; i < size; i++) 
		*(res + i) = ( *(vec1 + i)) * ( *(vec2 + i));

	return res;
}

float dot_prodR(float* vec1, float* vec2, const unsigned int size) {
	return sumAllElementsR(mul_elR(vec1,vec2,size), size);
}


float* autocorrR(float* vec1, const unsigned int size) {
	float* vec2 = (float*) calloc (.0, sizeof(float) * 2 * size);
	float* res = (float*) malloc (sizeof(float)* size);
	
	unsigned int start = 0, end = size - 1, lag = 0;
	float res_current;
	memcpy(vec2, vec1, size * sizeof(float));

	while (lag <= end) {
		res_current = dot_prodR(vec2 + lag, vec1, size);
		*(res + lag) = res_current;
		lag++;
	}

	return res;
}


float* sum_vecR(float* vec1, float* vec2, const unsigned int size) {
	float* result = (float*) malloc (sizeof(float) * size);
	unsigned int i;

	for (i = 0; i < size; i++) {
		*result = *vec1 + *vec2;
		result++;
		vec1++;
		vec2++;
	}
	
	result -= size;
	vec1 -= size;
	vec2 -= size;

	return result;
}


float* convR(float* vec1, float* vec2, const unsigned int size1, const unsigned int size2) {
	// temporarily!
	const int sizeOut = size1 + size2 - 1;
	float* res = (float*) calloc(.0, sizeof(float) * sizeOut);
	float* buff = (float*) calloc(.0, sizeof(float) * size2); // kernel 
	float* buff2 = (float*) calloc(.0, sizeof(float) * size1); // input
	float sum;

	int inCtr, buffMax = 0, buffCtr, inOffset = 0, outOfBounds = 0, indDP, indSum;
	float* prod = (float*) malloc(sizeof(float) * buffMax);

	for (inCtr = 0; inCtr < sizeOut ; inCtr++){
	//	float* prod = (float*) malloc(sizeof(float) * buffMax);

		// consider memmove for potential further opt
		// http://stackoverflow.com/questions/28623895/why-is-memmove-faster-than-memcpy
		for (buffCtr = 0; buffCtr < buffMax; buffCtr++) {
			*(buff +buffMax - buffCtr -1) = vec2[size2 - buffCtr - 1]; // kernel 
			if (buffMax < size2)
				*(buff2 + buffCtr ) = vec1[buffCtr]; // input
			else { 
				*(buff2 + buffCtr) = vec1[inOffset + buffCtr]; // input
				if (buffMax >= size2 && (inOffset + buffCtr >= size1))
					*(buff2 + size1 - buffCtr ) = .0;
			}
		}
		

		// dot prod loop
		// prod = mul_el(buff, buff2, buffMax);
		// sum = sumAllElements(prod, buffMax);
		// free(prod);

		for (indDP = 0; indDP < buffMax; indDP++) {
				
				*(prod + indDP) = *(buff + indDP) * (*(buff2 + indDP));
				

		}

		sum = .0;
		for (indSum = 0; indSum < buffMax; indSum++)
			sum += *(prod + indSum);

		if (buffMax < size2) {
			buffMax++;
			//float* prod = (float*) malloc(sizeof(float) * buffMax);
		}
		else 
			 inOffset++;
		#ifdef DBG
			for (buffCtr = 0; buffCtr < buffMax; buffCtr++) 
				printf("buffi[%d] = %f\n",buffCtr,*(buff2 + buffCtr));
			for (buffCtr = 0; buffCtr < buffMax; buffCtr++) 
				printf("buffi[%d] = %f\n",buffCtr,*(buff + buffCtr));
			printf("conv = %f, EOI\n ", sum);
		#endif

		*(res + inCtr) = sum;
	}
	//free(buff);
	//free(buff2);
	// freeing both -> double free error (why?), no problems in output though
	


	return res;
}
