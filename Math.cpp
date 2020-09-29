#include "Math.h"

class myMath::sqrtNegative : public std::exception {
public:
	sqrtNegative() {}
	const char* what() const { return "sqrt of negative number"; }
};

class myMath::divToNull : public std::exception {
public:
	divToNull() {}
	const char* what() const { return "divToNull"; }
};

double myMath::sqrt(double num, double EPS) {
	if (num < 0.0) {
		throw myMath::sqrtNegative();
	}

	double e = 1;

	double x = num;
	while (e > EPS) {
		x = Heron(x, num, e);
	}

	return x;
}

double myMath::Heron(double x_n, double num, double& e) {
	e = abs(num - x_n * x_n) / num / 2;
	return (x_n + num / x_n) / 2;
}