#pragma once

#include <string>
#include <sstream>
#include "Vector2D.h"
#include "Color.h"

using namespace std;

class Shape {
 
protected:
	
	/**
	* The shape's color, red by default
	*/
	string _shapeColor;
	
	/**
	* The shape's color if grouped, _shapeColor by default
	*/
	string _colorIfGrouped;
	
	/**
	* v1 pointer to the group in wich the shape is, null if not 
	*/
	Shape* father;
	
	/**
	* The gravity center's point
	*/
	Vector2D gravityCenter; 
	
	/**
	* The total number of shape created
	*/
	static int nbShape;
	
	/**
	* v1 unique incremental identifier 
	*/
	int ID;
	
	/**
	* The group id in wich the shape is, else the shape's id 
	*/
	int groupID;

public:

	/**
	* Shape
	*
	* @param  {string} shapeColor : Shape's color, red by default
	*/
	Shape(const string shapeColor = Color::RED);

	/**
	* Shape
	* 
	* @param  {Shape} S : The shape to be copied
	*/
	Shape(const Shape& S);

	/**
	* ~Shape
	*/
	virtual ~Shape();

	/**
	* Getter of father
	* 
	* @return {Shape*} : v1 pointer to the group in wich the shape is
	*/
	Shape* getFather() const;

	/**
	* Setter of father
	*
	* @param {Shape*} S : v1 pointer to the group in wich the shape is
	*/
	void setFather(Shape* S);

	/**
	* Get the id of the group in wich the shape is
	* 
	* @return {int} : the id of the group in wich the shape is
	*/ 
	const int getFatherID();

	/**
	* Get the color of the group in wich the shape is
	*
	* @return {string} : the color of the group in wich the shape is
	*/
	const string getFatherColor();

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
	virtual void setShapeColor(const string shapeColor);

	/**
	* Getter of groupColor
	* 
	* @return {string}  : Group's color
	*/
	const string getColorIfGrouped() const;

	/**
	* Setter of groupColor
	* 
	* @param  {string} groupColor : The new group's color
	*/
	virtual void setColorIfGrouped(const string groupColor);

	/**
	* Getter of gravityCenter
	* 
	* @return {Vector2D}  : Shape's gravity center
	*/
	Vector2D getGravity() const;

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
	virtual void setGroupID(const int GID);

	/**
	* Calculate and initialize the shape's gravity center
	*/
	void gravity();

	/**
	* Transforme the shape into a formatted string 
	*
	* @return {string}  : Formatted string 
	*/
	virtual const string serialize() const;

	/**
	* Applies a translation using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	* 
	* @return {Shape*}  : v1 new shape with applied translation
	*/
	virtual Shape* translation(const Vector2D& v) const = 0;

	/**
	* Applies a homothety using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} center : The homothety's center
	* @param  {double} k  : The homothety ratio
	* 
	* @return {Shape*}  : v1 new shape with applied homothety
	*/
	virtual Shape* homothety(const double k, const Vector2D& centre = Vector2D(0, 0)) const = 0;

	/**
	* Applies a rotation in the counterclokwise using an invariant point and a rotation angle in radian
	*
	* @param  {Vector2D} center  : The rotation's center
	* @param  {double} angle : The rotation's angle
	* 
	* @return {Shape*}  : v1 new shape with applied rotation
	*/
	virtual Shape* rotation(const double angle, const Vector2D& centre = Vector2D(0, 0)) const = 0; // verifier si l'angle est bien orienté ou pas 

	friend ostream& operator<<(ostream& flux, const Shape& c);

	ostream& print(ostream& flux) const;

	virtual operator string() const; 
};
