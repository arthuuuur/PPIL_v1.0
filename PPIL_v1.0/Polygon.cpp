#include "Polygon.h"
#include "Error.h"

Polygon::Polygon() {
}

Polygon::Polygon(vector<Vector2D> S) {
	for (vector<Vector2D>::iterator it = S.begin(); it != S.end(); it++) {
		listPoints.push_back(*it);
	}
	gravity();
}

Polygon::~Polygon() {
	listPoints.clear();
}

void Polygon::gravity() {
	double gx = 0.0;
	double gy = 0.0;
	double x1, y1, x2, y2;
	double area = 0.0;
	double a;
	unsigned int i = 0;
	int j;
	for (i = 0; i < listPoints.size(); i++) {
		if (i + 1 == listPoints.size()) {
			j = 0;
		}
		else {
			j = i + 1;
		}
		x1 = listPoints[i].getX();
		y1 = listPoints[i].getY();
		x2 = listPoints[j].getX();
		y2 = listPoints[j].getY();
		a = (x1 * y2) - (x2 * y1);
		area += a;
		gx += (x1 + x2) * a;
		gy += (y1 + y2) * a;
	}
	gx /= 3 * area;
	gy /= 3 * area;
	gravityCenter->setX(gx);
	gravityCenter->setY(gy);
}

string Polygon::serialize() const {
	string color;
	if (_isGrouped) {
		color = _groupColor;
	}
	else {
		color = _shapeColor;
	}
	ostringstream os;
	os << "type;3;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << color << ";groupColor;" << _groupColor << ";nbPoint;" << listPoints.size() << ";list;";
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		os << it->getX() << ";" << it->getY();
		if (it != listPoints.end() - 1)
			os << ";";
	}
	return os.str();
}

void Polygon::translation(double ax, double ay) {
	for (vector<Vector2D>::iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		it->translation(ax, ay);
	}
}

void Polygon::homothety(double ax, double ay, double k) {
	for (vector<Vector2D>::iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		it->homothety(ax, ay, k);
	}
}

void Polygon::rotation(double ax, double ay, double angle) {
	for (vector<Vector2D>::iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		it->rotation(ax, ay, angle);
	}
}

ostream& Polygon::print(ostream& flux) const {
	flux << "Polygon ";
	Shape::print(flux);
	flux << " < ";
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		flux << " " << *it << " ";
	}
	return flux << ">";
}