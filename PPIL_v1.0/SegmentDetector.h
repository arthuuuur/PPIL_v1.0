#pragma once
#include "ShapeDetector.h"

class SegmentDetector : public ShapeDetector {

public:
	
	/**
	* SegmentDetector
	*/
	SegmentDetector(ShapeDetector* next);

protected:
	
	/**
	*
	*/
	Shape* charge1(string data) const;
};