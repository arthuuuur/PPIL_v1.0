#include "Shape.h"
#include "Vector2D.h"
#include "Segment.h"
#include "Circle.h"
#include "Triangle.h"
#include "Group.h"
#include "ConvexPolygon.h"
#include "Error.h"
#include "ServerConnection.h"
#include "ShapeManagerVisitor.h"
#include "DrawServerVisitor.h"
#include "ShapesManager.h"
#include "SaveInText.h"
#include "LoadWithText.h"


int main() {
	
	Group* G1 = new Group(Color::RED);
	Vector2D v1(1, 1), v2(9, 5), v3(3, 7), v9(3, 8), v10(14, 3), v11(10, -5);
	Shape* s1 = new Segment(Color::YELLOW, v10, v11);
	Shape* s2 = new Circle(Color::CYAN, v9, 5);
	vector<Vector2D> listeV;
	listeV.push_back(v1);
	listeV.push_back(v2);
	listeV.push_back(v3);
	Shape* s3 = new Triangle(Color::YELLOW, listeV);
	G1->addShape(s1);
	G1->addShape(s2);
	G1->addShape(s3);

	Group* G2 = new Group(Color::GREEN);
	Vector2D v4(-1, -1), v5(-9, -5), v6(-3, -6), v12(-2, -2), v13(-10, -6);
	Shape* s4 = new Segment(Color::BLUE, v12, v13);
	Shape* s5 = new Circle(Color::BLUE, v6, 5);
	vector<Vector2D> listeV2;
	listeV2.push_back(v4);
	listeV2.push_back(v5);
	listeV2.push_back(v6);
	Shape* s6 = new Triangle(Color::BLUE, listeV2);
	G2->addShape(s4);
	G2->addShape(s5);
	G2->addShape(s6);

	Group* G3 = new Group(Color::YELLOW);
	Vector2D v7(-10, -10), v8(-20, -20);
	Shape* s8 = new Segment(Color::BLACK, v7, v8);
	Shape* s9 = new Circle(Color::BLACK, v7, 15);
	G3->addShape(s8);
	G3->addShape(s9);

	ShapesManager sm = ShapesManager();

	sm.addGroup(G1);
	sm.addGroup(G2);
	sm.addGroup(G3);
	G2->addGroup(G3);

	cout << endl << sm << endl << endl;

	ShapeManagerVisitor* saveTxt;
	saveTxt = new SaveInText;
	ShapeManagerVisitor* loadTxt;
	loadTxt = new LoadWithText;
	
	sm.accepte(saveTxt);
	sm.clean();
	sm.accepte(loadTxt);

	cout << endl << sm << endl << endl;
}