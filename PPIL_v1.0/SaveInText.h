#pragma once

#include "ShapeManagerVisitor.h"
#include "ShapesManager.h"

class SaveInText : public ShapeManagerVisitor {

private:
	
	/**
	* Save file's path
	*/
	string _fileName;

public:

	/**
	* SaveInText's constructor
	* 
	* @param {string} fileName : save file's path
	*/
	SaveInText(string fileName) : _fileName(fileName) {}

	/**
	* The methode which add the new functionality to the shapesManager
	* this one is used to back up all the contents of the shapesManager into a text file
	*
	* @param {shapesManager&} Sm : The shapesManager
	*/
	void visite(ShapesManager& Sm);


};