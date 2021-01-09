#pragma once
#include "ShapeManagerVisitor.h"

class DrawServerVisitor : public ShapeManagerVisitor {
public:

	void visite(ShapesManager Sm);
};