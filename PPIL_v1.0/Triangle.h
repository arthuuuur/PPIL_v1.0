#pragma once

#include "ConvexPolygon.h"
#include "Vector2D.h"

using namespace std;

class Triangle : public ConvexPolygon {

public:

	/**
	* Triangle
	*
	* @param  {double} ax : Abscissa of the first point
	* @param  {double} ay : Ordinate of the first point
	* @param  {double} bx : Abscissa of the second point
	* @param  {double} by : Ordinate of the second point
	* @param  {double} cx : Abscissa of the third point
	* @param  {double} cy : Ordinate of the third point
	*/
	Triangle(double ax, double ay, double bx, double by, double cx, double cy);

	/**
	* Triangle
	*
	* @param  {string} shapeColor : The color of the triangle
	* @param  {double} ax		  : Abscissa of the first point
	* @param  {double} ay		  : Ordinate of the first point
	* @param  {double} bx		  : Abscissa of the second point
	* @param  {double} by		  : Ordinate of the second point
	* @param  {double} cx		  : Abscissa of the third point
	* @param  {double} cy		  : Ordinate of the third point
	*/
	Triangle(string shapeColor, double ax, double ay, double bx, double by, double cx, double cy);

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
	Triangle(string shapeColor, vector<Vector2D> S);

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
