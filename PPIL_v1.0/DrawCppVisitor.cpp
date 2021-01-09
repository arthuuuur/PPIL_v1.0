#include "DrawCppVisitor.h"
#include <iostream>
#include <sstream>
#include "ShapesManager.h"

void DrawCppVisitor::visite(ShapesManager Sm) {
	std::cout << "Methode de dessin grace au visiteur pour une librairie graphique c++" << std::endl;
}