#pragma once
#include <cmath>
#include <iostream>

namespace myMath {
	double sqrt(double num, double EPS = 1e-5);
	double Heron(double x_n, double num, double& e);

	class sqrtNegative;
	class divToNull;
}