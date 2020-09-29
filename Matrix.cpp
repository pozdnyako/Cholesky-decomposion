#include "Matrix.h"
#include "Math.h"

Matrix::Matrix():
	data(NULL),
	N(0) {
}

Matrix::Matrix(int n) :
	N(n) {
	data = new double[N * N];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			data[xy2i(x, y)] = 0.0;
		}
	}
}

Matrix::Matrix(std::istream& in) {
	in >> N;

	data = new double[N * N];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			in >> data[xy2i(x, y)];
		}
	}
}

Matrix::Matrix(const Matrix& m):N(m.N) {
	data = new double[N * N];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			data[xy2i(x, y)] = m.data[xy2i(x,y)];
		}
	}
}

Matrix::~Matrix() {
	delete[] data;
}

std::ostream& operator<<(std::ostream& out, const Matrix& M) {
	out << "(" << M.N << "x" << M.N << "):\n";
	for (int y = 0; y < M.N; y++) {
		for (int x = 0; x < M.N; x++) {
			out << M.get(x, y) << "\t";
		}
		out << "\n";
	}

	return out;
}

Vector::Vector() :
	data(NULL),
	N(0) {
}

Vector::Vector(std::istream& in) {
	in >> N;

	data = new double[N];

	for (int i = 0; i < N; i++) {
		in >> data[i];
	}
}

Vector::Vector(int n) : N(n) {
	data = new double[N];

	for (int i = 0; i < N; i++) {
		data[i] = 0;
	}
}

Vector::Vector(const Vector& v) :N(v.N) {
	data = new double[N];

	for (int x = 0; x < N; x++) {
		data[x] = v.data[x];
	}
}


Vector::~Vector() {
	delete[] data;
}

double Vector::norm() const {
	double res = 0.0;

	for (int i = 0; i < N; i++) {
		res += data[i] * data[i];
	}

	return myMath::sqrt(res);
}


std::ostream& operator<<(std::ostream& out, const Vector& a) {
	out << "(" << a.N << "x1):\n";
	for (int x = 0; x < a.N; x++) {
		out << a[x] << "\n";
	}

	return out;
}

const Vector operator* (const Matrix& A, const Vector& b) {
	Vector c(A.N);

	for (int i = 0; i < c.N; i++) {
		for (int j = 0; j < c.N; j++) {
			c[i] += A.el(i, j) * b[j];
		}
	}

	return c;
}

const Vector operator-(const Vector& a, const Vector& b) {
	Vector c(a.N);

	for (int i = 0; i < c.N; i++) {
		c[i] = a[i] - b[i];
	}

	return c;
}

const Vector operator+(const Vector& a, const Vector& b) {
	Vector c(a.N);

	for (int i = 0; i < c.N; i++) {
		c[i] = a[i] + b[i];
	}

	return c;
}