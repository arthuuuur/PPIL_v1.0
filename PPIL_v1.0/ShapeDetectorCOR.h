#pragma once

#include "Shape.h"

class ShapeDetectorCOR {

public:

	/**
	* Charge the string into the chaine of responsability
	*
	* @param {string} data : The string to process thanks to the chaine of responsability
	*
	* @return {Shape*} : The shape corresponding to the string data
	*/
	virtual Shape* charge(string data) const = 0;
};
