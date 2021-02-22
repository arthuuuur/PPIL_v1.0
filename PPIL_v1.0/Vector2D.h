#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Vector2D {

private:

	/**
	* The point's abscissa
	*/
	double x;

	/**
	* The point's ordinate
	*/
	double y;

public:

	/**
	* Vector2D
	*
	* @param  {double} x : The point's abscissa
	* @param  {double} y : The point's ordinate
	*/
	Vector2D(const double x = 0, const double y = 0);

	/**
	* @param  {Vector2D} u : The vector to add
	* 
	* @return {Vector2D}   : The vector resulting from the addition
	*/
	const Vector2D operator + (const Vector2D& u) const;

	/**
	* @param  {double} a   : The constante that multiplie the vector
	* 
	* @return {Vector2D*}  : The vector resulting from the multiplication
	*/
	const Vector2D operator* (const double& a) const;

	/**
	* @return {Vector2D}  : The inverse of the vector
	*/
	const Vector2D operator - () const;

	/**
	* @param  {Vector2D} v2 : The vector with which the equality is tested
	* 
	* @return {bool}        : Return true if they are egal else false
	*/
	bool operator==(Vector2D& v2);

	/**
	* @param  {Vector2D} v2 : The vector with which the non equality is tested
	* 
	* @return {bool}        : Return true if they are not egal else return false
	*/
	bool operator!=(Vector2D& v2);

	/**
	* Getter of x
	* 
	* @return {double}  : The point's abscissa
	*/
	const double getX() const;

	/**
	* Getter of y
	* 
	* @return {double}  : The point's ordinate
	*/
	const double getY() const;

	/**
	* Setter of x
	* 
	* @param  {double} a : The new abscissa
	*/
	const void setX(const double a);

	/**
	* Setter of y
	* 
	* @param  {double} a : the new ordinate
	*/
	const void setY(const double a);

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : A new vector2D with applied translation
	*/
	Vector2D translation(const Vector2D& v) const;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} v : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : A new Vector2D with applied homothety
	*/
	Vector2D homothety(const Vector2D& center, const double k) const;

	/**
	* Applies a rotation using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} v  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : A new Vector2D with applied rotation
	*/
	Vector2D rotation(const Vector2D& center, const double angle) const;

	/**
	*
	*/
	friend ostream& operator<<(ostream&, const Vector2D& c);

	/**
	*
	*/
	ostream& print(ostream& flux) const;
};

inline Vector2D operator*(const double a, const Vector2D& v) // v5 = 2.5 * v1
{
	return v * a;
}

