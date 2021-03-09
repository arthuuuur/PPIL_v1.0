#pragma once

#include "ShapeManagerVisitor.h"
#include "ShapeDetector.h"

class LoadWithText : public ShapeManagerVisitor {

private:
	
	/**
	* A chain of responsability to convert a serialized shape into a shape
	*/
	ShapeDetectorCOR* cor;

public:

	LoadWithText();

	~LoadWithText();

	/**
	* TO DO
	*/
	void visite(ShapesManager& Sm);
};