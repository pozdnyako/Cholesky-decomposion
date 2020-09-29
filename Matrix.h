#pragma once

#include <iostream>
#include <fstream>

class Matrix;
class Vector;

class Matrix {
public:
    Matrix();
    Matrix(std::istream &);
    Matrix(int);
    Matrix(const Matrix&);

    virtual ~Matrix();

    int i2x(int i) const { return i % N; }
    int i2y(int i) const  { return i / N; }
    int xy2i(int x, int y) const { return x + y*N; }

    double& get(int x, int y) { return data[xy2i(x, y)]; }
    double get(int x, int y) const { return data[xy2i(x, y)]; }

    double& el (int y, int x) const { return data[xy2i(x, y)]; }


    friend std::ostream& operator<<(std::ostream&, const Matrix &);
    friend Matrix& CholeskyDecomp(const Matrix& A);

    friend Vector& operator* (const Matrix&, const Vector&);

    int N;
private:
    double* data;
};

Matrix& CholeskyDecomp(const Matrix& A);

class Vector {
public:
    Vector();
    Vector(std::istream&);
    Vector(int);
    Vector(const Vector&);

    virtual ~Vector();

    double& operator[] (int i) const { return data[i]; }

    friend std::ostream& operator<<(std::ostream&, const Vector&);
    friend Vector& operator* (const Matrix&, const Vector&);

    int N;
private:

    double* data;
};