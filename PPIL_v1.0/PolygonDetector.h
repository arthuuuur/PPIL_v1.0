#pragma once
#include "ShapeDetector.h"

class PolygonDetector : public ShapeDetector {
public:
	PolygonDetector(ShapeDetector* next);
protected:
	Shape* charge1(string data) const;
};