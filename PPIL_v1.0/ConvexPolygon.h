#pragma once

#include "Polygon.h"


class ConvexPolygon : public Polygon {

protected:

	/**
	* ConvexPolygon's constructor
	* Protected to prevent the user from creating an empty convex polygon
	*/
	ConvexPolygon();

public:

	/**
	* ConvexPolygon's constructor
	*
	* @param  {vector<Vector2D>} S : The list of the convex polygon's points
	*/
	ConvexPolygon(vector<Vector2D> S);

	/**
	* ConvexPolygon's constructor
	*
	* @param  {string} shapeColor  : The convex polygon's color
	* @param  {vector<Vector2D>} S : The list of the the convex polygon's points
	*/
	ConvexPolygon(const string shapeColor, vector<Vector2D> S);

	/**
	* Calculate the convex polygon's area
	* 
	* @return {double}  : The convex polygon's area
	*/
	virtual const double getArea() const;

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : v1 new ConvexPolygon with applied translation
	*/
	Shape* translation(const Vector2D& v) const;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} center : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : v1 new ConvexPolygon with applied homothety
	*/
	Shape* homothety(const double k, const Vector2D& center = Vector2D(0, 0)) const;

	/**
	* Applies a rotation in the counterclokwise using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} center  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : v1 new ConvexPolygon with applied rotation
	*/
	Shape* rotation(const double angle, const Vector2D& center = Vector2D(0, 0)) const;

};