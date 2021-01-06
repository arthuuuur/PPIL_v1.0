#pragma once
#include "Shape.h"
#include <string>

class ShapeDetectorCOR {
public:
	virtual Shape* charge(string data) const = 0;
};
