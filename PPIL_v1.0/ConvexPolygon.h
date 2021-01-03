#pragma once

#include "Polygon.h"

class ConvexPolygon : public Polygon {
protected:

	/**
	* ConvexPolygon
	* protected to prevent the user from creating an empty polygon
	*/
	ConvexPolygon();

public:

	/**
	* ConvexPolygon
	*
	* @param  {vector<Vector2D>} S : the list of the points of the polygon
	*/
	ConvexPolygon(vector<Vector2D> S);

	/**
	* ConvexPolygon
	*
	* @param  {string} shapeColor  : the color of the polygon
	* @param  {vector<Vector2D>} S : the list of the points of the polygon
	*/
	ConvexPolygon(string shapeColor, vector<Vector2D> S);

	/**
	* ~ConvexPolygon
	*/
	virtual	~ConvexPolygon();

	/**
	* @return {double}  : the area of the polygon
	*/
	virtual const double getArea() const;

	/**
	* @param  {ostream} flux : the output stream
	* @return {ostream}      : return the output stream with the print of the convex Polygon
	*/
	ostream& print(ostream& flux) const;

	void accepte(ShapeVisitor* S);
};