#pragma once
#define _USE_MATH_DEFINES // to get the constante M_PI with the <math.h> include
#include "Vector2D.h"
#include "Shape.h"
#include "Error.h"

using namespace std;

class Circle : public Shape {

private:

	/**
	* The center of the circle
	*/
	Vector2D* _center;

	/**
	* The radius of the circle
	*/
	double _radius;

public:

	/**
	* Circle
	*
	* @param  {double} x      : The abscissa of the center
	* @param  {double} y      : The ordinate of the center
	* @param  {double} radius : The radius of the circle
	*/
	Circle(const double x, const double y, const double radius);

	/**
	* Circle
	*
	* @param  {string} shapeColor : The color of the circle
	* @param  {double} x          : The abscissa of the center
	* @param  {double} y          : The ordinate of the center
	* @param  {double} radius     : The radius of the circle
	*/
	Circle(const SpecificColor shapeColor, const double x, const double y, const double radius);

	/**
	* Circle
	*
	* @param  {Circle&} c : The circle to be copied
	*/
	Circle(const Circle& c);

	/**
	* ~Circle
	*/
	~Circle();

	/**
	* Calculate the area of the circle
	* 
	* @return {double}  : The area of the circle
	*/
	const double getArea() const;

	/**
	* Getter of center
	* 
	* @return {Vector2D*}  : The center of the circle
	*/
	Vector2D getCenter() const;

	/**
	* Getter of radius
	* 
	* @return {double}  : The radius of the circle
	*/
	const double getRadius() const;

	/**
	* Calculate and initialize the gravity center of the circle
	*/
	void gravity();

	/**
	* Conversion of Circle into string
	*
	* @return {string}  : Reprensentation of the circle in string
	*/
	string serialize() const;

	/**
	* Allows to make a translation using a translation vector
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	*/
	void translation(const double ax, const double ay);

	/**
	* Allows to make a translation using an invariant point and a homothety ratio
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	* @param  {double} k  : The homothety ratio
	*/
	void homothety(const double ax, double ay, const double k);

	/**
	* Allows to make a rotation using an invariant point and a rotation angle
	*
	* @param  {double} ax    : The abscisse of the translation vector
	* @param  {double} ay    : The ordinate of the translation vector
	* @param  {double} angle : The angle of the rotation in degree
	*/
	void rotation(const double ax, double ay, const double angle);

	/**
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the circle
	*/
	ostream& print(ostream& flux) const;
};