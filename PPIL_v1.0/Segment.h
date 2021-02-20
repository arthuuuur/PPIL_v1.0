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
	* @param  {double} p1x : The abscissa of the first point
	* @param  {double} p1y : The ordinate of the first point
	* @param  {double} p2x : The abscissa of the second point
	* @param  {double} p2y : The ordinate of the second point
	*/
	Segment(const Vector2D& p1, const Vector2D& p2);

	/**
	* Segment
	*
	* @param  {string} shapeColor : The color of the segment
	* @param  {double} p1x        : The abscissa of the first point
	* @param  {double} p1y        : The ordinate of the first point
	* @param  {double} p2x        : The abscissa of the second point
	* @param  {double} p2y        : The ordinate of the second point
	*/
	Segment(const string shapeColor, const Vector2D& p1, const Vector2D& p2);

	/**
	* ~Segment
	*/
	~Segment();

	/**
	* Getter of _p1
	* 
	* @return {Vector2D}  : The first extremity of the segment
	*/
	Vector2D getP1() const;

	/**
	* Getter of _p2
	* 
	* @return {Vector2D}  : the second extremity of the segment
	*/
	Vector2D getP2() const;

	/**
	* Calculate the are of the segment
	* 
	* @return {double}  : the area of the segment
	*/
	const double getArea() const;

	/**
	* calculates and initializes the gravity center of the segment
	*/
	void gravity();

	/**
	* Conversion of segment into string
	*
	* @return {string}  : Reprensentation of the segment in string
	*/
	string serialize() const;

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
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the circle
	*/
	ostream& print(ostream& flux) const;
};