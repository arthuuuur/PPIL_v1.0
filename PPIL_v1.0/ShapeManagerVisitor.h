#pragma once

class ShapesManager;

class ShapeManagerVisitor {

public:

	/**
	* TO DO
	*/
	virtual void visite(ShapesManager& Sm) = 0;
};