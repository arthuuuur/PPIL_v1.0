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
	Group(string groupColor, vector<Shape*> F);

	/**
	 * Group
	 *
	 * @param  {string} groupColor : The color of the group
	 */
	Group(string groupColor);

	/**
	 * Group
	 *
	 * @param  {Group} G : The group to be copied
	 */
	Group(const Group& G);

	/**
	 * ~Group
	 */
	virtual ~Group();

	/**
	* Add a new Shape to the list of shapes
	* 
	 * @param  {Shape*} F : The shape to add at the group
	 */
	void addShape(Shape* F);

	/**
	* Add a new Group to the list of shapes
	* 
	 * @param  {Group} G : The group to add at the group
	 */
	void addGroup(Group G);

	/**
	* Calculate the area of all the shape is the group
	* 
	 * @return {double}  : The sum of all the area of the shape in the group
	 */
	const double getArea() const;

	/*
	* Getter of listShapes
	* 
	* @return {<vector>}  : The list of group's Shape
	*/
	vector<Shape*> getList();

	/**
	* Allows to make a translation using a translation vector in all the shape of the group
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	*/
	void translation(double ax, double ay);

	/**
	* Allows to make a translation using an invariant point and a homothety ratio in all the shape of the group
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	* @param  {double} k  : The homothety ratio
	*/
	void homothety(double ax, double ay, double k);

	/**
	* Allows to make a rotation using an invariant point and a rotation angle in all the shape of the group
	*
	* @param  {double} ax    : The abscisse of the translation vector
	* @param  {double} ay    : The ordinate of the translation vector
	* @param  {double} angle : The angle of the rotation in degrees
	*/
	void rotation(double ax, double ay, double angle);

	/**
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the group
	*/
	ostream& print(ostream& flux) const;
};