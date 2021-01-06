#include "Circle.h"

Circle::Circle(double x, double y, double radius) {
	_radius = radius;
	center = new Vector2D(x, y);
	gravity();
}

Circle::Circle(string shapeColor, double x, double y, double radius) : Shape(shapeColor) {
	_radius = radius;
	center = new Vector2D(x, y);
	gravity();
}

Circle::Circle(const Circle& c) : Shape(c._shapeColor) {
	_radius = c._radius;
	center = new Vector2D(c.getCenter().getX(), c.getCenter().getY());
	gravity();
}

Circle::~Circle() {
	delete center;
}

const double Circle::getArea() const {
	return M_PI * pow(_radius, 2);
}

Vector2D Circle::getCenter() const
{
	return *center;
}

const double Circle::getRadius() const
{
	return _radius;
}

void Circle::gravity() {
	gravityCenter->setX(center->getX());
	gravityCenter->setY(center->getY());
}

string Circle::serialize() const {
	string color;
	if (_isGrouped) {
		color = _groupColor;
	}
	else {
		color = _shapeColor;
	}
	ostringstream os;
	os << "type;2;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << color << ";groupColor;" << _groupColor << ";center;" << center->getX() << ";" << center->getY() << ";radius;" << _radius;
	return os.str();
}

void Circle::translation(double ax, double ay) {
	center->translation(ax, ay);
}

void Circle::homothety(double ax, double ay, double k) {
	center->homothety(ax, ay, k);
	_radius = abs(k) * k;
}

void Circle::rotation(double ax, double ay, double angle) {
	center->rotation(ax, ay, angle);
}

ostream& Circle::print(ostream& flux) const {
	flux << "Circle ";
	Shape::print(flux);
	return(flux << "< " << *center << ", r = " << _radius << " >");
}
