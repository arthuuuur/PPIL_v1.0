#include "Circle.h"

Circle::Circle(const Vector2D& v, const double radius) 
{
	_radius = radius;
	_center = v;
	gravity();
}

Circle::Circle(const string shapeColor, const Vector2D& v, const double radius) : Circle(v,radius) 
{
	if (Color::isAllowed(shapeColor)) {
		_shapeColor = shapeColor;
	}
}

const double Circle::getArea() const 
{
	return M_PI * pow(_radius, 2);
}

Vector2D Circle::getCenter() const 
{
	return _center;
}

const double Circle::getRadius() const 
{
	return _radius;
}

void Circle::gravity() 
{
	gravityCenter = _center;
}

const string Circle::serialize() const 
{
	ostringstream os;
	os << "type;2;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << _shapeColor << ";groupColor;" << _colorIfGrouped << ";center;" << _center.getX() << ";" << _center.getY() << ";radius;" << _radius;
	return os.str();
}

Shape* Circle::translation(const Vector2D& v) const
{

	return new Circle(this->getShapeColor(), _center.translation(v), _radius);
}

Shape* Circle::homothety(const double k, const Vector2D& center) const
{
	return new Circle(this->getShapeColor(), _center.homothety(k,center), abs(k) * _radius);
}

Shape* Circle::rotation(const double angle, const Vector2D& center) const
{
	return new Circle(this->getShapeColor(), _center.rotation(angle,center), _radius);
}

ostream& Circle::print(ostream& flux) const 
{
	flux << "Circle ";
	Shape::print(flux);
	return(flux << "< " << _center << ", r = " << _radius << " >");
}