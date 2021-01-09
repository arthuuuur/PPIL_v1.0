#pragma once
#include "ShapeDetector.h"

class CircleDetector : public ShapeDetector {

public:
	
	/**
	*
	*/
	CircleDetector(ShapeDetector* next);

protected:
	
	/**
	*
	*/
	Shape* charge1(string data) const;
};