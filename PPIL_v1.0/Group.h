#pragma once

#include "Shape.h"
#include <vector>

class Group : public Shape {

protected:
	
	/**
	 * The list of the group's Shapes
	 */
	vector<Shape*> listShapes;

public:

	/**
	 * Group
	 *
	 * @param  {string} groupColor : The color of the group
	 * @param  {vector<Shape*} >   : The list of the group's Shapes
	 */
	Group(const string groupColor, vector<Shape*> F);

	/**
	 * Group
	 *
	 * @param  {string} groupColor : The color of the group
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
	void addGroup(Group * G);

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
	void removeGroup(Group * G);

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

	/**
	* Allows to make a translation using a translation vector in all the shape of the group
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	*/
	Shape* translation(const Vector2D& v) const;

	/**
	* Allows to make a translation using an invariant point and a homothety ratio in all the shape of the group
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	* @param  {double} k  : The homothety ratio
	*/
	Shape* homothety(const Vector2D& v, const double k) const;

	/**
	* Allows to make a rotation using an invariant point and a rotation angle in all the shape of the group
	*
	* @param  {double} ax    : The abscisse of the translation vector
	* @param  {double} ay    : The ordinate of the translation vector
	* @param  {double} angle : The angle of the rotation in degree
	*/
	Shape* rotation(const Vector2D& v, const double angle) const;

	/**
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the group
	*/
	ostream& print(ostream& flux) const;

	string serialize() const;
};