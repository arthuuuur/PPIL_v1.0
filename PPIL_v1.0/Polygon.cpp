#include "Polygon.h"
#include "Error.h"

Polygon::Polygon() {}

Polygon::Polygon(vector<Vector2D> S) 
{
	for (vector<Vector2D>::iterator it = S.begin(); it != S.end(); it++) {
		listPoints.push_back(*it);
	}
	gravity();
}

Polygon::~Polygon() 
{
	listPoints.clear();
}

void Polygon::gravity() 
{
	Vector2D gravityC;
	double area = 0.0, a;
	int i, j;
	for (i = 0; i < listPoints.size(); i++) {
		if (i + 1 == listPoints.size()) {
			j = 0;
		}
		else {
			j = i + 1;
		}
		Vector2D v1 = listPoints[i];
		Vector2D v2 = listPoints[j];
		a = v1.det(v2);
		area += a;
		gravityC = gravityC + ((v1 + v2) * a);
	}
	gravityC =  gravityC / (3 * area);
	gravityCenter = gravityC;
}

const string Polygon::serialize() const 
{
	ostringstream os;
	os << "type;3;ID;" << ID << ";groupID;" << groupID << ";shapeColor;" << _shapeColor << ";groupColor;" << _colorIfGrouped << ";nbPoint;" << listPoints.size() << ";list;";
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		os << it->x << ";" << it->y;
		if (it != listPoints.end() - 1)
			os << ";";
	}
	return os.str();
}

Polygon::operator string() const
{
	ostringstream flux;
	flux << "Polygon ";
	Shape::print(flux);
	flux << " < ";
	for (vector<Vector2D>::const_iterator it = listPoints.begin(); it != listPoints.end(); it++) {
		flux << " " << *it << " ";
	}
	flux << ">";
	return flux.str();
}


