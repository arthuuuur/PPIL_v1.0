#include "Triangle.h"
#include "Segment.h"
#include <cmath>

Triangle::Triangle(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3) {
	listPoints.push_back(v1);
	listPoints.push_back(v2);
	listPoints.push_back(v3);
	gravity();
}

Triangle::Triangle(const string shapeColor, const Vector2D& v1, const Vector2D& v2, const Vector2D& v3) : Triangle(v1,v2,v3) {
	if (Color::isAllowed(shapeColor)) {
		_shapeColor = shapeColor;
	}
}

Triangle::Triangle(vector<Vector2D> S) : ConvexPolygon(S) {}

Triangle::Triangle(const string shapeColor, vector<Vector2D> S) : ConvexPolygon(S) {
	if (Color::isAllowed(shapeColor)) {
		_shapeColor = shapeColor;
	}
}

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