#pragma once

#include "ShapeDetector.h"
#include "ConvexPolygon.h"

class PolygonDetector : public ShapeDetector {

public:

	/**
	* PolygonDetector's constructor
	*
	* @param {ShapeDetector*} next : The next ShapeDetecor in the chaine of responsability
	*/
	PolygonDetector(ShapeDetector* next);

protected:

	/**
	* Conversion of string into Polygon
	*
	* @param {vector<string>} data : the string to convert into Polygon
	* 
	* @return {Shape*} : The Polygon corresponding to the string data
	*/
	Shape* deserialize(const vector<string> data) const;
};