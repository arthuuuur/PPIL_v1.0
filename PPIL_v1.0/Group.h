#pragma once

#include "Shape.h"
#include <vector>

class Group : public Shape {

protected:
	
	/**
	 * The list of the group's shapes
	 */
	vector<Shape*> listShapes;

	/**
	* Impossible to serialize a group 
	*/
	string serialize() const;

public:

	/**
	 * Group
	 *
	 * @param  {string} groupColor : The group's color
	 * @param  {vector<Shape*} >   : The list of the group's shapes
	 */
	Group(const string groupColor, vector<Shape*> F);

	/**
	 * Group
	 *
	 * @param  {string} groupColor : The group's color
	 */
	Group(const string groupColor);

	/**
	 * Group
	 *
	 * @param  {Group&} G : The group to be copied
	 */
	Group(const Group& G);

	/**
	 * ~Group
	 */
	virtual ~Group();

	

	/**
	* Add a new Shape to the list of shapes
	* 
	* @param  {Shape*} F : The shape to be added to the list
	*/
	void addShape(Shape* F);

	/**
	* Add all the shapes of a group to the list of shapes
	* 
	* @param  {Group*} G : The group of shape to be added to the list
	*/
	void addGroup(Shape * G);

	/**
	* Remove a shape to the list of shapes
	*
	 * @param  {Shape*} F : The shape to be removed of the list
	 */
	void removeShape(Shape * S);
	
	/**
	* Remove all the shapes of a specific group to the list of shapes
	*
	 * @param  {Group*} G : The group of shape to be removed to the list
	 */
	void removeGroup(Shape * G);

	/**
	* Calculate the area of all the shapes in the group
	* 
	 * @return {double}  : The sum of all the area of the shape in the group
	 */
	const double getArea() const;

	/*
	* Getter of listShapes
	* 
	* @return {<vector>}  : The list of group's shape
	*/
	vector<Shape*> getList();

	void setColorIfGrouped(const string groupColor);

	void setGroupID(const int GID);

	void setShapeColor(const string shapeColor);

	/**
	* Applies a translation to all the shape in the groupe using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : A new group with applied translation
	*/
	Shape* translation(const Vector2D& v) const;

	/**
	* Applies a homothety to all the shape in the group using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} v : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : A new group with applied homothety
	*/
	Shape* homothety(const Vector2D& center, const double k) const;

	/**
	* Applies a rotation to all the shape in the group using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} v  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : A new group with applied rotation
	*/
	Shape* rotation(const Vector2D& center, const double angle) const;

	/**
	*
	*/
	ostream& print(ostream& flux) const;
};