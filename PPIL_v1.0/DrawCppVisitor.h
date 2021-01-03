#pragma once
#include "ShapeVisitor.h"
#include "Group.h"

class DrawCppVisitor : public ShapeVisitor {
	
	public:
	
		void visite(Shape* S);
		void visite(Group* G);
};