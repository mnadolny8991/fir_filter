/*
 * main.c
 */
#include "fir.h"

#define BUFFER_LEN	1024
#define COEFF_NUM 242

int out_tab[BUFFER_LEN];
int kronecker_delta[BUFFER_LEN];
int x[COEFF_NUM];
const int w[COEFF_NUM] = {0, 0, 0, 0, 0, 1, 1,-1,-1,-1, 0, 1, 2, 2, 1, 0,-2,-3,-3, 0,
 3, 5, 5, 2,-2,-6,-8,-5, 1, 7,11, 9, 2,-7,-14,-14,-7, 5,16,20,
14,-1,-17,-26,-23,-7,15,31,33,18,-9,-34,-44,-32,-2,33,54,49,18,-27,
-62,-68,-40,13,64,87,67, 9,-59,-103,-97,-41,43,112,130,81,-14,-112,-161,-130,
-29,97,185,185,88,-65,-198,-241,-163, 9,193,296,254,75,-163,-342,-361,-192,98,372,
483,353,18,-374,-625,-579,-214,331,799,924,567,-196,-1060,-1587,-1374,-226,1730,4057,6129,7348,
7348,6129,4057,1730,-226,-1374,-1587,-1060,-196,567,924,799,331,-214,-579,-625,-374,18,353,483,
372,98,-192,-361,-342,-163,75,254,296,193, 9,-163,-241,-198,-65,88,185,185,97,-29,
-130,-161,-112,-14,81,130,112,43,-41,-97,-103,-59, 9,67,87,64,13,-40,-68,-62,
-27,18,49,54,33,-2,-32,-44,-34,-9,18,33,31,15,-7,-23,-26,-17,-1,14,
20,16, 5,-7,-14,-14,-7, 2, 9,11, 7, 1,-5,-8,-6,-2, 2, 5, 5, 3,
0,-3,-3,-2, 0, 1, 2, 2, 1, 0,-1,-1,-1, 0, 1, 1, 0, 0, 0, 0, 0};

void create_buffer(int x[], int N);
void create_kronecker(int tab[], int N);

int main(void) {

	// Create buffer filled with zeros
	create_buffer(x, COEFF_NUM);

	// Create Kronecker delta
	create_kronecker(kronecker_delta, BUFFER_LEN);

	// Loop that simulates sample acquisition and filtering
	int samp_in;
	int samp_out;

	int i;
	for(i = 0; i < BUFFER_LEN; ++i) {

		samp_in = kronecker_delta[i];

		samp_out = fir(samp_in, w, COEFF_NUM, x);

		out_tab[i] = samp_out;

	}

	return 0;
}

void create_kronecker(int tab[], int N) {
	create_buffer(tab, N);
	tab[0] = 32767;
}

void create_buffer(int x[], int N) {
	int i;
	for (i = 0; i < N; ++i) {
		x[i] = 0;
	}
}
