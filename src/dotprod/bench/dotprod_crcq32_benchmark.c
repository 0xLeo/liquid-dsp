/*
 * Copyright (c) 2007 - 2014 Joseph Gaeddert
 *
 * This file is part of liquid.
 *
 * liquid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * liquid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with liquid.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <sys/resource.h>
#include <stdlib.h>
#include "liquid.h"

// Helper function to keep code base small
void dotprod_crcq32_bench(struct rusage *_start,
                          struct rusage *_finish,
                          unsigned long int *_num_iterations,
                          unsigned int _n)
{
    // normalize number of iterations
    *_num_iterations *= 128;
    *_num_iterations /= _n;
    if (*_num_iterations < 1) *_num_iterations = 1;

    q32_t  h[_n];
    cq32_t x[_n];
    cq32_t y;
    unsigned int i;
    for (i=0; i<_n; i++) {
        h[i] = rand() % q32_one;
        
        x[i].real = rand() % q32_one;
        x[i].imag = rand() % q32_one;
    }

    // create dotprod structure;
    dotprod_crcq32 q = dotprod_crcq32_create(h,_n);

    // start trials
    getrusage(RUSAGE_SELF, _start);
    for (i=0; i<(*_num_iterations); i++) {
        dotprod_crcq32_execute(q, x, &y);
        dotprod_crcq32_execute(q, x, &y);
        dotprod_crcq32_execute(q, x, &y);
        dotprod_crcq32_execute(q, x, &y);
    }
    getrusage(RUSAGE_SELF, _finish);
    *_num_iterations *= 4;

    // clean up objects
    dotprod_crcq32_destroy(q);
}

#define DOTPROD_CRCQ32_BENCHMARK_API(N) \
(   struct rusage *_start,              \
    struct rusage *_finish,             \
    unsigned long int *_num_iterations) \
{ dotprod_crcq32_bench(_start, _finish, _num_iterations, N); }

void benchmark_dotprod_crcq32_4       DOTPROD_CRCQ32_BENCHMARK_API(4)
void benchmark_dotprod_crcq32_16      DOTPROD_CRCQ32_BENCHMARK_API(16)
void benchmark_dotprod_crcq32_64      DOTPROD_CRCQ32_BENCHMARK_API(64)
void benchmark_dotprod_crcq32_256     DOTPROD_CRCQ32_BENCHMARK_API(256)

