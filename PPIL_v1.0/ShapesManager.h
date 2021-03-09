#pragma once

#include "Shape.h"
#include <vector>
#include "ShapeManagerVisitor.h"
#include "Group.h"
#include <fstream>
#include "Error.h"
#include "ShapeDetector.h"


class ShapesManager {

private:

	/**
	* List of ShapesManager's shapes
	*/
	vector<Shape*> listShape;

	/**
	* List of ShapesManager's Group
	*/
	vector<Shape*> listGroup;

public:

	/**
	* Add a new Shape to the list of shapes
	*
	* @param {Shape*} S : The shape to be added to the list of shapes
	*/
	void addShape(Shape* S);

	/**
	* Add a new Group to the list of groups
	*
	* @param {Shape*} G : The group to be added to the list of groups
	*/
	void addGroup(Shape* G);

	/**
	* Remove a Shape to the list of shapes
	*
	* @param {Shape*} S : The shape to be removed to the list of shapes
	*/
	void removeShape(Shape* S);

	/**
	* Remove a Group to the list of groupes
	*
	* @param {Shape*} G : The group to be removed to the list of groups
	*/
	void removeGroup(Shape* G);

	/**
	* Clean the both ShapesManager's lists
 	*/
	void clean();

	/**
	* Getter of listShape
	* 
	* @return {vector<Shape*>} : the list of Shapes
	*/
	const vector<Shape*>& getListShape() const;
	
	/**
	* Getter of listGroup
	* 
	* @return {vector<Shape*>} : the list of Groups
	*/
	const vector<Shape*>& getGroupShape() const;

	/**
	* TO DO
	*/
	void accepte(ShapeManagerVisitor* S);

	operator string() const;
};

ostream& operator<<(ostream& flux, const ShapesManager& c);