#pragma once

class ShapesManager;

class ShapeManagerVisitor {

public:

	/**
	* The methode which add the new functionality to the shapesManager
	* 
	* @param {shapesManager&} Sm : The shapesManager
	*/
	virtual void visite(ShapesManager& Sm) = 0;
};