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
	* A chaine of responsability to convert a serialized shape into a shape
	*/
	ShapeDetectorCOR* cor;
	
	/**
	* List of ShapesManager's shapes
	*/
	vector<Shape*> listShape;

	/**
	* List of ShapesManager's Group
	*/
	vector<Shape*> listGroup;

	/**
	* Add a new Shape to the list of shapes
	*
	* @param {Shape*} : The shape to be added to the list of shapes
	*/
	void addShape(Shape*);

	/**
	* Add a new Group to the list of groups
	*
	* @param {Shape*} : The group to be added to the list of groups
	*/
	void addGroup(Shape* G);

	/**
	* Remove a Shape to the list of shapes
	*
	* @param {Shape*} : The shape to be removed to the list of shapes
	*/
	void removeShape(Shape* S);

	/**
	* Remove a Group to the list of groupes
	*
	* @param {Shape*} : The group to be removed to the list of groups
	*/
	void removeGroup(Shape* G);

public:

	/**
	* ShapesManager
	*/
	ShapesManager();

	/**
	* ~ShapesManager
	*/
	~ShapesManager();

	void add(Shape* S);

	void remove(Shape* S);

	

	/**
	* Clean the both ShapesManager's lists
 	*/
	void clean();

	/**
	* Getter of listShape
	* 
	* @return {vector<Shape*>} : the list of Shapes
	*/
	vector<Shape*> getListShape();
	
	/**
	* Getter of listGroup
	* 
	* @return {vector<Group*>} : the list of Groups
	*/
	vector<Shape*> getGroupShape();

	/**
	* Save in a file all the shapes and groups of the ShapeManager's lists
	*/
	void save(const string saveName);

	/**
	* Load the shapes and groups of ShapesManager's lists thanks to a save file
	*/
	void load(const string file);

	/**
	* TO DO
	*/
	void accepte(ShapeManagerVisitor* S);

	/**
	*
	* @param  {ostream} flux :
	* @param  {ShapesManager} c      :
	* @return {ostream}      :
	*/
	friend ostream& operator<<(ostream& flux, const ShapesManager& c);

	/**
	* @param  {ostream} flux : The output stream
	* @return {ostream}      : Return the output stream with the print of the shape
	*/
	virtual ostream& print(ostream& flux) const;
};