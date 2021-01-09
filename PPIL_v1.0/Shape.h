#pragma once

#include <string>
#include <sstream>
#include "Vector2D.h"
#include "ServerConnection.h"

using namespace std;

class Shape {
	
protected:
	
	/**
	* The color of the shape
	* Red by default
	*/
	string _shapeColor;

	/**
	* The color of the shape when it is in a group
	* The _shapeColor by default 
	*/
	string _groupColor;

	/**
	* A flag to evaluate if the shape is grouped
	* False by default 
	*/
	bool _isGrouped;

	/**
	* The point representing the center of gravity of the shape
	* Initialized at the construction ofthe shape
	*/
	Vector2D* gravityCenter;

	/**
	* The number of shape currently create to give the right id to the new shape
	* Incremented automatically at each new shape
	*/
	static int nbID;
	
	/**
	* The id of the shape
	* Automatically associated thanks to nbID
	*/
	int ID;

	/*
	* The id of the group in which the shape is
	*/
	int groupID;

public:
	
	/**
	* Shape
	*
	* @param  {string} shapeColor : The color of the shape
	* @param  {bool} state        : If the shape is grouped or not
	*/
	Shape(string shapeColor = "red", bool state = false);

	/**
	* Shape
	*
	* @param  {Shape} F : The shape to be copied
	*/
	Shape(const Shape& F);

	/**
	* ~Shape
	*/
	virtual ~Shape();

	/**
	* Getter of shapeColor
	* 
	* @return {string}  : The color of the shape
	*/
	const string getShapeColor() const;

	/**
	* Setter of shapeColor
	* 
	* @param  {string} shapeColor : The new color of the shape
	*/
	void setShapeColor(string shapeColor);

	/**
	* Getter of groupColor
	* 
	* @return {string}  : The color of the group
	*/
	const string getGroupColor() const;

	/**
	* Setter of groupColor
	* 
	* @param  {string} groupColor : The new color of the group
	*/
	void setGroupColor(string groupColor);

	/**
	* Getter of gravityCenter
	* 
	* @return {Vector2D}  : The center of gravity of the shape
	*/
	Vector2D getGravity() const;

	/**
	* Setter of gravityCenter
	* 
	* @param  {double} x : Abscissa of the center of gravity
	* @param  {double} y : Ordinate of the center of gravity
	*/
	void setGravity(double x, double y);

	/**
	* Getter of isGrouped
	* 
	* @return {bool}  : True if the shape is grouped, else false
	*/
	bool getIsGrouped() const;

	/**
	* Setter of isGrouped
	* 
	* @param  {bool}  : The new state of the shape
	*/
	void setIsGrouped(bool);

	/**
	* Calculate the area of the shape
	* 
	* @return {double}  : The area of the shape
	*/
	virtual const double getArea() const = 0;

	/**
	* Getter of nbID
	* 
	* @return {int}  : The number of shape created
	*/
	const int getNbID() const;

	/**
	* Getter of ID
	* 
	* @return {int}  : The id of the shape
	*/
	const int getID() const;

	/*
	* Getter of groupID
	* 
	* @return {int}  : The groupID of the shape
	*/
	const int getGroupID() const;

	/*
	* Setter of ID
	*
	* @param {int} id  : The new ID of the shape
	*/
	void setID(int id);

	/*
	* Setter of groupID
	*
	* @param {int} GID  : The new groupID of the shape
	*/
	void setGroupID(int GID);

	/**
	* Calculate and initialize the gravity center of the shape
	*/
	void gravity();

	/**
	* Conversion from Shape to string
	*
	* @return {string}  : Reprensentation of the shape in string
	*/
	virtual string serialize() const;

	/**
	* Allows to make a translation using a translation vector
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	*/
	virtual void translation(double ax, double ay);

	/**
	* Allows to make a translation using an invariant point and a homothety ratio
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	* @param  {double} k  : The homothety ratio
	*/
	virtual void homothety(double ax, double ay, double k);

	/**
	* Allows to make a rotation using an invariant point and a rotation angle
	*
	* @param  {double} ax    : The abscisse of the translation vector
	* @param  {double} ay    : The ordinate of the translation vector
	* @param  {double} angle : The angle of the rotation in degrees
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
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the shape
	*/
	virtual ostream& print(ostream& flux) const;
};
