#pragma once

#include <string>
#include <sstream>
#include "Vector2D.h"
#include "ServerConnection.h"
#include "Color.h"

using namespace std;

class Shape {
 
protected:

	/**
	* Shape's color, red by default
	*/
	string _shapeColor;

	/**
	* Grouped shape color, _shapeColor by default
	*/
	string _groupColor;

	/**
	* If the shape is grouped or not, false by default
	*/
	bool _isGrouped; // ou un pointeur sur le groupe 

	/**
	* The point of the shape's gravity center, initialized at the shape's construction
	*/
	Vector2D gravityCenter; 

	/**
	* The number of shape currently create to give a valide id to a new shape
	*/
	static int nbShape;
	
	/**
	* Unique incremental id to identify the shape
	*/
	int ID;

	/*
	* The id of the group in which the shape is, else -1 
	*/
	int groupID;

public:

	/**
	* Shape
	*
	* @param  {string} shapeColor : Shape's color, red by default
	* @param  {bool} state        : Grouped or not, false by default
	*/
	Shape(const string shapeColor = Color::RED, const bool state = false);

	/**
	* ~Shape
	*/
	virtual ~Shape();

	/**
	* Getter of shapeColor
	* 
	* @return {string}  : Shape's color
	*/
	const string getShapeColor() const;

	/**
	* Setter of shapeColor
	* 
	* @param  {string} shapeColor : The new shape's color
	*/
	void setShapeColor(const string shapeColor);

	/**
	* Getter of groupColor
	* 
	* @return {string}  : Group's color
	*/
	const string getGroupColor() const;

	/**
	* Setter of groupColor
	* 
	* @param  {string} groupColor : The new group's color
	*/
	void setGroupColor(const string groupColor);

	/**
	* Getter of gravityCenter
	* 
	* @return {Vector2D}  : Shape's gravity center
	*/
	Vector2D getGravity() const;

	/**
	* Getter of isGrouped
	* 
	* @return {bool}  : True if grouped, else false
	*/
	bool getIsGrouped() const;

	/**
	* Setter of isGrouped
	* 
	* @param  {bool}  : The new shape's state
	*/
	void setIsGrouped(const bool);

	/**
	* Calculate the area of the shape
	* 
	* @return {double}  : The shape'area
	*/
	virtual const double getArea() const = 0;

	/**
	* Getter of nbShape
	* 
	* @return {int}  : The number of shape created
	*/
	const int getNbShape() const;

	/**
	* Getter of ID
	* 
	* @return {int}  : Shape's id
	*/
	const int getID() const;

	/*
	* Getter of groupID
	* 
	* @return {int}  : The group's id in which the shape is 
	*/
	const int getGroupID() const;

	/*
	* Setter of ID
	*
	* @param {int} id  : The new shape's id
	*/
	void setID(const int id);

	/*
	* Setter of groupID
	*
	* @param {int} GID  : The new group's id
	*/
	void setGroupID(const int GID);

	/**
	* Calculate and initialize the shape's gravity center
	*/
	void gravity();

	/**
	* Transforme the shape into a formatted string 
	*
	* @return {string}  : Formatted string 
	*/
	virtual string serialize() const;

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	* 
	* @return {Shape*}  : A new shape with applied translation
	*/
	virtual Shape* translation(const Vector2D& v) const = 0;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} v : The homothety's center
	* @param  {double} k  : The homothety ratio
	* 
	* @return {Shape*}  : A new shape with applied homothety
	*/
	virtual Shape* homothety(const Vector2D& centre, const double k) const = 0; 

	/**
	* Applies a rotation using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} v  : The rotation's center
	* @param  {double} angle : The rotation's angle
	* 
	* @return {Shape*}  : A new shape with applied rotation
	*/
	virtual Shape* rotation(const Vector2D& center, const double angle) const = 0;

	/**
	*
	*/
	friend ostream& operator<<(ostream& flux, const Shape& c);

	/**
	* 
	*/
	virtual ostream& print(ostream& flux) const;
};
