#include <iostream>
#include <sstream>
#include "DrawServerVisitor.h"
#include "ShapesManager.h"


void DrawServerVisitor::visite(ShapesManager Sm) {
	vector<Shape*> tmp = Sm.getListShape();
	for (vector<Shape*>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		(*it)->draw();
	}
	vector<Group*> tmp2 = Sm.getGroupShape();
	for (vector<Group*>::iterator it = tmp2.begin(); it != tmp2.end(); it++) {
		(*it)->draw();
	}
}