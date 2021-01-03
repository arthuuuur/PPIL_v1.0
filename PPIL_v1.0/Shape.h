#pragma once

#include <string>
#include <sstream>
#include "Vector2D.h"
#include "ServerConnection.h"
#include "ShapeVisitor.h"


using namespace std;

class Shape {

protected:
	/**
	* the color of the shape
	*/
	string _shapeColor;

	/**
	* the color of the shape when it is in a group
	*/
	string _groupColor;

	/**
	* true if the shape is in a groupe else false
	*/
	bool _isGrouped;

	/**
	* the point representing the center of gravity of the shape
	*/
	Vector2D* gravityCenter;

	/**
	* the id of the shape
	*/
	int ID;

	/**
	* the number of shape currently create to give the right id to the new shape
	*/
	static int nbID;

public:
	/**
	* Shape
	*
	* @param  {string} shapeColor : the color of the shape
	* @param  {bool} state        : if it is grouped or not
	*/
	Shape(string shapeColor = "red", bool state = false);

	/**
	* Shape
	*
	* @param  {Shape} F : the shape to be copied
	*/
	Shape(const Shape& F);

	/**
	* ~Shape
	*/
	virtual ~Shape();

	/**
	* @return {string}  : the color of the shape
	*/
	const string getShapeColor() const;

	/**
	*
	* @param  {string} shapeColor : the new color of the shape
	*/
	void setShapeColor(string shapeColor);

	/**
	*
	* @return {string}  : the color of the group
	*/
	const string getGroupColor() const;

	/**
	*
	* @param  {string} groupColor : the new color of the group
	*/
	void setGroupColor(string groupColor);

	/**
	*
	* @return {Vector2D}  : the center of gravity of the shape
	*/
	Vector2D getGravity() const;

	/**
	*
	* @param  {double} x : abscissa of the center of gravity
	* @param  {double} y : ordinate of the center of gravity
	*/
	void setGravity(double x, double y);

	/**
	*
	* @return {bool}  : true if it is grouped else false
	*/
	bool getIsGrouped() const;

	/**
	*
	* @param  {bool}  : the new state of the shape ( grouped or not )
	*/
	void setIsGrouped(bool);

	/**
	*
	* @return {double}  : the area of the shape
	*/
	virtual const double getArea() const = 0;

	/**
	*
	* @return {int}  : the number of shape created
	*/
	const int getNbID() const;

	/**
	*
	* @return {int}  : the id of the shape
	*/
	const int getID() const;

	/**
	* calculates and initializes the center of gravity of the shape
	*/
	void gravity();

	/**
	* conversion from shape to string
	*
	* @return {string}  : reprensentation of this shape in string
	*/
	virtual string serialize() const;

	void draw();

	/**
	* allows to make a translation using a translation vector
	*
	* @param  {double} ax : the abscisse of the translation vector
	* @param  {double} ay : the ordinate of the translation vector
	*/
	virtual void translation(double ax, double ay);

	/**
	* allows to make a translation using an invariant point and a homothety ratio
	*
	* @param  {double} ax : the abscisse of the translation vector
	* @param  {double} ay : the ordinate of the translation vector
	* @param  {double} k  : the homothety ratio
	*/
	virtual void homothety(double ax, double ay, double k);

	/**
	* allows to make a rotation using an invariant point and a rotation angle
	*
	* @param  {double} ax    : the abscisse of the translation vector
	* @param  {double} ay    : the ordinate of the translation vector
	* @param  {double} angle : the angle of the rotation in degrees
	*/
	virtual void rotation(double ax, double ay, double angle);

	/**
	*
	* @param  {ostream} flux :
	* @param  {Shape} c      :
	* @return {ostream}      :
	*/
	friend ostream& operator<<(ostream& flux, const Shape& c);

	/**
	* @param  {ostream} flux : the output stream
	* @return {ostream}      : return the output stream with the print of the shape
	*/
	virtual ostream& print(ostream& flux) const;
};
