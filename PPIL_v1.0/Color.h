#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "Error.h"
#include <iostream>

using namespace std;

class Color {
	
	private:
		static const vector<string> AllowedColor;
		
	public:
		static const string RED;
		static const string GREEN;
		static const string BLUE;
		static const string CYAN;
		static const string YELLOW;
		static const string BLACK;

		static bool isAllowed(const string);
};