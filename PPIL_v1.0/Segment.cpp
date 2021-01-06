#include "Segment.h"

Segment::Segment(double p1x, double p1y, double p2x, double p2y) {
	_p1 = new Vector2D(p1x, p1y);
	_p2 = new Vector2D(p2x, p2y);
	gravity();
}

Segment::Segment(string shapeColor, double p1x, double p1y, double p2x, double p2y) : Shape(shapeColor) {
	_p1 = new Vector2D(p1x, p1y);
	_p2 = new Vector2D(p2x, p2y);
	gravity();
}

Segment::Segment(const Segment& s) : Shape(s._shapeColor, s._isGrouped) {
	_groupColor = s._groupColor;
	_p1 = new Vector2D(s.getP1().getX(), s.getP1().getY());
	_p2 = new Vector2D(s.getP2().getX(), s.getP2().getY());
	gravity();
}

Segment::~Segment() {
	delete _p1, _p2;
}

Vector2D Segment::getP1() const {
	return *_p1;
}

Vector2D Segment::getP2() const {
	return *_p2;
}

const double Segment::getArea() const {
	return 0.0;
}

const double Segment::lenght() const {
	return sqrt(pow(_p2->getX() - _p1->getX(), 2) + pow(_p2->getY() - _p1->getY(), 2));
}

void Segment::gravity() {
	double ax, ay, bx, by;
	ax = this->getP1().getX();
	ay = this->getP1().getY();
	bx = this->getP2().getX();
	by = this->getP2().getY();
	gravityCenter->setX((ax + bx) / 2);
	gravityCenter->setY((ay + by) / 2);
}

string Segment::serialize() const {
	string color;
	if (_isGrouped) {
		color = _groupColor;
	}
	else {
		color = _shapeColor;
	}
	ostringstream os;
	os << "type;1;ID;" << ID << ";groupID;" << groupID <<";shapeColor;" << color << ";groupColor;" << _groupColor << ";nbPoint;2;list;" << _p1->getX() << ";" << _p1->getY() << ";" << _p2->getX() << ";" << _p2->getY();
	return os.str();
}

void Segment::translation(double ax, double ay) {
	_p1->translation(ax, ay);
	_p2->translation(ax, ay);
}

void Segment::homothety(double ax, double ay, double k) {
	_p1->homothety(ax, ay, k);
	_p2->homothety(ax, ay, k);
}

void Segment::rotation(double ax, double ay, double angle) {
	_p1->rotation(ax, ay, angle);
	_p2->rotation(ax, ay, angle);
}

ostream& Segment::print(ostream& flux) const {
	flux << "Segment ";
	Shape::print(flux);
	return(flux << "[" << *_p1 << "; " << *_p2 << "] ");
}
