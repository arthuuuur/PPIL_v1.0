#include "Group.h"
#include "Error.h"
#include <iostream>

Group::Group(const SpecificColor groupColor, vector<Shape*> F) : Shape(groupColor) {
	try {
		for (vector<Shape*>::const_iterator it = F.begin(); it != F.end(); it++) {
			if ((*it)->getIsGrouped() == true) {
				throw Error("A Shape of this list is already in a Group");
			}
			(*it)->setIsGrouped(true);
			(*it)->setGroupColor(_groupColor);
			(*it)->setGroupID(this->getGroupID());
			listShapes.push_back(*it);
		}
		_shapeColor = intToColor.at(groupColor);
	}
	catch (exception const& err) {
		cerr << err.what() << endl;
		exit(-1);
	}
}

Group::Group(const SpecificColor groupColor) {
	_groupColor = intToColor.at(groupColor);
	_shapeColor = intToColor.at(groupColor);
	groupID = ID;
}

Group::Group(const Group& G) : listShapes(G.listShapes) {}

Group::~Group() {}

void Group::addShape(Shape* F) {
	try {
		if (F->getIsGrouped() == true) {
			throw Error("This Shape is already in a Group");
		}
		F->setIsGrouped(true);
		F->setGroupColor(_groupColor);
		F->setGroupID(this->getID());
		listShapes.push_back(F);
	}
	catch (exception const& err) {
		cerr << err.what() << *F << endl;
		exit(-1);
	}
}

void Group::addGroup(Group *G) {
	for (vector<Shape*>::iterator it = G->listShapes.begin(); it != G->listShapes.end(); it++) {
		(*it)->setGroupColor(_groupColor);
		(*it)->setGroupID(this->getGroupID());
		listShapes.push_back(*it);
	}
}

void Group::removeShape(Shape* S) {
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		if ((*it)->getID() == S->getID()) {
			listShapes.erase(it);
			break;
		}
	}
}

void Group::removeGroup(Group * G) {
	for (vector<Shape*>::iterator it = G->listShapes.begin(); it != G->listShapes.end(); it++) {
		removeShape(*it);
	}
}

const double Group::getArea() const {
	double area = 0;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		area += (**it).getArea();
	}
	return area;
}

vector<Shape*> Group::getList() {
	return listShapes;
}

void Group::translation(const double ax, const double ay) {
	for (vector<Shape*>::iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		(*it)->translation(ax, ay);
	}
}

void Group::homothety(const double ax, const double ay, const double k) {
	for (vector<Shape*>::iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		(*it)->homothety(ax, ay, k);
	}
}

void Group::rotation(const double ax, const double ay, const double angle) {
	for (vector<Shape*>::iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		(*it)->rotation(ax, ay, angle);
	}
}

ostream& Group::print(ostream& flux) const {
	flux << "Group ";
	Shape::print(flux);
	flux << "< ";
	flux << endl;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		(*it)->print(flux);
		flux << endl;
	}
	return flux << ">";
}