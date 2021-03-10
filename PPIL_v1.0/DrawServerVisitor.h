#pragma once

#include "ShapeManagerVisitor.h"

class DrawServerVisitor : public ShapeManagerVisitor {

public:

	/**
	* The methode which add the new functionality to the shapesManager
	* this one is used to draw all the shapesManager's shapes by sending them to a Java server
	*
	* @param {shapesManager&} Sm : The shapesManager
	*/
	void visite(ShapesManager& Sm);
};