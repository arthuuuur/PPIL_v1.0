#pragma once
#include "ShapeVisitor.h"
#include "Group.h"

// to draw with the java server
class DrawServerVisitor : public ShapeVisitor {

public:

	void visite(Shape* S);
	void visite(Group* G);
	
};