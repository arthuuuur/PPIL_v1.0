#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Vector2D {
	
	private:

		/**
		* the abscissa of the point
		*/
		double x;

		/**
		* the ordinate of the point
		*/
		double y; 

	public:

		/**
		* Vector2D 
		* 
		* @param  {double} x : abscissa of the center
		* @param  {double} y : ordinate of the center
		*/
			Vector2D(double x, double y);

		/**
		* ~Vector2D 
		*/
			~Vector2D();

		/** 
		* @param  {Vector2D} u : the vector to add
		* @return {Vector2D}   : the vector resulting from the addition
		*/
			inline const Vector2D operator + (const Vector2D& u) const;

		/** 
		* @param  {double} a   : the constante that multiplie the vector
		* @return {Vector2D*}  : the vector resulting from the multiplication
		*/
			inline const Vector2D operator* (const double& a) const;

		/**
		* @return {Vector2D}  : the inverse of the vector
		*/
			inline const Vector2D operator - () const;

		/** 
		* @param  {Vector2D} v2 : the vector with which the equality is tested
		* @return {bool}        : return true if they are egal else return false
		*/
			bool operator==(Vector2D& v2);

		/**
		* @param  {Vector2D} v2 : the vector with which the non equality is tested
		* @return {bool}        : return true if they are not egal else return false
		*/
			bool operator!=(Vector2D& v2);

		/** 
		* @return {double}  : the abscissa of the point
		*/
			inline const double getX() const;

		/** 
		* @return {double}  : the ordinate of the point
		*/
			inline const double getY() const;

		/**
		* @param  {double} a : the new abscissa
		*/
			const void setX(double a);

		/**
		* @param  {double} a : the new ordinate
		*/
			const void setY(double a);

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
		* @param  {ostream}    : 
		* @param  {Vector2D} c : 
		* @return {ostream}    : 
		*/
			friend ostream& operator<<(ostream&, const Vector2D& c);

		/**
		* @param  {ostream} flux : the output stream
		* @return {ostream}      : return the output stream with the print of the point
		*/
			ostream& print(ostream& flux) const;
};

inline const Vector2D Vector2D::operator + (const Vector2D& u) const {
	return Vector2D(x + u.x, y + u.y);
}

inline const Vector2D operator*(const double& a, const Vector2D& u) { // quelle est la difference entre la redefinition de cet operateur la et l'autre operateur* ?
	return u* a;
}

inline const Vector2D Vector2D::operator* (const double& a) const { // quelle est la difference entre la redefinition de cet operateur la et l'autre operateur* ?
	return Vector2D(x* a, y* a);
}

inline const Vector2D Vector2D::operator - () const {
	return Vector2D(-x, -y);
}

inline bool Vector2D::operator==(Vector2D& v2) {
	return x == v2.getX() && y == v2.getY();
}

inline bool Vector2D::operator!=(Vector2D& v2) {
	return !(x == v2.getX() && y == v2.getY());
}

inline const Vector2D operator -(const Vector2D& u, const Vector2D& v) {
	return Vector2D(u.getX() - v.getX(), u.getY() - v.getY());
}

inline const double Vector2D::getX() const {
	return x;
}

inline const double Vector2D::getY() const {
	return y;
}