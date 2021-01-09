#include "PolygonDetector.h"
#include "ConvexPolygon.h"

PolygonDetector::PolygonDetector(ShapeDetector* next) :ShapeDetector(next) {}

Shape* PolygonDetector::charge1(string D) const
{
	vector<string> data = split(D, ";");
	if (data[indexOf(data, "type") + 1] == "3") {
		Shape* shape;
		int nbPoint = stoi(data[indexOf(data, "nbPoint") + 1]);
		string color = data[indexOf(data, "shapeColor") + 1];
		double x, y;
		vector<Vector2D> listPoints;
		for (int i = 0; i < nbPoint * 2; i += 2) {
			x = stod(data[indexOf(data, "list") + 1 + i]);
			y = stod(data[indexOf(data, "list") + 1 + i + 1]);
			Vector2D* p = new Vector2D(x, y);
			listPoints.push_back(*p);
		}
		shape = new ConvexPolygon(color, listPoints);
		shape->setID(stoi(data[indexOf(data, "ID") + 1]));
		shape->setGroupID(stoi(data[indexOf(data, "groupID") + 1]));
		shape->setGroupColor(data[indexOf(data, "groupColor") + 1]);
		return shape;
	}
	return NULL;
}