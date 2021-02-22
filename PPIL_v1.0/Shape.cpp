#include "Shape.h"
#include "Error.h"



int Shape::nbShape = 0;

Shape::Shape(const string shapeColor, const bool state) : _isGrouped(state) {
		if (Color::isAllowed(shapeColor)){
			_shapeColor = shapeColor;
			_groupColor = shapeColor;
		}
		ID = ++nbShape;
		groupID = -1;
}

Shape::~Shape() {
	nbShape--;
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

const int Shape::getNbShape() const {
	return nbShape;
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