#pragma once
#include "Shape.h"
#include <vector>
#include "ShapeDetectorCOR.h"

class ShapeDetector : public ShapeDetectorCOR {
public:
	ShapeDetector* next;
	Shape* charge(string data) const;
protected:
	ShapeDetector(ShapeDetector* next);
	virtual Shape* charge1(string data) const;
	vector<string> split(string str, string delim) const;
	int indexOf(vector<string> S, string val) const;
};
