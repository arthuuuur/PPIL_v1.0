#include "ShapeDetector.h"

ShapeDetector::ShapeDetector(ShapeDetector* next) : next(next) {}

Shape* ShapeDetector::deserialize(const vector<string> data) const 
{
	return nullptr;
}

vector<string> ShapeDetector::split(const string str, const string separator) const
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do 
	{
		pos = str.find(separator, prev);
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + separator.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

int ShapeDetector::indexOf(vector<string> S, const string val) const
{
	int i = 0;
	for (vector<string>::const_iterator it = S.begin(); it != S.end(); it++) 
	{
		if (*it == val) 
		{
			return i;
		}
		i++;
	}
	return -1;
}

Shape* ShapeDetector::charge(const string data) const 
{
	Shape* res;
	res = this->deserialize(split(data,";"));
	if (res != NULL) 
	{
		return res;
	}
	else {
		if (this->next) 
		{
			return this->next->charge(data);
		}
		else 
		{
			return NULL;
		}
	}
}