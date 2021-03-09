#include "Matrix2_2.h"

/**
* Matrix2_2
* __________
* | a1 | a2 |
* |----|----|
* | b1 | b2 |
* -----------
*
* @param  {double} a1: First term
* @param  {double} a2: Second term
* @param  {double} b1: Third term
* @param  {double} b2: Fourth term
*
*/
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
