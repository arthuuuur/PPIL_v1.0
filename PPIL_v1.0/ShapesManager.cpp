#include "ShapesManager.h"

ShapesManager::ShapesManager() {}

ShapesManager::~ShapesManager() {}

void ShapesManager::addShape(Shape* S) {
	ObjectManager.push_back(S);
}

void ShapesManager::addGroup(Group G) {
	vector<Shape*> tmp = G.getList();
	for (vector<Shape*>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		ObjectManager.push_back(*it);
	}
}

void ShapesManager::removeShape(Shape *S) {
	for (vector<Shape*>::const_iterator it = ObjectManager.begin(); it != ObjectManager.end(); it++) {
		if ((*it)->getID() == S->getID()) {
			ObjectManager.erase(it);
			break;
		}
	}
}

void ShapesManager::removeGroup(Group G) {
	vector<Shape*> tmp = G.getList();
	for (vector<Shape*>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		this->removeShape(*it);
	}
}

vector<Shape*> ShapesManager::getList() {
	return ObjectManager;
}

void ShapesManager::save() {
}

void ShapesManager::load(string file) {
}

void ShapesManager::accepte(ShapeManagerVisitor *S) {
	S->visite(*this);
}

ostream& ShapesManager::print(ostream& flux) const {
	flux << "ShapesManager ";
	flux << "{ ";
	flux << endl;
	for (vector<Shape*>::const_iterator it = ObjectManager.begin(); it != ObjectManager.end(); it++) {
		(*it)->print(flux);
		flux << endl;
	}
	return flux << "}";
}

ostream& operator<<(ostream& flux, const ShapesManager& c) {
	return c.print(flux);
}
