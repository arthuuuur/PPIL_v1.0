#include "Circle.h"

Circle::Circle(const Vector2D& v, const double radius) 
{
	try 
	{
		if (radius <= 0) 
		{
			throw Error("The radius must be postive or not null");
		}
		_radius = radius;
		_center = v;
		gravity();
	}
	catch (exception const& err) 
	{
		cout << err.what() << endl;
		exit(-1);
	}

}

Circle::Circle(const string shapeColor, const Vector2D& v, const double radius) : Circle(v,radius) 
{
	if (Color::isAllowed(shapeColor)) 
	{
		_shapeColor = shapeColor;
	}
}

const double Circle::getArea() const 
{
	return M_PI * _radius * _radius;
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
	os << "type;2;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << _shapeColor 
	   << ";groupColor;" << _colorIfGrouped << ";center;" << _center.x << ";" << _center.y 
	   << ";radius;" << _radius; //appeller le tostring de centre
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

Circle::operator string() const
{
	ostringstream flux; 
	Shape::print(flux);
	flux << "< " << _center << ", r = " << _radius << " >";
	return flux.str();
}