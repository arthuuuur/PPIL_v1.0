#pragma once
#include "ShapeDetector.h"

class PolygonDetector : public ShapeDetector {

public:

	/**
	* PolygonDetector
	*
	* @param {ShapeDetector*} next : The next ShapeDetecor in the chaine of responsability
	*/
	PolygonDetector(ShapeDetector* next);

protected:

	/**
	* Conversion of string into Polygon
	*
	* @param {string} data : the string to convert into Polygon
	* 
	* @return {Shape*} : The Polygon corresponding to the string data
	*/
	Shape* deserialize(const string data) const;
};