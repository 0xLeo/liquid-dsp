/*
	Originally at:
	liquid-dsp/src/vector/src/vector_add.c
*/





/*
 * Copyright (c) 2007 - 2015 Joseph Gaeddert
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

//
// Generic vector addition
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

// basic vector addition, unrolling loop
//  _x      :   first array  [size: _n x 1]
//  _y      :   second array [size: _n x 1]
//  _n      :   array lengths
//  _z      :   output array pointer [size: _n x 1]
void VECTOR_add(float* _x,
                  float* _y,
                  unsigned int _n,
                  float* _z)
{
    // t = 4*(floor(_n/4))
    unsigned int t=(_n>>2)<<2; 

    // compute in groups of 4
    unsigned int i;
    for (i=0; i<t; i+=4) {
        _z[i  ] = _x[i  ] + _y[i  ];
        _z[i+1] = _x[i+1] + _y[i+1];
        _z[i+2] = _x[i+2] + _y[i+2];
        _z[i+3] = _x[i+3] + _y[i+3];
    }

    // clean up remaining
    for ( ; i<_n; i++)
        _z[i] = _x[i] + _y[i];
}

// basic vector scalar addition, unrolling loop
//  _x      :   input array  [size: _n x 1]
//  _n      :   array length
//  _v      :   scalar
//  _y      :   output array pointer [size: _n x 1]
void VECTOR_addscalar(float* _x,
                        unsigned int _n,
                        float _v,
                        float* _y)
{
    // t = 4*(floor(_n/4))
    unsigned int t=(_n>>2)<<2; 

    // compute in groups of 4
    unsigned int i;
    for (i=0; i<t; i+=4) {
        _y[i  ] = _x[i  ] + _v;
        _y[i+1] = _x[i+1] + _v;
        _y[i+2] = _x[i+2] + _v;
        _y[i+3] = _x[i+3] + _v;
    }

    // clean up remaining
    for ( ; i<_n; i++)
        _y[i] = _x[i] + _v;
}

//-----------------------------------------------------------------------------------------
/*
	Originally at:
	https://github.com/jgaeddert/liquid-dsp/blob/master/src/vector/src/vector_mul.c
*/






/*
 * Copyright (c) 2007 - 2015 Joseph Gaeddert
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

//
// Generic vector multiplication
//


// basic vector multiplication, unrolling loop
//  _x      :   first array  [size: _n x 1]
//  _y      :   second array [size: _n x 1]
//  _n      :   array lengths
//  _z      :   output array pointer [size: _n x 1]
void VECTOR_mul(float* _x,
                  float* _y,
                  unsigned int _n,
                  float* _z)
{
    // t = 4*(floor(_n/4))
    unsigned int t=(_n>>2)<<2; 

    // compute in groups of 4
    unsigned int i;
    for (i=0; i<t; i+=4) {
        _z[i  ] = _x[i  ] * _y[i  ];
        _z[i+1] = _x[i+1] * _y[i+1];
        _z[i+2] = _x[i+2] * _y[i+2];
        _z[i+3] = _x[i+3] * _y[i+3];
    }

    // clean up remaining
    for ( ; i<_n; i++)
        _z[i] = _x[i] * _y[i];
}

// basic vector scalar multiplication, unrolling loop
//  _x      :   input array  [size: _n x 1]
//  _n      :   array length
//  _v      :   scalar
//  _y      :   output array pointer [size: _n x 1]
void VECTOR_mulscalar(float* _x,
                        unsigned int _n,
                        float _v,
                        float* _y)
{
    // t = 4*(floor(_n/4))
    unsigned int t=(_n>>2)<<2; 

    // compute in groups of 4
    unsigned int i;
    for (i=0; i<t; i+=4) {
        _y[i  ] = _x[i  ] * _v;
        _y[i+1] = _x[i+1] * _v;
        _y[i+2] = _x[i+2] * _v;
        _y[i+3] = _x[i+3] * _v;
    }

    // clean up remaining
    for ( ; i<_n; i++)
        _y[i] = _x[i] * _v;
}





/*
	available here:
	https://github.com/jgaeddert/liquid-dsp/blob/ee9e1da4c1a810bfc38a75b5777176ad1fb4fe57/src/dotprod/src/dotprod_rrrf.av.c
*/
void dotprod_rrrf_run(float *      _h,
                      float *      _x,
                      unsigned int _n,
                      float *      _y)
{
    float r=0;
    unsigned int i;
    for (i=0; i<_n; i++)
        r += _h[i] * _x[i];
    *_y = r;
}






/*
	availalbe here: 
	https://github.com/jgaeddert/liquid-dsp/blob/ee9e1da4c1a810bfc38a75b5777176ad1fb4fe57/src/filter/src/firdes.c
*/
float liquid_filter_autocorr(float *      _h,
                             unsigned int _h_len,
                             int          _lag)
{
    // auto-correlation is even symmetric
    _lag = abs(_lag);

    // lag outside of filter length is zero
    if (_lag >= _h_len) return 0.0f;

    // compute auto-correlation
    float rxx=0.0f; // initialize auto-correlation to zero
    unsigned int i;
    for (i=_lag; i<_h_len; i++)
        rxx += _h[i] * _h[i-_lag];

    return rxx;
}
