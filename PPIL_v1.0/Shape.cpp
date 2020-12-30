#include "Shape.h"

int Shape::nbID = 0;

Shape::Shape(string shapeColor, bool state) : _shapeColor(shapeColor), _isGrouped(state), _groupColor(shapeColor) {
	ID = ++nbID;
	gravityCenter = new Vector2D(0, 0);
}

Shape::Shape(const Shape& F) {
	ID = ++nbID;
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

void Shape::setShapeColor(string shapeColor) {
	_shapeColor = shapeColor;
}

const string Shape::getGroupColor() const {
	return _groupColor;
}

void Shape::setGroupColor(string groupColor) {
	_groupColor = groupColor;
}

Vector2D Shape::getGravity() const {
	return *gravityCenter;
}

void Shape::setGravity(double x, double y) {
	gravityCenter->setX(x);
	gravityCenter->setY(y);
}

bool Shape::getIsGrouped() const {
	return _isGrouped;
}

void Shape::setIsGrouped(bool state) {
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

string Shape::serialize() const {
	return nullptr;
}

void Shape::draw(ServerConnection * client) {}

void Shape::translation(double ax, double ay) {}

void Shape::homothety(double ax, double bx, double k) {}

void Shape::rotation(double ax, double ay, double angle) {}

ostream& Shape::print(ostream& flux) const {
	flux << _shapeColor << " ";
	return flux;
}

ostream& operator<<(ostream& flux, const Shape& c) {
	return c.print(flux);
}