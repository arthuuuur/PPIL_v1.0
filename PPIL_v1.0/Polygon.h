#pragma once

#include "Shape.h"

using namespace std;

class Polygon : public Shape {

protected:
	/**
	* The list of polygon's points
	*/
	vector<Vector2D> listPoints;

public:
	
	/**
	* Polygon's constructor
	*/
	Polygon();

	/**
	* Polygon's constructor
	*
	* @param  {vector<Vector2D>} S : The list of polygon's points
	*/
	Polygon(vector<Vector2D> S);

	/**
	* ~Polygon
	*/
	virtual ~Polygon();

	/**
	* Calculate the polygon's area
	* 
	* @return {double}  : The polygon's area
	*/
	virtual const double getArea() const = 0;

	/**
	* Calculate and initialize the polygon's gravity center
	*/
	void gravity();

	/**
	* Transforme the polygon into a formatted string
	*
	* @return {string}  : Formatted string
	*/
	const string serialize() const;

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : v1 new shape with applied translation
	*/
	Shape* translation(const Vector2D& v) const = 0;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} center : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : v1 new shape with applied homothety
	*/
	Shape* homothety(const double k, const Vector2D& centre = Vector2D(0, 0)) const = 0;

	/**
	* Applies a rotation in the counterclokwise using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} center  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : v1 new shape with applied rotation
	*/
	Shape* rotation(const double angle, const Vector2D& centre = Vector2D(0, 0)) const = 0;

	operator string() const;
};