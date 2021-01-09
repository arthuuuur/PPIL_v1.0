#pragma once

#include "Polygon.h"

class ConvexPolygon : public Polygon {

protected:

	/**
	* ConvexPolygon
	* Protected to prevent the user from creating an empty  convex polygon
	*/
	ConvexPolygon();

public:

	/**
	* ConvexPolygon
	*
	* @param  {vector<Vector2D>} S : The list of the convex polygon's points
	*/
	ConvexPolygon(vector<Vector2D> S);

	/**
	* ConvexPolygon
	*
	* @param  {string} shapeColor  : The color of the convex polygon
	* @param  {vector<Vector2D>} S : The list of the the convex polygon's points
	*/
	ConvexPolygon(string shapeColor, vector<Vector2D> S);

	/**
	* ~ConvexPolygon
	*/
	virtual	~ConvexPolygon();

	/**
	* Calculate the area of the convex polygon
	* 
	* @return {double}  : The area of the convex polygon
	*/
	virtual const double getArea() const;

	/**
	* @param  {ostream} flux : the output stream
	* @return {ostream}      : return the output stream with the print of the convex Polygon
	*/
	ostream& print(ostream& flux) const;
};