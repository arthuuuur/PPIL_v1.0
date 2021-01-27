#include "Circle.h"

Circle::Circle(const double x, const double y, const double radius) {
	_radius = radius;
	_center = new Vector2D(x, y);
	gravity();
}

Circle::Circle(const string shapeColor, const double x, const double y, const double radius) : Shape(shapeColor) {
	_radius = radius;
	_center = new Vector2D(x, y);
	gravity();
}

Circle::Circle(const Circle& c) : Shape(c._shapeColor) {
	_radius = c._radius;
	_center = new Vector2D(c.getCenter().getX(), c.getCenter().getY());
	gravity();
}

Circle::~Circle() {
	delete _center;
}

const double Circle::getArea() const {
	return M_PI * pow(_radius, 2);
}

Vector2D Circle::getCenter() const {
	return *_center;
}

const double Circle::getRadius() const {
	return _radius;
}

void Circle::gravity() {
	gravityCenter->setX(_center->getX());
	gravityCenter->setY(_center->getY());
}

string Circle::serialize() const {
	ostringstream os;
	os << "type;2;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << _shapeColor << ";groupColor;" << _groupColor << ";center;" << _center->getX() << ";" << _center->getY() << ";radius;" << _radius;
	return os.str();
}

void Circle::translation(const double ax, const double ay) {
	_center->translation(ax, ay);
}

void Circle::homothety(const double ax, const double ay, const double k) {
	_center->homothety(ax, ay, k);
	_radius = abs(k) * k;
}

void Circle::rotation(const double ax, const double ay, const double angle) {
	_center->rotation(ax, ay, angle);
}

ostream& Circle::print(ostream& flux) const {
	flux << "Circle ";
	Shape::print(flux);
	return(flux << "< " << *_center << ", r = " << _radius << " >");
}