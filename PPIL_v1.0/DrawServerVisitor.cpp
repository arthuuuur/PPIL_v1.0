#include <iostream>
#include <sstream>
#include "DrawServerVisitor.h"

void DrawServerVisitor::visite(Shape* S) {
	S->draw();
}

void DrawServerVisitor::visite(Group* G) {
	G->draw();
}



