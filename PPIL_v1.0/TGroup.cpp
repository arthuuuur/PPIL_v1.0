#include "Shape.h"
#include "Vector2D.h"
#include "Segment.h"
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Group.h"
#include "ConvexPolygon.h"
#include "Error.h"
#include "ServerConnection.h"
#include "DrawCppVisitor.h"
#include "ShapeManagerVisitor.h"
#include "DrawServerVisitor.h"
#include "ShapesManager.h"

using namespace std;

int main() {
	
	Group *G1 = new Group(Color::RED);
	Vector2D v1(1, 1), v2(2, 2), v3(3, 3);
	Shape* s1 = new Segment(v1, v2);
	Shape* s2 = new Circle(v3, 5);
	vector<Vector2D> listeV;
	listeV.push_back(v1);
	listeV.push_back(v2);
	listeV.push_back(v3);
	Shape* s3 = new Triangle(listeV);
	G1->addShape(s1);
	G1->addShape(s2);
	G1->addShape(s3);

	Group * G2 = new Group(Color::GREEN);
	Vector2D v4(-1, -1), v5(-2, -2), v6(-3, -3);
	Shape* s4 = new Segment(v4, v5);
	Shape* s5 = new Circle(v6, -5);
	Shape* s7 = new Segment(v5, v5);
	vector<Vector2D> listeV2;
	listeV2.push_back(v4);
	listeV2.push_back(v5);
	listeV2.push_back(v6);
	Shape* s6 = new Triangle(listeV2);
	G2->addShape(s4);
	G2->addShape(s5);
	G2->addShape(s6);

	G1->addGroup(G2);
	cout << *G1 << endl << endl << endl;
	cout << *G2 << endl << endl << endl;

	G2->addShape(s7);
	cout << *G1 << endl << endl << endl;
	cout << *G2 << endl << endl << endl;

	
	G1->removeGroup(G2);
	cout << *G1 << endl << endl << endl;
	cout << *G2 << endl << endl << endl;

	ShapesManager sm = ShapesManager();
	sm.add(s1);
	sm.add(G2);
	sm.add(s3);
	sm.save("test.txt");
	sm.clean();
	sm.load("test.txt");

	cout << sm << endl;

}