#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "Error.h"
#include <iostream>

using namespace std;

class Color {
	
	private:
		/**
		* List of allowed color for a shape
		*/
		static const vector<string> AllowedColor;
		
	public:
		static const string RED;
		static const string GREEN;
		static const string BLUE;
		static const string CYAN;
		static const string YELLOW;
		static const string BLACK;

		/**
		* Check if a color is in the AllowedColor list
		* @param  {string} color  : the color to check
		* 
		* @return {bool}  : True if allowed, else false
		*/
		static bool isAllowed(const string color);
};