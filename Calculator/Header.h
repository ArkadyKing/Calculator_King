#pragma once
#include <cmath>

namespace CalcF {
	double divF(double x, double y) {
		return x / y;
	}
	double multF(double x, double y) {
		return x * y;
	}
	double subF(double x, double y) {
		return x - y;
	}
	double plusF(double x, double y) {
		return x + y;
	}
	double xF(double x) {
		return x * x;
	}
	double sF(double x) {
		return sqrt(x);
	}
	double lnF(double x) {
		return log(x);
	}
	double lgF(double x) {
		return log10(x);
	}
}