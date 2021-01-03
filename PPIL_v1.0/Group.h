#pragma once

#include "Shape.h"
#include <vector>

class Group : public Shape {
protected:
	/**
	 * the list of the shapes of the group
	 */
	vector<Shape*> listShapes;

public:

	/**
	 * Group
	 *
	 * @param  {string} groupColor : the color of the group
	 * @param  {vector<Shape*} >   : the list of the shapes of the group
	 */
	Group(string groupColor, vector<Shape*> F);

	/**
	 * Group
	 *
	 * @param  {string} groupColor : the color of the group
	 */
	Group(string groupColor);

	/**
	 * Group
	 *
	 * @param  {Group} G : the group to be copied
	 */
	Group(const Group& G);

	/**
	 * ~Group
	 */
	virtual ~Group();

	/**
	 * @param  {Shape*} F : the shape to add at the group
	 */
	void addShape(Shape* F);

	/**
	 * @param  {Group} G : the group to add the group
	 */
	void addGroup(Group G);

	/**
	 * @return {double}  : the sum of all the area of the shape in the group
	 */
	const double getArea() const;

	void draw();

	/**
	* allows to make a translation using a translation vector in all the shape of the group
	*
	* @param  {double} ax : the abscisse of the translation vector
	* @param  {double} ay : the ordinate of the translation vector
	*/
	void translation(double ax, double ay);

	/**
	* allows to make a translation using an invariant point and a homothety ratio in all the shape of the group
	*
	* @param  {double} ax : the abscisse of the translation vector
	* @param  {double} ay : the ordinate of the translation vector
	* @param  {double} k  : the homothety ratio
	*/
	void homothety(double ax, double ay, double k);

	/**
	* allows to make a rotation using an invariant point and a rotation angle in all the shape of the group
	*
	* @param  {double} ax    : the abscisse of the translation vector
	* @param  {double} ay    : the ordinate of the translation vector
	* @param  {double} angle : the angle of the rotation in degrees
	*/
	void rotation(double ax, double ay, double angle);

	/**
	* @param  {ostream} flux : the output stream
	* @return {ostream}      : return the output stream with the print of the group
	*/
	ostream& print(ostream& flux) const;

	void accepte(ShapeVisitor* S);
};