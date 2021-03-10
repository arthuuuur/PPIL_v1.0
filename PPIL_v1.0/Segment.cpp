#include "Segment.h"

Segment::Segment(const Vector2D& p1, const Vector2D& p2)
{
	_p1 = p1;
	_p2 = p2;
	gravity();
}

Segment::Segment(const string shapeColor, const Vector2D& p1, const Vector2D& p2) : Segment(p1,p2)
{
	if (Color::isAllowed(shapeColor)) 
	{
		_shapeColor = shapeColor;
	}
}

Vector2D Segment::getP1() const 
{
	return _p1;
}

Vector2D Segment::getP2() const 
{
	return _p2;
}

const double Segment::getArea() const 
{
	return 0.0;
}

void Segment::gravity() 
{
	gravityCenter = 0.5 * (_p1 + _p2);
}

const string Segment::serialize() const 
{
	ostringstream os;
	os << "type;1;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << _shapeColor << ";groupColor;" << _colorIfGrouped << ";nbPoint;2;list;" << _p1.x << ";" << _p1.y << ";" << _p2.x << ";" << _p2.y;
	return os.str();
}

Shape* Segment::translation(const Vector2D& v) const 
{
	return new Segment(this->getShapeColor(), _p1.translation(v), _p2.translation(v));
}

Shape* Segment::homothety(const double k, const Vector2D& center) const
{
	return new Segment(this->getShapeColor(), _p1.homothety(k,center), _p2.homothety(k,center));
}

Shape* Segment::rotation(const double angle, const Vector2D& center) const
{
	return new Segment(this->getShapeColor(), _p1.rotation(angle,center), _p2.rotation(angle,center));
}

Segment::operator string() const
{
	ostringstream flux;
	flux << "Segment ";
	Shape::print(flux);
	flux << "[" << _p1 << "; " << _p2 << "] ";
	return flux.str();
}
