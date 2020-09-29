#include "Matrix.h"
#include "Math.h"

const Matrix CholeskyDecomp(const Matrix& A) {
	Matrix L(A.N);

	L.el(0, 0) = myMath::sqrt(A.el(0, 0));
	
	for (int j = 1; j < A.N; j++) {
		L.el(j, 0) = A.el(j, 0) / L.el(0, 0);
	}

	for (int j = 1; j < A.N; j++) {
		for (int i = 1; i < j; i++) {
			double sum = 0.0;

			for (int p = 0; p < A.N - 1; p++) {
				sum += L.el(i, p) * L.el(j, p);
			}

			L.el(j, i) = (A.el(j, i) - sum) / L.el(i, i);
		}

		double sum = 0.0;
		for (int p = 0; p <= j - 1; p++) {
			sum += L.el(j, p) * L.el(j, p);
		}

		L.el(j, j) = myMath::sqrt(A.el(j, j) - sum);
	}

	return L;
}
