#include "CircleDetector.h"
#include "Circle.h"

CircleDetector::CircleDetector(ShapeDetector* next) : ShapeDetector(next) {}

Shape* CircleDetector::deserialize(const string D) const
{
	vector<string> data = split(D, ";");
	if (data[indexOf(data, "type") + 1] == "2") {
		Shape* shape;
		string color = data[indexOf(data, "shapeColor") + 1];
		double centerx, centery, radius;
		centerx = stod(data[indexOf(data, "center") + 1]);
		centery = stod(data[indexOf(data, "center") + 2]);
		radius = stod(data[indexOf(data, "radius") + 1]);
		shape = new Circle((Shape::SpecificColor)Shape::colorToInt.at(color), centerx, centery, radius);
		shape->setID(stoi(data[indexOf(data, "ID") + 1]));
		shape->setGroupID(stoi(data[indexOf(data, "groupID") + 1]));
		shape->setGroupColor(data[indexOf(data, "groupColor") + 1]);
		return shape;
	}
	return NULL;
}