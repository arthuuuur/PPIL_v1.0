#include "ConvexPolygon.h"
#include "Triangle.h"
#include "Error.h"
#include "Segment.h"

ConvexPolygon::ConvexPolygon(vector<Vector2D> S) :Polygon(S) {}

ConvexPolygon::ConvexPolygon(const SpecificColor shapeColor, vector<Vector2D> S) : Polygon(S) {
	_shapeColor = intToColor.at(shapeColor);
	_groupColor = intToColor.at(shapeColor);
}

ConvexPolygon::ConvexPolygon() {}

ConvexPolygon::~ConvexPolygon() {}

const double ConvexPolygon::getArea() const {
	unsigned int i;
	int j;
	vector<Segment> listeSegments;
	for (i = 0; i < listPoints.size(); i++) {
		if (i + 1 == listPoints.size()) {
			j = 0;
		}
		else {
			j = i + 1;
		}
		Segment s(listPoints[i].getX(), listPoints[i].getY(), listPoints[j].getX(), listPoints[j].getY());
		listeSegments.push_back(s);
	}
	double area = 0;
	double x, y;
	for (vector<Segment>::const_iterator it = listeSegments.begin(); it != listeSegments.end(); it++) {
		if (it == listeSegments.begin()) { // on cherche les coordonnées du premier coté du polygone
			x = ((*it).getP1().getX() + (*it).getP2().getX()) * 0.5;
			y = ((*it).getP1().getY() + (*it).getP2().getY()) * 0.5;
		}
		else { // ensuite on créer un triangle entre tous les autres cotés et le milieu calculé
			Triangle* t;
			t = new Triangle(x, y, (*it).getP1().getX(), (*it).getP1().getY(), (*it).getP2().getX(), (*it).getP2().getY());
			area += (*t).getArea();
			delete t;
		}
	}
	return area;
}

ostream& ConvexPolygon::print(ostream& flux) const {
	flux << "ConvexPolygon ";
	Shape::print(flux);
	flux << "<";
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		flux << " " << *it << " ";
	}
	return flux << ">";
}