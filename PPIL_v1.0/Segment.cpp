#include "Segment.h"

Segment::Segment(const Vector2D& p1, const Vector2D& p2) {
	_p1 = p1;
	_p2 = p2;
	gravity();
}

Segment::Segment(const string shapeColor, const Vector2D& p1, const Vector2D& p2) : Segment(p1,p2){
	if (Color::isAllowed(shapeColor)) {
		_shapeColor = shapeColor;
	}
}

Vector2D Segment::getP1() const {
	return _p1;
}

Vector2D Segment::getP2() const {
	return _p2;
}

const double Segment::getArea() const {
	return 0.0;
}

void Segment::gravity() {
	gravityCenter = 0.5 * (_p1 + _p2);
}

string Segment::serialize() const {
	ostringstream os;
	os << "type;1;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << _shapeColor << ";groupColor;" << _groupColor << ";nbPoint;2;list;" << _p1.getX() << ";" << _p1.getY() << ";" << _p2.getX() << ";" << _p2.getY();
	return os.str();
}

Shape* Segment::translation(const Vector2D& v) const {
	return new Segment(this->getShapeColor(), _p1.translation(v), _p2.translation(v));
}

Shape* Segment::homothety(const Vector2D& centre, const double k) const {
	return new Segment(this->getShapeColor(), _p1.homothety(centre, k), _p2.homothety(centre, k));
}

Shape* Segment::rotation(const Vector2D& v, const double angle) const {
	return new Segment(_p1.rotation(v, angle), _p2.rotation(v, angle));
}

ostream& Segment::print(ostream& flux) const {
	flux << "Segment ";
	Shape::print(flux);
	return(flux << "[" << _p1 << "; " << _p2 << "] ");
}