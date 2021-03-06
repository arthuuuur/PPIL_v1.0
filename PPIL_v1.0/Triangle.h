#pragma once

#include "ConvexPolygon.h"

using namespace std;

class Triangle : public ConvexPolygon {

public:

	/**
	* Triangle's constructor
	*
	* @param  {Vector2D} v1 : First point
	* @param  {Vector2D} v2 : Second point
	* @param  {Vector2D} v3 : Third point
	*/
	Triangle(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3);

	/**
	* Triangle's constructor
	*
	* @param  {string} shapeColor : triangle's color
	* @param  {Vector2D} v1 : First point
	* @param  {Vector2D} v2 : Second point
	* @param  {Vector2D} v3 : Third point
	*/
	Triangle(const string shapeColor, const Vector2D& v1, const Vector2D& v2, const Vector2D& v3);

	/**
	* Triangle
	*
	* @param  {vector<Vector2D>} S : The list of the triangle's points
	*/
	Triangle(vector<Vector2D> S);

	/**
	* Triangle
	*
	* @param  {string} shapeColor  : Triangle's color
	* @param  {vector<Vector2D>} S : The list of the triangle's points
	*/
	Triangle(const string shapeColor, vector<Vector2D> S);

	/**
	* Calculate the triangle's area
	* 
	* @return {double}  : The triangle's area
	*/
	const double getArea() const;
};
