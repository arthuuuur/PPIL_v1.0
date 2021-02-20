#include "Shape.h"
#include "Error.h"



int Shape::nbID = 0;

Shape::Shape(const string shapeColor, const bool state) : _isGrouped(state) {
		if (Color::isAllowed(shapeColor)){
			_shapeColor = shapeColor;
			_groupColor = shapeColor;
		}
		ID = ++nbID;
		groupID = -1;
}

Shape::Shape(const Shape& F) {
	ID = ++nbID;
	groupID = F.groupID;
	_shapeColor = F._shapeColor;
	_groupColor = F._groupColor;
	_isGrouped = F._isGrouped;
	gravityCenter = F.getGravity();
}

Shape::~Shape() {
	nbID--;
}

const string Shape::getShapeColor() const {
	return _shapeColor;
}

void Shape::setShapeColor(const string shapeColor) {
	if (Color::isAllowed(shapeColor)) {
		_shapeColor = shapeColor;
	}
}

const string Shape::getGroupColor() const {
	return _groupColor;
}

void Shape::setGroupColor(const string groupColor) {

	if (Color::isAllowed(groupColor)) {
		_groupColor = groupColor;
	}		
}

Vector2D Shape::getGravity() const {
	return gravityCenter;
}

bool Shape::getIsGrouped() const {
	return _isGrouped;
}

void Shape::setIsGrouped(const bool state) {
	_isGrouped = state;
}

void Shape::gravity() {}

string Shape::serialize() const
{
	return nullptr;
}

const int Shape::getNbID() const {
	return nbID;
}

const int Shape::getID() const {
	return ID;
}

const int Shape::getGroupID() const {
	return groupID;
}

void Shape::setGroupID(const int GID) {
	groupID = GID;
}

void Shape::setID(const int id) {
	ID = id;
}

ostream& Shape::print(ostream& flux) const {
	flux << _shapeColor << " | id = " << ID << " | groupID = " << groupID << " | ";
	return flux;
}

ostream& operator<<(ostream& flux, const Shape& c) {
	return c.print(flux);
}