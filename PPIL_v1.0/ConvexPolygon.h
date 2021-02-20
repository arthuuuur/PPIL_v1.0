#pragma once

#include "Polygon.h"

class ConvexPolygon : public Polygon {

protected:

	/**
	* ConvexPolygon
	* Protected to prevent the user from creating an empty convex polygon
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
	ConvexPolygon(const string shapeColor, vector<Vector2D> S);


	/**
	* Calculate the area of the convex polygon
	* 
	* @return {double}  : The area of the convex polygon
	*/
	virtual const double getArea() const;

	/**
	* Allows to make a translation using a translation vector
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	*/
	Shape* translation(const Vector2D& v) const;

	/**
	* Allows to make a translation using an invariant point and a homothety ratio
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	* @param  {double} k  : The homothety ratio
	*/
	Shape* homothety(const Vector2D& centre, const double k) const;

	/**
	* Allows to make a rotation using an invariant point and a rotation angle
	*
	* @param  {double} ax    : The abscisse of the translation vector
	* @param  {double} ay    : The ordinate of the translation vector
	* @param  {double} angle : The angle of the rotation in degree
	*/
	Shape* rotation(const Vector2D& v, const double angle) const;

	/**
	* @param  {ostream} flux : the output stream
	* @return {ostream}      : return the output stream with the print of the convex Polygon
	*/
	ostream& print(ostream& flux) const;
};