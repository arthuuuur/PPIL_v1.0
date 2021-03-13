#pragma once

#include "ShapeManagerVisitor.h"
#include "ShapeDetector.h"

class LoadWithText : public ShapeManagerVisitor {

private:
	
	/**
	* A chain of responsability to convert a serialized shape into a shape
	*/
	ShapeDetectorCOR* cor;

	/*
	* Load file's path
	*/
	string _fileName;

public:

	/**
	* LoadWithText's constructor's
	* 
	* @param {string} fileName : load file's path
	*/
	LoadWithText(string fileName);

	/**
	* LoadWithText's destructor
	*/
	~LoadWithText();

	/**
	* The methode which add the new functionality to the shapesManager
	* this one is used to load all the contents of a file text into the shapesManager
	*
	* @param {shapesManager&} Sm : The shapesManager
	*/
	void visite(ShapesManager& Sm);
};