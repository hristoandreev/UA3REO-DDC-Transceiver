#include "ldpc.h"
#include "constants.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int ldpc_check(uint8_t codeword[]);
static float fast_tanh(float x);
static float fast_atanh(float x);

// Packs a string of bits each represented as a zero/non-zero byte in plain[],
// as a string of packed bits starting from the MSB of the first byte of packed[]
void pack_bits(const uint8_t plain[], int num_bits, uint8_t packed[]) {
	int num_bytes = (num_bits + 7) / 8;
	for (int i = 0; i < num_bytes; ++i) {
		packed[i] = 0;
	}

	uint8_t mask = 0x80;
	int byte_idx = 0;
	for (int i = 0; i < num_bits; ++i) {
		if (plain[i]) {
			packed[byte_idx] |= mask;
		}
		mask >>= 1;
		if (!mask) {
			mask = 0x80;
			++byte_idx;
		}
	}
}

//
// does a 174-bit codeword pass the FT8's LDPC parity checks?
// returns the number of parity errors.
// 0 means total success.
//
static int ldpc_check(uint8_t codeword[]) {
	int errors = 0;

	for (int m = 0; m < FT8_LDPC_M; ++m) {
		uint8_t x = 0;
		for (int i = 0; i < kFT8_LDPC_num_rows[m]; ++i) {
			x ^= codeword[kFT8_LDPC_Nm[m][i] - 1];
		}
		if (x != 0) {
			++errors;
		}
	}
	return errors;
}

void bp_decode(float codeword[], int max_iters, uint8_t plain[], int *ok) {
	float tov[FT8_LDPC_N][3];
	float toc[FT8_LDPC_M][7];

	int min_errors = FT8_LDPC_M;

	// initialize message data
	for (int n = 0; n < FT8_LDPC_N; ++n) {
		tov[n][0] = tov[n][1] = tov[n][2] = 0;
	}

	for (int iter = 0; iter < max_iters; ++iter) {
		// Do a hard decision guess (tov=0 in iter 0)
		int plain_sum = 0;
		for (int n = 0; n < FT8_LDPC_N; ++n) {
			plain[n] = ((codeword[n] + tov[n][0] + tov[n][1] + tov[n][2]) > 0) ? 1 : 0;
			plain_sum += plain[n];
		}

		if (plain_sum == 0) {
			// message converged to all-zeros, which is prohibited
			break;
		}

		// Check to see if we have a codeword (check before we do any iter)
		int errors = ldpc_check(plain);

		if (errors < min_errors) {
			// we have a better guess - update the result
			min_errors = errors;

			if (errors == 0) {
				break; // Found a perfect answer
			}
		}

		// Send messages from bits to check nodes
		for (int m = 0; m < FT8_LDPC_M; ++m) {
			for (int n_idx = 0; n_idx < kFT8_LDPC_num_rows[m]; ++n_idx) {
				int n = kFT8_LDPC_Nm[m][n_idx] - 1;
				// for each (n, m)
				float Tnm = codeword[n];
				for (int m_idx = 0; m_idx < 3; ++m_idx) {
					if ((kFT8_LDPC_Mn[n][m_idx] - 1) != m) {
						Tnm += tov[n][m_idx];
					}
				}
				toc[m][n_idx] = fast_tanh(-Tnm / 2);
			}
		}

		// send messages from check nodes to variable nodes
		for (int n = 0; n < FT8_LDPC_N; ++n) {
			for (int m_idx = 0; m_idx < 3; ++m_idx) {
				int m = kFT8_LDPC_Mn[n][m_idx] - 1;
				// for each (n, m)
				float Tmn = 1.0f;
				for (int n_idx = 0; n_idx < kFT8_LDPC_num_rows[m]; ++n_idx) {
					if ((kFT8_LDPC_Nm[m][n_idx] - 1) != n) {
						Tmn *= toc[m][n_idx];
					}
				}
				tov[n][m_idx] = -2 * fast_atanh(Tmn);
			}
		}
	}

	*ok = min_errors;
}

// Ideas for approximating tanh/atanh:
// * https://varietyofsound.wordpress.com/2011/02/14/efficient-tanh-computation-using-lamberts-continued-fraction/
// * http://functions.wolfram.com/ElementaryFunctions/ArcTanh/10/0001/
// * https://mathr.co.uk/blog/2017-09-06_approximating_hyperbolic_tangent.html
// * https://math.stackexchange.com/a/446411

static float fast_tanh(float x) {
	if (x < -4.97f) {
		return -1.0f;
	}
	if (x > 4.97f) {
		return 1.0f;
	}
	float x2 = x * x;
	// float a = x * (135135.0f + x2 * (17325.0f + x2 * (378.0f + x2)));
	// float b = 135135.0f + x2 * (62370.0f + x2 * (3150.0f + x2 * 28.0f));
	// float a = x * (10395.0f + x2 * (1260.0f + x2 * 21.0f));
	// float b = 10395.0f + x2 * (4725.0f + x2 * (210.0f + x2));
	float a = x * (945.0f + x2 * (105.0f + x2));
	float b = 945.0f + x2 * (420.0f + x2 * 15.0f);
	return a / b;
}

static float fast_atanh(float x) {
	float x2 = x * x;
	// float a = x * (-15015.0f + x2 * (19250.0f + x2 * (-5943.0f + x2 * 256.0f)));
	// float b = (-15015.0f + x2 * (24255.0f + x2 * (-11025.0f + x2 * 1225.0f)));
	// float a = x * (-1155.0f + x2 * (1190.0f + x2 * -231.0f));
	// float b = (-1155.0f + x2 * (1575.0f + x2 * (-525.0f + x2 * 25.0f)));
	float a = x * (945.0f + x2 * (-735.0f + x2 * 64.0f));
	float b = (945.0f + x2 * (-1050.0f + x2 * 225.0f));
	return a / b;
}
