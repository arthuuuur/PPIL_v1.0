#pragma once
#include "ShapeDetector.h"

class CircleDetector : public ShapeDetector {

public:
	
	/**
	* CircleDetector
	* 
	* @param {ShapeDetector*} next : The next ShapeDetecor in the chaine of responsability
	*/
	CircleDetector(ShapeDetector* next);

protected:
	
	/**
	* Conversion of string into Circle
	* 
	* @param {string} data : the string to convert into Circle
	* 
	* @return {Shape*} : The Circle corresponding to the string data
	*/
	Shape* deserialize(const vector<string> data) const;
};