#include "Vector2D.h"
#define _USE_MATH_DEFINES // to get the constante M_PI with the <math.h> include
#include <math.h>

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D::~Vector2D() {}

const void Vector2D::setX(double a) {
	x = a;
}
const void Vector2D::setY(double a) {
	y = a;
}

void Vector2D::translation(double ax, double ay) {
	x += ax;
	y += ay;
}

void Vector2D::homothety(double ax, double ay, double k) {
	x = (x - ax) * k + ax;
	y = (y - ay) * k + ay;
}

void Vector2D::rotation(double ax, double ay, double angle) {
	angle *= M_PI / 180.0;
	double f = x - ax;
	double g = y - ay;
	double xf, yf;
	xf = f * cos(angle) + g * sin(angle) + ax;
	yf = -f * sin(angle) + g * cos(angle) + ay;
	x = round(xf);
	y = round(yf);
}

ostream& operator<<(ostream& flux, const Vector2D& c) {
	return c.print(flux);
}

ostream& Vector2D::print(ostream& flux) const {
	return (flux << "(" << x << "," << y << ")");
}