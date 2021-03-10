#include "Color.h"

const string Color::RED = "red";
const string Color::GREEN = "green";
const string Color::BLUE = "blue";
const string Color::CYAN = "cyan";
const string Color::YELLOW = "yellow";
const string Color::BLACK = "black";

const vector<string> Color::AllowedColor = { "red", "green", "blue", "cyan", "yellow", "black" };

bool Color::isAllowed(const string color)
{
	try 
	{
		if (find(AllowedColor.begin(), AllowedColor.end(), color) != AllowedColor.end()) 
		{
			return true;
		}
		else 
		{
			throw Error("Unallowed color : " + color);
		}
	}
	catch (exception const& err) 
	{
		cerr << err.what() << endl;
		exit(-1);
	}

}