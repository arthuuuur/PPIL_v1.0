#include "DrawCppVisitor.h"
#include <iostream>
#include <sstream>


void DrawCppVisitor::visite(Shape* S){
	std::cout << "Methode de dessin grace au visiteur pour une librairie graphique c++" << std::endl;
}

void DrawCppVisitor::visite(Group* G) {
	std::cout << "Methode de dessin grace au visiteur pour une librairie graphique c++" << std::endl;
}
