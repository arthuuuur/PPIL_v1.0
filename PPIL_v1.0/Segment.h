#pragma once

#include <math.h>
#include "Vector2D.h"
#include "Shape.h"
#include "Error.h"

using namespace std;

class Segment : public Shape {

private:

	/**
	* The first extremity of the point
	*/
	Vector2D* _p1;
	/**
	* The second extremity of the point
	*/
	Vector2D* _p2;

public:

	/**
	* Segment
	*
	* @param  {double} p1x : Abscissa of the first point
	* @param  {double} p1y : Ordinate of the first point
	* @param  {double} p2x : Abscissa of the second point
	* @param  {double} p2y : Ordinate of the second point
	*/
	Segment(double p1x, double p1y, double p2x, double p2y);

	/**
	* Segment
	*
	* @param  {string} shapeColor : The color of the segment
	* @param  {double} p1x        : Abscissa of the first point
	* @param  {double} p1y        : Ordinate of the first point
	* @param  {double} p2x        : Abscissa of the second point
	* @param  {double} p2y        : Ordinate of the second point
	*/
	Segment(string shapeColor, double p1x, double p1y, double p2x, double p2y);

	/**
	* Segment
	*
	* @param  {Segment} s : The segment to be copied
	*/
	Segment(const Segment& s);

	/**
	* ~Segment
	*/
	~Segment();

	/**
	* Getter of _p1
	* 
	* @return {Vector2D}  : The first extremity of the segment
	*/
	Vector2D getP1() const;

	/**
	* Getter of _p2
	* 
	* @return {Vector2D}  : the second extremity of the segment
	*/
	Vector2D getP2() const;

	/**
	* Calculate the are of the segment
	* 
	* @return {double}  : the area of the segment
	*/
	const double getArea() const;

	/**
	* Calculate the distance betwenn both of the extremities 
	* 
	* @return {double}  : The length of the segment
	*/
	const double lenght() const;

	/**
	* calculates and initializes the gravity center of the circle
	*/
	void gravity();

	/**
	* Conversion from segment to string
	*
	* @return {string}  : Reprensentation of this segment in string
	*/
	string serialize() const;

	/**
	* Allows to make a translation using a translation vector
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	*/
	void translation(double ax, double ay);

	/**
	* Allows to make a translation using an invariant point and a homothety ratio
	*
	* @param  {double} ax : The abscisse of the translation vector
	* @param  {double} ay : The ordinate of the translation vector
	* @param  {double} k  : The homothety ratio
	*/
	void homothety(double ax, double ay, double k);

	/**
	* Allows to make a rotation using an invariant point and a rotation angle
	*
	* @param  {double} ax    : The abscisse of the translation vector
	* @param  {double} ay    : The ordinate of the translation vector
	* @param  {double} angle : The angle of the rotation in degrees
	*/
	void rotation(double ax, double ay, double angle);

	/**
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the circle
	*/
	ostream& print(ostream& flux) const;
};