#pragma once

#define _USE_MATH_DEFINES // to get the constante M_PI with the <math.h> include
#include "Vector2D.h"
#include "Shape.h"
#include "Error.h"

using namespace std;

class Circle : public Shape {
private:

	/**
	* The point representing the center of the circle
	*/
	Vector2D* center;

	/**
	* the radius of the circle
	*/
	double _radius;

public:

	/**
	* Circle
	*
	* @param  {double} x      : abscissa of the center
	* @param  {double} y      : ordinate of the center
	* @param  {double} radius : radius of the center
	*/
	Circle(double x, double y, double radius);

	/**
	* Circle
	*
	* @param  {string} shapeColor : the color of the circle
	* @param  {double} x          : the abscissa of the center
	* @param  {double} y          : the ordinate of the center
	* @param  {double} radius     : the radius of the center
	*/
	Circle(string shapeColor, double x, double y, double radius);

	/**
	* Circle
	*
	* @param  {Circle} c : the circle to be copied
	*/
	Circle(const Circle& c);

	/**
	* ~Circle
	*/
	~Circle();

	/**
	* @return {double}  : the area of the circle
	*/
	const double getArea() const;

	/**
	* @return {Vector2D}  : the center of the circle
	*/
	Vector2D getCenter() const;

	/**
	* @return {double}  : the radius of the circle
	*/
	const double getRadius() const;

	/**
	* calculates and initializes the center of gravity of the circle
	*/
	void gravity();

	/**
	* conversion from circle to string
	*
	* @return {string}  : reprensentation of this circle in string
	*/
	string serialize() const;

	/**
	* allows to make a translation using a translation vector
	*
	* @param  {double} ax : the abscisse of the translation vector
	* @param  {double} ay : the ordinate of the translation vector
	*/
	void translation(double ax, double ay);

	/**
	* allows to make a translation using an invariant point and a homothety ratio
	*
	* @param  {double} ax : the abscisse of the translation vector
	* @param  {double} ay : the ordinate of the translation vector
	* @param  {double} k  : the homothety ratio
	*/
	void homothety(double ax, double ay, double k);

	/**
	* allows to make a rotation using an invariant point and a rotation angle
	*
	* @param  {double} ax    : the abscisse of the translation vector
	* @param  {double} ay    : the ordinate of the translation vector
	* @param  {double} angle : the angle of the rotation in degrees
	*/
	void rotation(double ax, double ay, double angle);

	/**
	* @param  {ostream} flux : the output stream
	* @return {ostream}      : return the output stream with the print of the circle
	*/
	ostream& print(ostream& flux) const;
};