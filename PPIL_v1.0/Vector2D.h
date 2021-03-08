#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include "Matrix2_2.h"
#include "Error.h"

using namespace std;

class Vector2D {

public:

	/**
	* The point's abscissa
	*/
	double x;

	/**
	* The point's ordinate
	*/
	double y;

	/**
	* Vector2D
	*
	* @param  {double} x : The point's abscissa
	* @param  {double} y : The point's ordinate
	*/
	inline explicit Vector2D(const double x = 0, const double y = 0);

	inline const double det(const Vector2D& u) const;

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
	* Divide the coordinate of the vector by a
	* 
	* @param  {double} a   : The constante that divides the vector
	*
	* @return {Vector2D*}  : The vector resulting from the division
	*/
	inline const Vector2D operator/ (const double& a) const;

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

	inline const Vector2D operator* (const Matrix2_2& M) const;

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : v1 new vector2D with applied translation
	*/
	inline Vector2D translation(const Vector2D& v) const;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} center : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : v1 new Vector2D with applied homothety
	*/
	inline Vector2D homothety(const double k, const Vector2D& center = Vector2D(0, 0)) const;

	/**
	* Applies a rotation in the counterclokwise using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} center  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : v1 new Vector2D with applied rotation
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

inline Vector2D operator*(const double a, const Vector2D& v)
{
	return v * a;
}

inline Vector2D::Vector2D(const double x, const double y) : x(x), y(y) {}

inline const double Vector2D::det(const Vector2D& u) const
{
	return (this->x * u.y) - (u.x * this->y);
}

inline const Vector2D Vector2D::operator + (const Vector2D& u) const 
{
	return Vector2D(x + u.x, y + u.y);
}

inline const Vector2D Vector2D::operator* (const double& a) const 
{
	return Vector2D(x * a, y * a);
}

inline const Vector2D Vector2D::operator/(const double& a) const
{
	try 
	{
		if (a == 0)
			throw Error("Division by 0");
		else
			return Vector2D(x / a, y / a);
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		exit(-1);
	}
}

inline const Vector2D Vector2D::operator - () const
{
	return Vector2D(-x, -y);
}

inline bool Vector2D::operator==(Vector2D& v2) 
{
	return x == v2.x && y == v2.y;
}

inline bool Vector2D::operator!=(Vector2D& v2) 
{
	return !(x == v2.x && y == v2.y);
}

inline const Vector2D operator -(const Vector2D& u, const Vector2D& v) 
{
	return Vector2D(u.x - v.x, u.y - v.y);
}

inline const Vector2D Vector2D::operator*(const Matrix2_2& M) const
{
	vector<vector<double>> matrix = M.getMatrix();
	return Vector2D(matrix[0][0] * x + matrix[0][1] * y, matrix[1][0] * x + matrix[1][1] * y);
	//utiliser produit scalaire
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

	Matrix2_2 matrice(cos(angle), -sin(angle), sin(angle), cos(angle));
	Vector2D r = (*this - center) * matrice + center;
	return r;
}

inline const Vector2D operator* (const Matrix2_2& m, const Vector2D& v) { return v * m; }

inline ostream& operator<<(ostream& flux, const Vector2D& c) 
{
	return c.print(flux);
}

inline ostream& Vector2D::print(ostream& flux) const 
{
	return (flux << "(" << x << "," << y << ")"); // rajouter 3 parametres separateur debut et fin de chaine
}