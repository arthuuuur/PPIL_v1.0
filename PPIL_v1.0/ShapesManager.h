#pragma once

#include "Shape.h"
#include <vector>

class ShapesManager {

	private:

		vector<Shape*> ObecjtManager;

	public:

		ShapesManager();
		~ShapesManager();
		void addShape(Shape*);
		void removeShape(int id);
		virtual void draw(ServerConnection* client);
};