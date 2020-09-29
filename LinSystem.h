#pragma once
#include "Matrix.h"

class LinSystem {
public:
	LinSystem():N(0) {}
	LinSystem(std::istream& in) :A(in), b(in) { N = A.N;  }
	LinSystem(const Matrix &_A, const Vector &_b) :A(_A), b(_b) { N = A.N; }

	Vector& solve();
	int N;
private:
	Matrix A;
	Vector b;
};