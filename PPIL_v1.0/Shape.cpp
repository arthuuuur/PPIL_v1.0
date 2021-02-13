#include "Shape.h"
#include "Error.h"

const unordered_map<int, string> Shape::intToColor = { {0,"red"}, {1,"blue"}, {2,"green"}, {3,"black"}, {4,"yellow"}, {5,"cyan"} };
const unordered_map<string, int> Shape::colorToInt = { {"red",0}, {"blue",1}, {"green",2}, {"black",3}, {"yellow",4}, {"cyan",5} };

int Shape::nbID = 0;

Shape::Shape(const SpecificColor shapeColor, const bool state) : _isGrouped(state) {
	_shapeColor = intToColor.at(shapeColor);
	_groupColor = intToColor.at(shapeColor);
	ID = ++nbID;
	groupID = -1;
	gravityCenter = new Vector2D(0, 0);
}

Shape::Shape(const Shape& F) {
	ID = ++nbID;
	groupID = F.groupID;
	_shapeColor = F._shapeColor;
	_groupColor = F._groupColor;
	_isGrouped = F._isGrouped;
	gravityCenter = new Vector2D(F.getGravity().getX(), F.getGravity().getY());
}

Shape::~Shape() {
	nbID--;
	delete gravityCenter;
}

const string Shape::getShapeColor() const {
	return _shapeColor;
}

void Shape::setShapeColor(const string shapeColor) {
	_shapeColor = shapeColor;
}

const string Shape::getGroupColor() const {
	return _groupColor;
}

void Shape::setGroupColor(const string groupColor) {
	_groupColor = groupColor;
}

Vector2D Shape::getGravity() const {
	return *gravityCenter;
}

void Shape::setGravity(const double x, const double y) {
	gravityCenter->setX(x);
	gravityCenter->setY(y);
}

bool Shape::getIsGrouped() const {
	return _isGrouped;
}

void Shape::setIsGrouped(const bool state) {
	_isGrouped = state;
}

const double Shape::getArea() const {
	return 0.0;
}

void Shape::gravity() {}

const int Shape::getNbID() const {
	return nbID;
}

const int Shape::getID() const {
	return ID;
}

const int Shape::getGroupID() const {
	return groupID;
}

string Shape::serialize() const {
	return nullptr;
}

void Shape::setGroupID(const int GID) {
	groupID = GID;
}

void Shape::setID(const int id) {
	ID = id;
}

void Shape::translation(const double ax, const double ay) {}

void Shape::homothety(const double ax, const double bx, const double k) {}

void Shape::rotation(const double ax, const double ay, const double angle) {}

ostream& Shape::print(ostream& flux) const {
	flux << _shapeColor << " | id = " << ID << " | groupID = " << groupID << " | ";
	return flux;
}

ostream& operator<<(ostream& flux, const Shape& c) {
	return c.print(flux);
}