#include "ConvexPolygon.h"
#include "Triangle.h"
#include "Error.h"
#include "Segment.h"

ConvexPolygon::ConvexPolygon(vector<Vector2D> S) :Polygon(S) {}

ConvexPolygon::ConvexPolygon(const string shapeColor, vector<Vector2D> S) : Polygon(S) {
	if (Color::isAllowed(shapeColor)) {
		_shapeColor = shapeColor;
		_groupColor = shapeColor;
	}
}

ConvexPolygon::ConvexPolygon() {}

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
		Vector2D v1(listPoints[i].getX(), listPoints[i].getY());
		Vector2D v2(listPoints[j].getX(), listPoints[j].getY());
		Segment s(v1,v2);
		listeSegments.push_back(s);
	}
	double area = 0;
	double x, y;
	for (vector<Segment>::const_iterator it = listeSegments.begin(); it != listeSegments.end(); it++) {
		if (it == listeSegments.begin()) { // on cherche les coordonnées du premier coté du polygone
			x = ((*it).getP1().getX() + (*it).getP2().getX()) * 0.5;
			y = ((*it).getP1().getY() + (*it).getP2().getY()) * 0.5;
		}
		else { // ensuite on créer un triangle entre le premier coté et tous les autres cotés du polygone
			Vector2D v1(x, y),
					 v2((*it).getP1().getX(), (*it).getP1().getY()),
					 v3((*it).getP2().getX(), (*it).getP2().getY());
			Triangle* t;
			t = new Triangle(v1,v2,v3);
			area += (*t).getArea();
			delete t;
		}
	}
	return area;
}
Shape* ConvexPolygon::translation(const Vector2D& v) const
{
	vector<Vector2D> clonePoints;
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		clonePoints.push_back(it->translation(v));
	}
	return new ConvexPolygon(clonePoints);
}

Shape* ConvexPolygon::homothety(const Vector2D& centre, const double k) const
{
	vector<Vector2D> clonePoints;
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		clonePoints.push_back(it->homothety(centre, k));
	}
	return new ConvexPolygon(clonePoints);
}

Shape* ConvexPolygon::rotation(const Vector2D& v, const double angle) const
{
	vector<Vector2D> clonePoints;
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		clonePoints.push_back(it->rotation(v, angle));
	}
	return new ConvexPolygon(clonePoints);
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