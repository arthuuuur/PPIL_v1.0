#pragma once

#include "Shape.h"
#include <vector>

class Group : public Shape {

protected:
	
	/**
	 * The list of the group's shapes
	 */
	vector<Shape*> listShapes;

public:

	/**
	 * Group
	 *
	 * @param  {string} groupColor : The group's color
	 * @param  {vector<Shape*>} L : The list of the group's shapes
	 */
	Group(const string groupColor, vector<Shape*> L);

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
	* @param  {Shape*} S : The shape to be added to the list
	*/
	void addShape(Shape* S);

	/**
	* Add all the shapes of a group to the list of shapes
	* 
	* @param  {Group*} G : The group of shape to be added to the list
	*/
	void addGroup(Shape * G);

	/**
	* Remove a shape to the list of shapes
	*
	* @param  {Shape*} S : The shape to be removed of the list
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

	/**
	* Getter of listShapes
	* 
	* @return {vector<Shape*>}  : The list of group's shape
	*/
	vector<Shape*> getList();

	/**
	* Setter of ColorIfGrouped for a group, change also the ColorIfGrouped of each shapes in the group
	* 
	* @param {string} ColorIfGrouped : the new ColorIfGrouped
	*/
	void setColorIfGrouped(const string ColorIfGrouped);

	/**
	* Setter of GroupID for a group, change also the groupID of each shapes in the group
	*
	* @param {int} GID : the new groupID
	*/
	void setGroupID(const int GID);

	/**
	* Setter of ShapeColor for a group, change also the ColorIfGrouped of each shapes in the group if this group isn't grouped 
	* 
	* @param {string} shapeColor : the new shapeColor
	*/
	void setShapeColor(const string shapeColor);

	/**
	* Applies a translation to all the shape in the groupe using a translation vector
	*
	* @param  {Vector2D} v : The translation vector
	*
	* @return {Shape*}  : v1 new group with applied translation
	*/
	Shape* translation(const Vector2D& v) const;

	/**
	* Applies a homothety to all the shape in the group using an invariant point and a homothety ratio
	*
	* @param  {Vector2D} center : The homothety's center
	* @param  {double} k  : The homothety ratio
	*
	* @return {Shape*}  : v1 new group with applied homothety
	*/
	Shape* homothety(const double k, const Vector2D& center = Vector2D(0, 0)) const;

	/**
	* Applies a rotation in the counterclokwise to all the shape in the group using an invariant point and a rotation angle in radiant
	*
	* @param  {Vector2D} center  : The rotation's center
	* @param  {double} angle : The rotation's angle
	*
	* @return {Shape*}  : v1 new group with applied rotation
	*/
	Shape* rotation(const double angle, const Vector2D& center = Vector2D(0, 0)) const;

	operator string() const;
};