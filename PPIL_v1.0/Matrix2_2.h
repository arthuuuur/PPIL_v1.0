#pragma once

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Matrix2_2
{
	private :
		/**
		* Matrix 2x2
		*/
		vector<vector<double>> matrix;
		//Vector2D matrix[2];

	public:

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
		Matrix2_2(const double a1, const double a2, const double b1, const double b2);

		/**
		* Getter of matrix
		* 
		* @return {vector<vector<double>>} : the matrix
		*/
		const vector<vector<double>> getMatrix() const;
};

