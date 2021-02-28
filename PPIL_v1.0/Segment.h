#pragma once

#include <math.h>
#include "Vector2D.h"
#include "Shape.h"
#include "Error.h"

using namespace std;

class Segment : public Shape {

private:

	/**
	* The first extremity of the point
	*/
	Vector2D _p1; 
	
	/**
	* The second extremity of the point
	*/
	Vector2D _p2;  

public:

	/**
	* Segment
	*
	* @param  {Vector2D} p1 : First extremity
	* @param  {Vector2D} p2 : Seconde extremity
	*/
	Segment(const Vector2D& p1, const Vector2D& p2);

	/**
	* Segment
	*
	* @param  {string} shapeColor : The segment's color
	* @param  {Vector2D} p1 : First extremity
	* @param  {Vector2D} p2 : Seconde extremity
	*/
	Segment(const string shapeColor, const Vector2D& p1, const Vector2D& p2);

	/**
	* Getter of _p1
	* 
	* @return {Vector2D}  : The first extremity
	*/
	Vector2D getP1() const;

	/**
	* Getter of _p2
	* 
	* @return {Vector2D}  : the second extremity
	*/
	Vector2D getP2() const;

	/**
	* Calculate the segment's area
	* 
	* @return {double}  : the segment's area
	*/
	const double getArea() const;

	/**
	* calculates and initializes the segment's gravity center
	*/
	void gravity();

	/**
	* Transforme the segment into a formatted string
	*
	* @return {string}  : Formatted string
	*/
	const string serialize() const;

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : A new segment with applied translation
	*/
	Shape* translation(const Vector2D& v) const;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} center : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : A new segment with applied homothety
	*/
	Shape* homothety(const double k, const Vector2D& center = Vector2D(0, 0)) const;

	/**
	* Applies a rotation using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} center  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : A new segment with applied rotation
	*/
	Shape* rotation(const double angle, const Vector2D& center = Vector2D(0, 0)) const;

	/**
	*
	*/
	ostream& print(ostream& flux) const;
};