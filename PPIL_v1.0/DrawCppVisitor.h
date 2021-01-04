#pragma once
#include "ShapeManagerVisitor.h"


class DrawCppVisitor : public ShapeManagerVisitor {
	
	public:
	
		void visite(ShapesManager Sm);
};