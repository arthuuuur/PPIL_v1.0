#pragma once

#include <math.h>
#include "Vector2D.h"
#include "Shape.h"
#include "Error.h"

using namespace std;

class Segment : public Shape {
	
	private:

		/**
		* the first extremity of the point
		*/
			Vector2D* _p1;
		/**
		* the second extremity of the point
		*/
			Vector2D* _p2;

	public:

		/**
		* Segment 
		* 
		* @param  {double} p1x : abscissa of the first point
		* @param  {double} p1y : ordinate of the first point
		* @param  {double} p2x : abscissa of the second point
		* @param  {double} p2y : ordinate of the second point
		*/
			Segment(double p1x, double p1y, double p2x, double p2y);

		/**
		* Segment 
		* 
		* @param  {string} shapeColor : the color of the segment
		* @param  {double} p1x        : abscissa of the first point
		* @param  {double} p1y        : ordinate of the first point
		* @param  {double} p2x        : abscissa of the second point
		* @param  {double} p2y        : ordinate of the second point
		*/
			Segment(string shapeColor, double p1x, double p1y, double p2x, double p2y);

		/**
		* Segment 
		* 
		* @param  {Segment} s : the segment to be copied
		*/
			Segment(const Segment& s);

		/**
		* ~Segment 
		*/
			~Segment();

		/**
		* @return {Vector2D}  : the first extremity of the segment 
		*/
			Vector2D getP1() const;

		/**
		* @return {Vector2D}  : the second extremity of the segment
		*/
			Vector2D getP2() const;

		/**
		* @return {double}  : the area of the segment
		*/
			const double getArea() const;

		/**
		* @return {double}  : the distance betwenn both of the extremities
		*/
			const double lenght() const;

		/**
		* calculates and initializes the center of gravity of the circle
		*/
			void gravity();

		/**
		* conversion from segment to string
		*
		* @return {string}  : reprensentation of this segment in string
		*/
			string serialize() const;

			void draw(ServerConnection* client);
			

		/**
		* allows to make a translation using a translation vector
		*
		* @param  {double} ax : the abscisse of the translation vector
		* @param  {double} ay : the ordinate of the translation vector
		*/
			void translation(double ax, double ay);

		/**
		* allows to make a translation using an invariant point and a homothety ratio
		*
		* @param  {double} ax : the abscisse of the translation vector
		* @param  {double} ay : the ordinate of the translation vector
		* @param  {double} k  : the homothety ratio
		*/
			void homothety(double ax, double ay, double k);

		/**
		* allows to make a rotation using an invariant point and a rotation angle
		*
		* @param  {double} ax    : the abscisse of the translation vector
		* @param  {double} ay    : the ordinate of the translation vector
		* @param  {double} angle : the angle of the rotation in degrees
		*/
			void rotation(double ax, double ay, double angle);

		
		/**
		* @param  {ostream} flux : the output stream
		* @return {ostream}      : return the output stream with the print of the circle
		*/
			ostream& print(ostream& flux) const;
};