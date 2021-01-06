#pragma once
#include "ShapeDetector.h"

class SegmentDetector : public ShapeDetector {
public:
	SegmentDetector(ShapeDetector* next);
protected:
	Shape* charge1(string data) const;
};