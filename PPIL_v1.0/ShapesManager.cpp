#include "ShapesManager.h"
#include "SegmentDetector.h"
#include "CircleDetector.h"
#include "PolygonDetector.h"

using namespace std;

ShapesManager::ShapesManager() 
{
	ShapeDetector* Segment = new SegmentDetector(NULL);
	ShapeDetector* Circle = new CircleDetector(Segment);
	ShapeDetector* Polygon = new PolygonDetector(Circle);
	cor = Polygon;
}

ShapesManager::~ShapesManager() {}



void ShapesManager::addShape(Shape* S)
{
	listShape.push_back(S);
}

void ShapesManager::addGroup(Shape* G) 
{
	listGroup.push_back(G);
}


void ShapesManager::removeShape(Shape* S) 
{
	for (vector<Shape*>::const_iterator it = listShape.begin(); it != listShape.end(); it++) {
		if ((*it)->getID() == S->getID()) {
			listShape.erase(it);
			break;
		}
	}
}

void ShapesManager::removeGroup(Shape* G) 
{
	for (vector<Shape*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
		if ((*it)->getID() == G->getID()) {
			listGroup.erase(it);
			break;
		}
	}
}

void ShapesManager::clean() 
{
	listShape.clear();
	listGroup.clear();
}

const vector<Shape*>& ShapesManager::getListShape() const 
{
	return listShape;
}

const vector<Shape*>& ShapesManager::getGroupShape() const
{
	return listGroup;
}

const ShapeDetectorCOR* ShapesManager::getCOR() const
{
	return cor;
}

void ShapesManager::accepte(ShapeManagerVisitor* S) 
{
	S->visite(*this);
}

ShapesManager::operator string() const
{
	ostringstream flux;
	flux << "ShapesManager ";
	flux << "{ ";
	flux << endl << endl;
	for (vector<Shape*>::const_iterator it = listShape.begin(); it != listShape.end(); it++) {
		flux << **it;
		flux << endl;
	}
	flux << endl;
	for (vector<Shape*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
		flux << **it;
		flux << endl;
	}
	flux << endl << "}";
	return flux.str();
}

ostream& operator<<(ostream& flux, const ShapesManager& c) 
{
	return flux << (string)c;
}

