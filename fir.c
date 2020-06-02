/*
 * fir.c
 *
 *  Created on: 23 may 2020
 *  Author: Micha³ Nadolny
 *
 */
#include "fir.h"

int* buffr_ptr;

int fir(int xin, int w[], int N, int x[]) {

	// If buffer is empty or not loaded return 0
	static int loaded = 0;
	static int n = 0;

	if (!loaded) {
		x[n] = xin;
		buffr_ptr = &x[n];
		++n;
		if (n >= N) loaded = 1;
		return 0;
	}

	// Else return filtered output value
	if (n >= N) {
		buffr_ptr = &x[0];
		n = 0;
	} else {
		++buffr_ptr;
		++n;
	}
	*buffr_ptr = xin;

	int y = 0;
	int i;
	// Initialize counter with start value n
    int j = N - n - 1;
	for (i = 0; i < N; ++i) {
		y += w[i] * x[(N - 1) - (j % N)];
	 	++j;
	}

	return y;

}




