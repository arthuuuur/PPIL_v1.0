#pragma once

#include "ConvexPolygon.h"
#include "Vector2D.h"

using namespace std;

class Triangle : public ConvexPolygon {

	public:

		/**
		* Triangle 
		* 
		* @param  {double} ax : abscissa of the first point
		* @param  {double} ay : ordinate of the first point
		* @param  {double} bx : abscissa of the second point
		* @param  {double} by : ordinate of the second point
		* @param  {double} cx : abscissa of the third point
		* @param  {double} cy : ordinate of the third point
		*/
			Triangle(double ax, double ay, double bx, double by, double cx, double cy);

		/**
		* Triangle 
		* 
		* @param  {string} shapeColor : the color of the triangle
		* @param  {double} ax		  : abscissa of the first point
		* @param  {double} ay		  : ordinate of the first point
		* @param  {double} bx		  : abscissa of the second point
		* @param  {double} by		  : ordinate of the second point
		* @param  {double} cx		  : abscissa of the third point
		* @param  {double} cy		  : ordinate of the third point
		*/
			Triangle(string shapeColor, double ax, double ay, double bx, double by, double cx, double cy);

		/**
		* Triangle 
		* 
		* @param  {vector<Vector2D>} S : the list of the points of the triangle
		*/
			Triangle(vector<Vector2D> S);

		/**
		* Triangle 
		* 
		* @param  {string} shapeColor  : the color of the triangle
		* @param  {vector<Vector2D>} S : the list of the points of the triangle
		*/
			Triangle(string shapeColor, vector<Vector2D> S);

		/**
		* ~Triangle 
		*/
			virtual ~Triangle();

		/**
		* @return {double}  : the area of the triangle
		*/
			const double getArea() const;

		/**
		* @param  {ostream} flux : the output stream
		* @return {ostream}      : return the output stream with the print of the triangle
		*/
			ostream& print(ostream& flux) const;
};
