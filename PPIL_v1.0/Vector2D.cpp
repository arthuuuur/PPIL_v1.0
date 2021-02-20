#include "Vector2D.h"
#define _USE_MATH_DEFINES // to get the constante M_PI with the <math.h> include
#include <math.h>

Vector2D::Vector2D(const double x, const double y) : x(x), y(y) {}

Vector2D::~Vector2D() {}

const Vector2D Vector2D::operator + (const Vector2D& u) const {
	return Vector2D(x + u.x, y + u.y);
}

const Vector2D Vector2D::operator* (const double& a) const { 
	return Vector2D(x * a, y * a);
}

const Vector2D Vector2D::operator - () const {
	return Vector2D(-x, -y);
}

bool Vector2D::operator==(Vector2D& v2) {
	return x == v2.getX() && y == v2.getY();
}

bool Vector2D::operator!=(Vector2D& v2) {
	return !(x == v2.getX() && y == v2.getY());
}

const Vector2D operator -(const Vector2D& u, const Vector2D& v) {
	return Vector2D(u.getX() - v.getX(), u.getY() - v.getY());
}

const double Vector2D::getX() const {
	return x;
}

const double Vector2D::getY() const {
	return y;
}

const void Vector2D::setX(const double a) {
	x = a;
}
const void Vector2D::setY(const double a) {
	y = a;
}

Vector2D Vector2D::translation(const Vector2D& v) const {
	Vector2D r = *this + v;
	return r;
}

Vector2D Vector2D::homothety(const Vector2D& v, const double k) const {
	Vector2D r;
	return r = k * (*this - v) + v;
}

Vector2D Vector2D::rotation(const Vector2D& v,const double angle) const { // faire avec la classe matrice comme vu avec le prof
	/*double f = x - ax;
	double g = y - ay;
	double xf, yf;
	xf = f * cos(angle) + g * sin(angle) + ax;
	yf = -f * sin(angle) + g * cos(angle) + ay;
	x = round(xf);
	y = round(yf); // pourquoi on arrondit ? */
	return NULL;
}

ostream& operator<<(ostream& flux, const Vector2D& c) {
	return c.print(flux);
}

ostream& Vector2D::print(ostream& flux) const {
	return (flux << "(" << x << "," << y << ")");
}