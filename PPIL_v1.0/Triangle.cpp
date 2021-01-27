#include "Triangle.h"
#include "Segment.h"
#include <cmath>

Triangle::Triangle(const double ax, const double ay, const double bx, const double by, const double cx, const double cy) {
	Vector2D v1(ax, ay);
	Vector2D v2(bx, by);
	Vector2D v3(cx, cy);
	listPoints.push_back(v1);
	listPoints.push_back(v2);
	listPoints.push_back(v3);
	gravity();
}

Triangle::Triangle(const string shapeColor, const double ax, const double ay, const double bx, const double by, const double cx, const double cy) {
	_shapeColor = shapeColor;
	Vector2D v1(ax, ay);
	Vector2D v2(bx, by);
	Vector2D v3(cx, cy);
	listPoints.push_back(v1);
	listPoints.push_back(v2);
	listPoints.push_back(v3);
	gravity();
}

Triangle::Triangle(vector<Vector2D> S) : ConvexPolygon(S) {}

Triangle::Triangle(const string shapeColor, vector<Vector2D> S) : ConvexPolygon(S) {
	_shapeColor = shapeColor;
}

Triangle::~Triangle() {}

const double Triangle::getArea() const {
	double ax, ay, bx, by, cx, cy;
	ax = listPoints[0].getX();
	ay = listPoints[0].getY();
	bx = listPoints[1].getX();
	by = listPoints[1].getY();
	cx = listPoints[2].getX();
	cy = listPoints[2].getY();
	return 0.5 * abs((bx - ax) * (cy - ay) - (cx - ax) * (by - ay));
}

ostream& Triangle::print(ostream& flux) const {
	flux << "Triangle ";
	Shape::print(flux);
	flux << "<";
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		flux << " " << *it << " ";
	}
	flux << ">";
	return flux;
}