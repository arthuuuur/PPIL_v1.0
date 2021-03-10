#include "Shape.h"

int Shape::nbShape = 0;

Shape::Shape(const string shapeColor) 
{
		if (Color::isAllowed(shapeColor))
		{
			_shapeColor = shapeColor;
			_colorIfGrouped = shapeColor;
		}
		ID = ++nbShape;
		father = NULL;
		groupID = ID;
		
}

Shape::Shape(const Shape& S) 
{
	_shapeColor = S.getShapeColor();
	_colorIfGrouped = S.getColorIfGrouped();
	father = S.getFather();
	ID = ++nbShape;
	groupID = ID;
}

Shape::~Shape() 
{
	nbShape--;
	free(father);
}


Shape* Shape::getFather() const
{
	return father;
}

void Shape::setFather(Shape* S)
{
	father = S;
}

const int Shape::getFatherID()
{
	Shape* iterator;
	iterator = this;
	while (iterator->getFather() != NULL)// si elle est groupé on remonte le pere jusqu'a trouver la racine pour determiner le groupID
	{
		iterator = iterator->getFather();
	}
	if (iterator != NULL)
		return iterator->getID(); // si la forme a un pere on retourne l'id de la racine 
	else
		return ID; // sinon on retourne l'id de la forme
}

const string Shape::getFatherColor()
{
	Shape* iterator;
	iterator = this;
	while (iterator->getFather() != NULL)// si elle est groupé on remonte le pere jusqu'a trouver la racine 
	{
		iterator = iterator->getFather();
	}
	if (iterator != NULL)
	{
		return iterator->getShapeColor(); // si la forme a un pere on retourne la couleur du pere
	}
	else
		return _shapeColor; // sinon on retourne la couleur de la forme
}

const string Shape::getShapeColor() const 
{
	return _shapeColor;
}

void Shape::setShapeColor(const string shapeColor) 
{
	if (Color::isAllowed(shapeColor)) 
	{
		_shapeColor = shapeColor;
	}
}

const string Shape::getColorIfGrouped() const 
{
	return _colorIfGrouped;
}

void Shape::setColorIfGrouped(const string groupColor) 
{

	if (Color::isAllowed(groupColor)) 
	{
		_colorIfGrouped = groupColor;
	}		
}

Vector2D Shape::getGravity() const 
{
	return gravityCenter;
}


void Shape::gravity() {}

const string Shape::serialize() const
{
	return nullptr;
}

const int Shape::getNbShape() const 
{
	return nbShape;
}

const int Shape::getID() const
{
	return ID;
}

const int Shape::getGroupID() const
{
	return groupID;
}

void Shape::setGroupID(const int GID) 
{
	groupID = GID;
}

void Shape::setID(const int id) 
{
	ID = id;
}

ostream& Shape::print(ostream& flux) const 
{
	return flux << _shapeColor << " | id = " << ID << " | groupID = " << groupID << " | ";
}

Shape::operator string() const
{
	ostringstream flux;
	print(flux);
	return flux.str();
}

ostream& operator<<(ostream& flux, const Shape& c)
{
	return flux << (string)c;
}

