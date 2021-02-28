#include "Group.h"
#include "Error.h"
#include <iostream>

Group::Group(const string groupColor, vector<Shape*> L) : Shape(groupColor) 
{
	father = NULL;
	for (vector<Shape*>::const_iterator it = L.begin(); it != L.end(); it++) {	
		(*it)->setColorIfGrouped(groupColor);
		(*it)->setGroupID(this->getID());
		(*it)->setFather(this);
		listShapes.push_back(*it);
	}
}

Group::Group(const string groupColor) : Shape(groupColor) {}

Group::Group(const Group& G) : listShapes(G.listShapes) {}

Group::~Group() {}


void Group::addShape(Shape* S) 
{
	S->setFather(this);
	S->setColorIfGrouped(this->getFatherColor());
	S->setGroupID(this->getFatherID());
	listShapes.push_back(S);
}

void Group::addGroup(Shape *G) 
{
	G->setGroupID(this->getFatherID());
	G->setFather(this);
	G->setColorIfGrouped(this->getShapeColor());
	for (vector<Shape*>::iterator it = dynamic_cast<Group*>(G)->listShapes.begin(); it != dynamic_cast<Group*>(G)->listShapes.end(); it++) {
		(*it)->setColorIfGrouped(this->getFatherColor());
		(*it)->setGroupID(this->getFatherID());
	}
	listShapes.push_back(G);
}

void Group::removeShape(Shape* S) 
{
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		if ((*it)->getID() == S->getID()) {
			listShapes.erase(it);
			break;
		}
	}
	S->setFather(NULL);
	S->setColorIfGrouped(S->getShapeColor());
	S->setGroupID(S->getID());
}

void Group::removeGroup(Shape * G) 
{
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		if ((*it)->getID() == G->getID()) {
			listShapes.erase(it);
			break;
		}
	}
	for (vector<Shape*>::iterator it = dynamic_cast<Group*>(G)->listShapes.begin(); it != dynamic_cast<Group*>(G)->listShapes.end(); it++) {
		(*it)->setColorIfGrouped(G->getShapeColor());
		(*it)->setGroupID(G->getID());
	}
	G->setGroupID(G->getID());
	G->setFather(NULL);
	G->setColorIfGrouped(G->getShapeColor());
}

const double Group::getArea() const 
{
	double area = 0;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		area += (**it).getArea();
	}
	return area;
}

vector<Shape*> Group::getList() 
{
	return listShapes;
}

void Group::setColorIfGrouped(const string ColorIfGrouped)
{
	if (Color::isAllowed(ColorIfGrouped)) {
		_colorIfGrouped = ColorIfGrouped;
	}
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		(*it)->setColorIfGrouped(ColorIfGrouped);
	}
}

void Group::setGroupID(const int GID)
{
	groupID = GID;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		(*it)->setGroupID(GID);
	}
}

void Group::setShapeColor(const string shapeColor)
{
	if (Color::isAllowed(shapeColor)) {
		_shapeColor = shapeColor;
	}
	if (this->getFather() == NULL) // si le groupe n'est pas dans un groupe
	{ // on donne a chaque forme du groupe le nouveau groupColor correspondant a la nouvelle couleur du groupe
		for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
			(*it)->setColorIfGrouped(shapeColor);
		}
	}
}


Shape* Group::translation(const Vector2D& v) const
{
	vector<Shape*> cloneShape;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		cloneShape.push_back((*it)->translation(v));
	}
	return new Group(this->getColorIfGrouped(),cloneShape);
}

Shape* Group::homothety(const Vector2D& center, const double k) const 
{
	vector<Shape*> cloneShape;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		cloneShape.push_back((*it)->homothety(center,k));
	}
	return new Group(this->getColorIfGrouped(), cloneShape);
}

Shape* Group::rotation(const Vector2D& center, const double angle) const
{
	vector<Shape*> cloneShape;
	for (vector<Shape*>::const_iterator it = listShapes.begin(); it != listShapes.end(); it++) {
		cloneShape.push_back((*it)->rotation(center, angle));
	}
	return new Group(this->getColorIfGrouped(), cloneShape);
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

const string Group::serialize() const
{
	return nullptr;
}