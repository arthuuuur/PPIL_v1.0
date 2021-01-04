#pragma once

#include "Shape.h"
#include <vector>
#include "ShapeManagerVisitor.h"
#include "Group.h"

class ShapesManager {

	private:

		vector<Shape*> ObjectManager;

	public:

		ShapesManager();
		~ShapesManager();
		void addShape(Shape*);
		void addGroup(Group);
		void removeShape(Shape * S);
		void removeGroup(Group G);
		vector<Shape*> getList();
		void save();
		void load(string file);
		void accepte(ShapeManagerVisitor* S);
		friend ostream& operator<<(ostream& flux, const ShapesManager& c);
		virtual ostream& print(ostream& flux) const;
};