#include "Triangle.h"


Triangle::Triangle(const Vector2D& v1, const Vector2D& v2, const Vector2D& v3)
{
	listPoints.push_back(v1);
	listPoints.push_back(v2);
	listPoints.push_back(v3);
	gravity();
}

Triangle::Triangle(const string shapeColor, const Vector2D& v1, const Vector2D& v2, const Vector2D& v3) : Triangle(v1,v2,v3)
{
	if (Color::isAllowed(shapeColor)) 
	{
		_shapeColor = shapeColor;
	}
}

Triangle::Triangle(vector<Vector2D> S) : ConvexPolygon(S) {}

Triangle::Triangle(const string shapeColor, vector<Vector2D> S) : ConvexPolygon(S) 
{
	if (Color::isAllowed(shapeColor)) 
	{
		_shapeColor = shapeColor;
	}
}

const double Triangle::getArea() const 
{
	Vector2D ab = listPoints[1] - listPoints[0];
	Vector2D ac = listPoints[2] - listPoints[0];
	double det = 0.5 * abs(ab.det(ac));
	return det;
}
