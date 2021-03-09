#pragma once

#include <exception>
#include <string>

using namespace std;

class Error : public exception {
private:

	/**
	* the error's message
	*/
	string _error;

public:

	/**
	* Error
	*
	* @param {string} error : the error's message
	*/
	Error(string const& error = "") throw() : _error(error) {}

	/**
	*
	* @return {char*}  : the error's message
	*/
	virtual const char* what() const throw() {
		return _error.c_str();
	}

	/**
	* ~Error
	*/
	virtual  ~Error() {}
};
