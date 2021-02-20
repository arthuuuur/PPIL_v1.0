#include "Polygon.h"
#include "Error.h"

Polygon::Polygon() {}

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
	double gx = 0.0, gy = 0.0, area = 0.0, a, x1, y1, x2, y2;
	int i = 0, j;
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
	gravityCenter.setX(gx);
	gravityCenter.setY(gy);
}

string Polygon::serialize() const {
	ostringstream os;
	os << "type;3;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << _shapeColor << ";groupColor;" << _groupColor << ";nbPoint;" << listPoints.size() << ";list;";
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		os << it->getX() << ";" << it->getY();
		if (it != listPoints.end() - 1)
			os << ";";
	}
	return os.str();
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