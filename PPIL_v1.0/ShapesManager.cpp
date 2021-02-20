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

void ShapesManager::addGroup(Group* G) {
	try {
		for (vector<Group*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
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

void ShapesManager::removeGroup(Group* G) {
	for (vector<Group*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
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

vector<Shape*> ShapesManager::getListShape() {
	return listShape;
}

vector<Group*> ShapesManager::getGroupShape() {
	return listGroup;
}

void ShapesManager::save(const string saveName) {
	try {
		ofstream save(saveName.c_str());
		if (!save) throw Error("failed to create a save file");
		for (vector<Shape*>::const_iterator it = listShape.begin(); it != listShape.end(); it++) {
			save << (*it)->serialize();
			if (it != listShape.end() - 1)
				save << "\n";
		}
		if (!listShape.empty()) save << "\n";
		for (vector<Group*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
			vector<Shape*> tmp = (*it)->getList();
			for (vector<Shape*>::const_iterator itbis = tmp.begin(); itbis != tmp.end(); itbis++) {
				save << (*itbis)->serialize();
				if (itbis != tmp.end() - 1)
					save << "\n";
			}
		}
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		exit(-1);
	}
}

void ShapesManager::load(const string file) {
	try {
		ifstream save(file);
		if (!save) throw Error("failed to open file");
		string line;
		while (getline(save, line)) {
			Shape* var = cor->charge(line);
			if (var != NULL) {
				if (var->getGroupID() > -1) { // si une forme appartient à un group
					bool here = false;
					for (vector<Group*>::iterator it = listGroup.begin(); it != listGroup.end(); it++) { // on regarde si le group est deja la
						if ((*it)->getID() == var->getGroupID()) {
							here = true;
							if (here) {
								(*it)->addShape(var);
							}
						}
					}
					if (!here) {
						Group* G = new Group(var->getGroupColor());
						G->setGroupID(var->getGroupID());
						G->setID(var->getGroupID());
						G->addShape(var);
						listGroup.push_back(G);
						here = false;
					}
				}
				else {
					this->addShape(var);
				}
			}
			else {
				throw Error("the file contains an unknown shape");
			}
		}
	}
	catch (exception const& err) {
		cout << err.what() << endl;
		exit(-1);
	}
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
	for (vector<Group*>::const_iterator it = listGroup.begin(); it != listGroup.end(); it++) {
		(*it)->print(flux);
		flux << endl;
	}
	return flux << endl << "}";
}

ostream& operator<<(ostream& flux, const ShapesManager& c) {
	return c.print(flux);
}