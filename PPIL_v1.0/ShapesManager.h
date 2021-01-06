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

		ShapeDetectorCOR * cor;
		vector<Shape*> listShape;
		vector<Group*> listGroup;

	public:

		ShapesManager();
		~ShapesManager();
		void addShape(Shape*);
		void addGroup(Group* G);
		void removeShape(Shape * S);
		void removeGroup(Group* G);
		void clean();
		vector<Shape*> getListShape();
		vector<Group*> getGroupShape();
		void save(string saveName);
		void load(string file);
		void accepte(ShapeManagerVisitor* S);
		friend ostream& operator<<(ostream& flux, const ShapesManager& c);
		virtual ostream& print(ostream& flux) const;
};