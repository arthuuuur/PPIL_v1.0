#pragma once
#define _USE_MATH_DEFINES // to get the constante M_PI with the <math.h> include
#include "Vector2D.h"
#include "Shape.h"
#include "Error.h"

using namespace std;

class Circle : public Shape {

private:

	/**
	* The circle's center
	*/
	Vector2D _center;

	/**
	* The circle's radius
	*/
	double _radius;

public:

	/**
	* Circle
	*
	* @param  {Vector2D} x : The circle's center
	* @param  {double} radius : The circle's radius
	*/
	Circle(const Vector2D& v, const double radius);

	/**
	* Circle
	*
	* @param  {string} shapeColor : The circle's color
	* @param  {Vector2D} x : The circle's center
	* @param  {double} radius : The circle's radius
	*/
	Circle(const string shapeColor, const Vector2D& v, const double radius);

	/**
	* Calculate the circle's area
	* 
	* @return {double}  : The circle's ares
	*/
	const double getArea() const;

	/**
	* Getter of center
	* 
	* @return {Vector2D*}  : The circle's center
	*/
	Vector2D getCenter() const;

	/**
	* Getter of radius
	* 
	* @return {double}  : The circle's radius 
	*/
	const double getRadius() const;

	/**
	* Calculate and initialize the circle's gravity center
	*/
	void gravity();

	/**
	* Transforme the circle into a formatted string
	*
	* @return {string}  : Formatted string
	*/
	string serialize() const;

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : A new Circle with applied translation
	*/
	Shape* translation(const Vector2D& v) const;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} v : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : A new Circle with applied homothety
	*/
	Shape* homothety(const Vector2D& center, const double k) const;

	/**
	* Applies a rotation using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} v  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : A new Circle with applied rotation
	*/
    Shape* rotation(const Vector2D& center, const double angle) const;

	/**
	*
	*/
	ostream& print(ostream& flux) const;
};