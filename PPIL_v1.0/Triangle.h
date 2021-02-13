#pragma once

#include "ConvexPolygon.h"
#include "Vector2D.h"

using namespace std;

class Triangle : public ConvexPolygon {

public:

	/**
	* Triangle
	*
	* @param  {double} ax : The abscissa of the first point
	* @param  {double} ay : The ordinate of the first point
	* @param  {double} bx : The abscissa of the second point
	* @param  {double} by : The ordinate of the second point
	* @param  {double} cx : The abscissa of the third point
	* @param  {double} cy : The ordinate of the third point
	*/
	Triangle(const double ax, const double ay, const double bx, const double by, const double cx, const double cy);

	/**
	* Triangle
	*
	* @param  {string} shapeColor : The color of the triangle
	* @param  {double} ax		  : The abscissa of the first point
	* @param  {double} ay		  : The ordinate of the first point
	* @param  {double} bx		  : The abscissa of the second point
	* @param  {double} by		  : The ordinate of the second point
	* @param  {double} cx		  : The abscissa of the third point
	* @param  {double} cy		  : The ordinate of the third point
	*/
	Triangle(const SpecificColor shapeColor, const double ax, const double ay, const double bx, const double by, const double cx, const double cy);

	/**
	* Triangle
	*
	* @param  {vector<Vector2D>} S : The list of the triangle's points
	*/
	Triangle(vector<Vector2D> S);

	/**
	* Triangle
	*
	* @param  {string} shapeColor  : The color of the triangle
	* @param  {vector<Vector2D>} S : The list of the triangle's points
	*/
	Triangle(const SpecificColor, vector<Vector2D> S);

	/**
	* ~Triangle
	*/
	virtual ~Triangle();

	/**
	* Calculate the area of the triangle
	* 
	* @return {double}  : The area of the triangle
	*/
	const double getArea() const;

	/**
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the triangle
	*/
	ostream& print(ostream& flux) const;
};
