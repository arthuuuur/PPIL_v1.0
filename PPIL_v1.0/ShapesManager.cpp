#include "ShapesManager.h"
#include "SegmentDetector.h"
#include "CircleDetector.h"
#include "PolygonDetector.h"

using namespace std;

ShapesManager::ShapesManager() {
	ShapeDetector* Segment = new SegmentDetector(NULL);
	ShapeDetector* Circle = new CircleDetector(Segment);
	ShapeDetector* Polygon = new PolygonDetector(Circle);
	cor = Polygon;
}

ShapesManager::~ShapesManager() {}



void ShapesManager::addShape(Shape* S) {
	try {
		for (vector<Shape*>::const_iterator it = listShape.begin(); it != listShape.end(); it++) {
			if ((*it)->getID() == S->getID()) {
				throw Error("The shape is already in the ObjectManager");
			}
		}
		listShape.push_back(S);
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		exit(-1);
	}
}

void ShapesManager::addGroup(Shape* G) {
	try {
		for (vector<Shape*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
			if ((*it)->getID() == G->getID()) {
				throw Error("The group is already in the ObjectManager");
			}
		}
		listGroup.push_back(G);
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		exit(-1);
	}
}


void ShapesManager::removeShape(Shape* S) {
	for (vector<Shape*>::const_iterator it = listShape.begin(); it != listShape.end(); it++) {
		if ((*it)->getID() == S->getID()) {
			listShape.erase(it);
			break;
		}
	}
}

void ShapesManager::removeGroup(Shape* G) {
	for (vector<Shape*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
		if ((*it)->getID() == G->getID()) {
			listGroup.erase(it);
			break;
		}
	}
}

void ShapesManager::clean() {
	listShape.clear();
	listGroup.clear();
}

const vector<Shape*>& ShapesManager::getListShape() const {
	return listShape;
}

const vector<Shape*>& ShapesManager::getGroupShape() const{
	return listGroup;
}

ShapeDetectorCOR* ShapesManager::getCOR() const
{
	return cor;
}

void ShapesManager::accepte(ShapeManagerVisitor* S) {
	S->visite(*this);
}

ostream& ShapesManager::print(ostream& flux) const {
	flux << "ShapesManager ";
	flux << "{ ";
	flux << endl << endl;
	for (vector<Shape*>::const_iterator it = listShape.begin(); it != listShape.end(); it++) {
		(*it)->print(flux);
		flux << endl;
	}
	flux << endl;
	for (vector<Shape*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
		(*it)->print(flux);
		flux << endl;
	}
	return flux << endl << "}";
}

ostream& operator<<(ostream& flux, const ShapesManager& c) {
	return c.print(flux);
}