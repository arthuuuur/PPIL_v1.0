#include "Matrix2_2.h"

Matrix2_2::Matrix2_2(const double a1, const double a2, const double b1, const double b2)
{
	vector<double> v1, v2;
	v1.push_back(a1); v1.push_back(a2);
	v2.push_back(b1); v2.push_back(b2);
	matrix.push_back(v1); matrix.push_back(v2);
}

const vector<vector<double>> Matrix2_2::getMatrix() const
{
	return matrix;
}
