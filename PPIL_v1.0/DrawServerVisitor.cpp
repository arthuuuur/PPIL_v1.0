#include <iostream>
#include <sstream>
#include "DrawServerVisitor.h"
#include "ShapesManager.h"


void DrawServerVisitor::visite(ShapesManager Sm) {
	vector<Shape*> tmp = Sm.getList();
	for (vector<Shape*>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		(*it)->draw();
	}
}