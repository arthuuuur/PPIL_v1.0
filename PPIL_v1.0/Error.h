#pragma once

#include <exception>
#include <string>

using namespace std;

class Error : public exception {
private:

	/**
	* the message of the error
	*/
	string _error;

public:

	/**
	* Error
	*
	* @param {string} error : the message off the error
	*/
	Error(string const& error = "") throw() : _error(error) {}

	/**
	*
	* @return {char*}  : the message of the error
	*/
	virtual const char* what() const throw() {
		return _error.c_str();
	}

	/**
	* ~Error
	*/
	virtual  ~Error()
	{}
};
