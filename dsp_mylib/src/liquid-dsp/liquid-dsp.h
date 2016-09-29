#ifndef LIQUID_DSP_H
#define LIQUID_DSP_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void VECTOR_add(float *          _x,
                  float *          _y,
                  unsigned int _n,
                  float *          _z);


void VECTOR_addscalar(float *          _x,
                        unsigned int _n,
                        float            _v,
                        float *          _y);


void VECTOR_mul(float *          _x,
                  float *          _y,
                  unsigned int _n,
                  float *          _z);


void VECTOR_mulscalar(float *          _x,
                        unsigned int _n,
                        float            _v,
                        float *          _y);

/*

void dotprod_rrrf_run(float *      _h,
                      float *      _x,
                      unsigned int _n,
                      float *      _y);
*/

float liquid_filter_autocorr(float *      _h,
                             unsigned int _h_len,
                             int          _lag);

#endif
