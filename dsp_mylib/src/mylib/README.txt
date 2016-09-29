This directory contains my own implementations including ARM Neon optimisations.

COMPILATION INSTRUCTIONS

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
		Only test3 requires two sizes to be defined, SIZE1 for input and SIZE2 for the mask. Vectors are filled with random numbers.
	example:
		gcc -I. -O2 -g -w main.c DSPlib.c -DSIZE1=12000 -DTEST7 -o test7

