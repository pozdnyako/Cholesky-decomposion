#include "LinSystem.h"

Vector& LinSystem::solve() {
	Vector y(N);
	Vector* x = new Vector(N);


	std::cout << "A = " << A << std::endl << "b = " << b << std::endl;

	Matrix L = CholeskyDecomp(A);
	std::cout << "L = " << L << std::endl;

	for (int i = 0; i < N; i++) {
		y[i] = b[i];

		for (int j = 0; j < i; j++) {
			y[i] -= y[j] * L.el(i, j);
		}

		y[i] /= L.el(i, i);
	}

	std::cout << "y = " << y << std::endl;

	for (int i = N - 1; i >= 0; i--) {
		(*x)[i] = y[i];

		for (int j = N-1; j > i; j--) {
			(*x)[i] -= (*x)[j] * L.el(j, i);
		}

		(*x)[i] /= L.el(i, i);
	}

	return *x;
}