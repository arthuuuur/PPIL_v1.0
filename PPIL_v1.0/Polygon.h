#pragma once

#include <vector>
#include "Vector2D.h"
#include "Shape.h"

using namespace std;

class Polygon : public Shape {
	
	protected:
		/**
		* @param  {} : the list of the points of the polygon
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
		* @param  {vector<Vector2D>} S : the list of the points of the polygon
		*/
			Polygon(vector<Vector2D> S);

		/**
		* ~Polygon 
		*/
			virtual ~Polygon();

		/**
		* @return {double}  : the area of the polygon
		*/
			virtual const double getArea() const = 0;

		/**
		* calculates and initializes the center of gravity of the polygon
		*/
			void gravity();

		/**
		* conversion from polygon to string
		*
		* @return {string}  : reprensentation of this polygon in string
		*/
			string serialize() const;

			virtual void draw(ServerConnection* client);

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
		* @return {ostream}      : return the output stream with the print of the polygon
		*/
			virtual ostream& print(ostream& flux) const;
};