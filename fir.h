/*
 * fir.h
 *
 *  Created on: 23 may 2020
 *  Author: Micha³ Nadolny
 *
 */

#ifndef FIR_H_
#define FIR_H_

/* fir filter
 *
 * INPUT:
 * xin - input sample
 * w - filter coefficients array
 * N - number of filter coefficients
 * x - sample buffer array
 *
 * OUTPUT:
 * y - current output value of a filter
 */
int fir(int xin, int w[], int N, int x[]);

#endif /* FIR_H_ */
