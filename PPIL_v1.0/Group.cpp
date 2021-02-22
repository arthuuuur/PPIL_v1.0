#include "Group.h"
#include "Error.h"
#include <iostream>

Group::Group(const string groupColor, vector<Shape*> F) : Shape(groupColor) {
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
		if (Color::isAllowed(groupColor)) {
			_shapeColor = groupColor;
		}
	}
	catch (exception const& err) {
		cerr << err.what() << endl;
		exit(-1);
	}
}

Group::Group(const string groupColor) {
	if (Color::isAllowed(groupColor)) {
		_shapeColor = groupColor;
		_groupColor = groupColor;
	}
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

Shape* Group::translation(const Vector2D& v) const{
	vector<Shape*> cloneShape;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		cloneShape.push_back((*it)->translation(v));
	}
	return new Group(this->getGroupColor(),cloneShape);
}

Shape* Group::homothety(const Vector2D& center, const double k) const {
	vector<Shape*> cloneShape;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		cloneShape.push_back((*it)->homothety(center,k));
	}
	return new Group(this->getGroupColor(), cloneShape);
}

Shape* Group::rotation(const Vector2D& center, const double angle) const{
	vector<Shape*> cloneShape;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		cloneShape.push_back((*it)->rotation(center, angle));
	}
	return new Group(this->getGroupColor(), cloneShape);
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

string Group::serialize() const
{
	return nullptr;
}