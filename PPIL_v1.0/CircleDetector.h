#pragma once

#include "ShapeDetector.h"
#include "Circle.h"

class CircleDetector : public ShapeDetector {

public:
	
	/**
	* CircleDetector's constructor
	* 
	* @param {ShapeDetector*} next : The next ShapeDetecor in the chaine of responsability
	*/
	CircleDetector(ShapeDetector* next);

protected:
	
	/**
	* Conversion of string into Circle
	* 
	* @param {vector<string>} data : the string to convert into Circle
	* 
	* @return {Shape*} : The Circle corresponding to the string data
	*/
	Shape* deserialize(const vector<string> data) const;
};