#pragma once
#include "Shape.h"
#include <vector>
#include "ShapeDetectorCOR.h"

class ShapeDetector : public ShapeDetectorCOR {

public:

	/**
	* The next ShapeDetector in the chaine of responsability
	*/
	ShapeDetector* next;

	/**
	* Charge the string into the chaine of responsability
	* 
	* @param {string} data : The string to process thanks to the chaine of responsability
	* 
	* @return {Shape*} : The shape corresponding to the string data
	*/
	Shape* charge(const string data) const;

protected:

	/**
	* ShapeDetector
	* 
	* @param {ShapeDetector*} : The next ShapeDetector in the chaine of responsability
	*/
	ShapeDetector(ShapeDetector* next);

	/**
	* Conversion of string into Shape
	*
	* @param {string} data : the string to convert into Polygon
	* 
	* @return {Shape*} : The Shape corresponding to the string data 
	*/
	virtual Shape* deserialize(const string data) const;

	/*
	* Split a string into a vector of string with a specific separator
	* 
	* @param {string} str   : The string to split  
	* @param {string} separator : The separator
	* 
	* @return {vector<string>} : Return a vector of string created by splitting the string parameter into several pieces according to the separator parameter.
	*/
	vector<string> split(const string str, const string separator) const;

	/*
	* Return the index of a string into a vector of string 
	*
	* @param {vector<String>} S   : The vector of string
	* @param {string} val         : The string of which we want the index
	*
	* @return {int} : Return the index of a string into a vector of string 
	*/
	int indexOf(vector<string> S, const string val) const;
};
