#pragma once
#include "ShapeDetector.h"

class SegmentDetector : public ShapeDetector {

public:
	
	/**
	* SegmentDetector
	*
	* @param {ShapeDetector*} next : The next ShapeDetecor in the chaine of responsability
	*/
	SegmentDetector(ShapeDetector* next);

protected:
	
	/**
	* Conversion of string into Segment
	*
	* @param {string} data : the string to convert into Segment
	* 
	* @return {Shape*} : The Segment corresponding to the string data
	*/
	Shape* deserialize(const string data) const;
};