#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Vector2D {

private:

	/**
	* The abscissa of the point
	*/
	double x;

	/**
	* The ordinate of the point
	*/
	double y;

public:

	/**
	* Vector2D
	*
	* @param  {double} x : Abscissa of the center
	* @param  {double} y : Ordinate of the center
	*/
	Vector2D(double x, double y);

	/**
	* ~Vector2D
	*/
	~Vector2D();

	/**
	* @param  {Vector2D} u : The vector to add
	* @return {Vector2D}   : The vector resulting from the addition
	*/
	const Vector2D operator + (const Vector2D& u) const;

	/**
	* @param  {double} a   : The constante that multiplie the vector
	* @return {Vector2D*}  : The vector resulting from the multiplication
	*/
	const Vector2D operator* (const double& a) const;

	/**
	* @return {Vector2D}  : The inverse of the vector
	*/
	const Vector2D operator - () const;

	/**
	* @param  {Vector2D} v2 : The vector with which the equality is tested
	* @return {bool}        : Return true if they are egal else return false
	*/
	bool operator==(Vector2D& v2);

	/**
	* @param  {Vector2D} v2 : The vector with which the non equality is tested
	* @return {bool}        : Return true if they are not egal else return false
	*/
	bool operator!=(Vector2D& v2);

	/**
	* Getter of x
	* 
	* @return {double}  : The abscissa of the point
	*/
	const double getX() const;

	/**
	* Getter of y
	* 
	* @return {double}  : The ordinate of the point
	*/
	const double getY() const;

	/**
	* Setter of x
	* 
	* @param  {double} a : The new abscissa
	*/
	const void setX(double a);

	/**
	* Setter of y
	* 
	* @param  {double} a : the new ordinate
	*/
	const void setY(double a);

	/**
	* Allows to make a translation using a translation vector
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	*/
	void translation(double ax, double ay);

	/**
	* Allows to make a translation using an invariant point and a homothety ratio
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	* @param  {double} k  : The homothety ratio
	*/
	void homothety(double ax, double ay, double k);

	/**
	* Allows to make a rotation using an invariant point and a rotation angle
	*
	* @param  {double} ax    : The abscisse of the translation vector
	* @param  {double} ay    : The ordinate of the translation vector
	* @param  {double} angle : The angle of the rotation in degrees
	*/
	void rotation(double ax, double ay, double angle);

	/**
	* @param  {ostream}    :
	* @param  {Vector2D} c :
	* @return {ostream}    :
	*/
	friend ostream& operator<<(ostream&, const Vector2D& c);

	/**
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the point
	*/
	ostream& print(ostream& flux) const;
};

