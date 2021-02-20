#pragma once

#include <vector>
#include "Vector2D.h"
#include "Shape.h"

using namespace std;

class Polygon : public Shape {

protected:
	/**
	* The list of polygon's points
	*/
	vector<Vector2D> listPoints;

public:
	
	/**
	* Polygon
	*/
	Polygon();

	/**
	* Polygon
	*
	* @param  {vector<Vector2D>} S : The list of polygon's points
	*/
	Polygon(vector<Vector2D> S);

	/**
	* ~Polygon
	*/
	virtual ~Polygon();

	/**
	* Calculate the area of the polygon
	* 
	* @return {double}  : The area of the polygon
	*/
	virtual const double getArea() const = 0;

	/**
	* Calculate and initialize the gravity center of the polygon
	*/
	void gravity();

	/**
	* Conversion of polygon into string
	*
	* @return {string}  : Reprensentation of this polygon in string
	*/
	string serialize() const;

	/**
	* Allows to make a translation using a translation vector
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	*/
	Shape* translation(const Vector2D& v) const = 0;

	/**
	* Allows to make a translation using an invariant point and a homothety ratio
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	* @param  {double} k  : The homothety ratio
	*/
	Shape* homothety(const Vector2D& centre, const double k) const = 0;

	/**
	* Allows to make a rotation using an invariant point and a rotation angle
	*
	* @param  {double} ax    : The abscisse of the translation vector
	* @param  {double} ay    : The ordinate of the translation vector
	* @param  {double} angle : The angle of the rotation in degree
	*/
	Shape* rotation(const Vector2D& v, const double angle) const = 0;

	/**
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the polygon
	*/
	virtual ostream& print(ostream& flux) const;
};