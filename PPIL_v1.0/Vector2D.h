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
	inline explicit Vector2D(const double x = 0, const double y = 0);

	/**
	* @param  {Vector2D} u : The vector to add
	*
	* @return {Vector2D}   : The vector resulting from the addition
	*/
	inline const Vector2D operator + (const Vector2D& u) const;

	/**
	* @param  {double} a   : The constante that multiplie the vector
	*
	* @return {Vector2D*}  : The vector resulting from the multiplication
	*/
	inline const Vector2D operator* (const double& a) const;

	/**
	* @return {Vector2D}  : The inverse of the vector
	*/
	inline const Vector2D operator - () const;

	/**
	* @param  {Vector2D} v2 : The vector with which the equality is tested
	*
	* @return {bool}        : Return true if they are egal else false
	*/
	inline bool operator==(Vector2D& v2);

	/**
	* @param  {Vector2D} v2 : The vector with which the non equality is tested
	*
	* @return {bool}        : Return true if they are not egal else return false
	*/
	inline bool operator!=(Vector2D& v2);

	/**
	* Getter of x
	*
	* @return {double}  : The point's abscissa
	*/
	inline const double getX() const;

	/**
	* Getter of y
	*
	* @return {double}  : The point's ordinate
	*/
	inline const double getY() const;

	/**
	* Setter of x
	*
	* @param  {double} a : The new abscissa
	*/
	inline const void setX(const double a);

	/**
	* Setter of y
	*
	* @param  {double} a : the new ordinate
	*/
	inline const void setY(const double a);

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : A new vector2D with applied translation
	*/
	inline Vector2D translation(const Vector2D& v) const;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} center : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : A new Vector2D with applied homothety
	*/
	inline Vector2D homothety(const double k, const Vector2D& center = Vector2D(0, 0)) const;

	/**
	* Applies a rotation using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} center  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : A new Vector2D with applied rotation
	*/
	inline Vector2D rotation(const double angle, const Vector2D& center = Vector2D(0, 0)) const;

	/**
	*
	*/
	inline friend ostream& operator<<(ostream&, const Vector2D& c);

	/**
	*
	*/
	inline ostream& print(ostream& flux) const;
};

inline Vector2D operator*(const double a, const Vector2D& v) // v5 = 2.5 * v1
{
	return v * a;
}

inline Vector2D::Vector2D(const double x, const double y) : x(x), y(y) {}

inline const Vector2D Vector2D::operator + (const Vector2D& u) const 
{
	return Vector2D(x + u.x, y + u.y);
}

inline const Vector2D Vector2D::operator* (const double& a) const 
{
	return Vector2D(x * a, y * a);
}

inline const Vector2D Vector2D::operator - () const 
{
	return Vector2D(-x, -y);
}

inline bool Vector2D::operator==(Vector2D& v2) 
{
	return x == v2.getX() && y == v2.getY();
}

inline bool Vector2D::operator!=(Vector2D& v2) 
{
	return !(x == v2.getX() && y == v2.getY());
}

inline const Vector2D operator -(const Vector2D& u, const Vector2D& v) 
{
	return Vector2D(u.getX() - v.getX(), u.getY() - v.getY());
}

inline const double Vector2D::getX() const 
{
	return x;
}

inline const double Vector2D::getY() const
{
	return y;
}

inline const void Vector2D::setX(const double a) 
{
	x = a;
}

inline const void Vector2D::setY(const double a) 
{
	y = a;
}

inline Vector2D Vector2D::translation(const Vector2D& v) const 
{
	Vector2D r = *this + v;
	return r;
}

inline Vector2D Vector2D::homothety(const double k, const Vector2D& center) const 
{
	Vector2D r;
	return r = k * (*this - center) + center;
}

inline Vector2D Vector2D::rotation(const double angle, const Vector2D& center) const 
{
	double f = x - center.getX();
	double g = y - center.getY();
	double xf, yf;
	xf = f * cos(angle) + g * sin(angle) + center.getX();
	yf = -f * sin(angle) + g * cos(angle) + center.getY();
	Vector2D r(xf, yf);
	return r;
}

inline ostream& operator<<(ostream& flux, const Vector2D& c) 
{
	return c.print(flux);
}

inline ostream& Vector2D::print(ostream& flux) const 
{
	return (flux << "(" << x << "," << y << ")");
}