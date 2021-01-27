#include "SegmentDetector.h"
#include "Segment.h"

SegmentDetector::SegmentDetector(ShapeDetector* next) : ShapeDetector(next) {}

Shape* SegmentDetector::deserialize(const string D) const
{
	vector<string> data = split(D, ";");
	if (data[indexOf(data, "type") + 1] == "1") {
		Shape* shape;
		string color = data[indexOf(data, "shapeColor") + 1];
		int id = stoi(data[indexOf(data, "ID") + 1]);
		double x1, y1, x2, y2;
		x1 = stod(data[indexOf(data, "list") + 1]);
		y1 = stod(data[indexOf(data, "list") + 2]);
		x2 = stod(data[indexOf(data, "list") + 3]);
		y2 = stod(data[indexOf(data, "list") + 4]);
		shape = new Segment(color, x1, y1, x2, y2);
		shape->setID(stoi(data[indexOf(data, "ID") + 1]));
		shape->setGroupID(stoi(data[indexOf(data, "groupID") + 1]));
		shape->setGroupColor(data[indexOf(data, "groupColor") + 1]);
		return shape;
	}
	return NULL;
}