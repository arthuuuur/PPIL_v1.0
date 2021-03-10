#include "ConvexPolygon.h"
#include "Segment.h"
#include "Triangle.h"

ConvexPolygon::ConvexPolygon(vector<Vector2D> S) :Polygon(S) {}

ConvexPolygon::ConvexPolygon(const string shapeColor, vector<Vector2D> S) : Polygon(S) 
{
	if (Color::isAllowed(shapeColor))
	{
		_shapeColor = shapeColor;
		_colorIfGrouped = shapeColor;
	}
}

ConvexPolygon::ConvexPolygon() {}

const double ConvexPolygon::getArea() const 
{
	int i,j;
	vector<Segment> listeSegments;
	for (i = 0; i < listPoints.size(); i++) 
	{
		if (i + 1 == listPoints.size()) 
		{
			j = 0;
		}
		else 
		{
			j = i + 1;
		}
		Vector2D v1(listPoints[i].x, listPoints[i].y);
		Vector2D v2(listPoints[j].x, listPoints[j].y);
		Segment s(v1,v2);
		listeSegments.push_back(s);
	}
	double area = 0;
	Vector2D r;
	for (vector<Segment>::const_iterator it = listeSegments.begin(); it != listeSegments.end(); it++)
	{
		if (it == listeSegments.begin()) // on cherche les coordonnées du premier coté du polygone
		{ 
			r = 0.5 * ((*it).getP1() + (*it).getP2());
		}
		else // ensuite on créer un triangle entre le premier coté et tous les autres cotés du polygone
		{ 
			Vector2D v2((*it).getP1().x, (*it).getP1().y),
					 v3((*it).getP2().x, (*it).getP2().y);
			Triangle* t;
			t = new Triangle(r,v2,v3);
			area += (*t).getArea();
			delete t;
		}
	}
	return area;
}

Shape* ConvexPolygon::translation(const Vector2D& v) const
{
	vector<Vector2D> clonePoints;
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) 
	{
		clonePoints.push_back(it->translation(v)); 
	}
	return new ConvexPolygon(this->getShapeColor(), clonePoints);
}

Shape* ConvexPolygon::homothety(const double k, const Vector2D& center) const
{
	vector<Vector2D> clonePoints;
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) 
	{
		clonePoints.push_back(it->homothety(k,center));
	}
	return new ConvexPolygon(this->getShapeColor(), clonePoints);
}

Shape* ConvexPolygon::rotation(const double angle, const Vector2D& center) const
{
	vector<Vector2D> clonePoints;
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) 
	{
		clonePoints.push_back(it->rotation(angle,center));
	}
	return new ConvexPolygon(this->getShapeColor(), clonePoints);
}
