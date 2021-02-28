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
#include "ShapeManagerVisitor.h"
#include "DrawServerVisitor.h"
#include "ShapesManager.h"
#include "SaveInText.h"
#include "LoadWithText.h"

using namespace std;

int main() {

	Group* G1 = new Group(Color::RED);
	Vector2D v1(1, 1), v2(2, 2), v3(3, 3);
	Shape* s1 = new Segment(Color::YELLOW, v1, v2);
	Shape* s2 = new Circle(Color::YELLOW, v3, 5);
	vector<Vector2D> listeV;
	listeV.push_back(v1);
	listeV.push_back(v2);
	listeV.push_back(v3);
	Shape* s3 = new Triangle(Color::YELLOW, listeV);
	G1->addShape(s1);
	G1->addShape(s2);
	G1->addShape(s3);

	//cout << *s1->getFather() << *s1->getFatherID() << *s1->getColorIfGrouped()




	Group* G2 = new Group(Color::GREEN);
	Vector2D v4(-1, -1), v5(-2, -2), v6(-3, -3);
	Shape* s4 = new Segment(Color::BLUE, v4, v5);
	Shape* s5 = new Circle(Color::BLUE, v6, -5);
	vector<Vector2D> listeV2;
	listeV2.push_back(v4);
	listeV2.push_back(v5);
	listeV2.push_back(v6);
	Shape* s6 = new Triangle(Color::BLUE, listeV2);
	G2->addShape(s4);
	G2->addShape(s5);
	G2->addShape(s6);

	Group* G3 = new Group(Color::CYAN);
	Vector2D v7(-10, -10), v8(-20, -20);
	Shape* s8 = new Segment(Color::BLACK, v7, v8);
	Shape* s9 = new Circle(Color::BLACK, v7, 15);
	G3->addShape(s8);
	G3->addShape(s9);

	G2->addGroup(G3);

	//G3->setColorIfGrouped(Color::YELLOW);
	cout << *G3 << endl;
	cout << G3->getColorIfGrouped() << endl << s8->getColorIfGrouped() << endl;
	//G2->removeGroup(G3);
	//cout << *G3 << endl;
	//cout << s8->getFatherColor() << endl << s8->getColorIfGrouped();
	G3->setShapeColor(Color::YELLOW);
	cout << *G3 << endl;
	cout << s8->getColorIfGrouped() << endl;
	G2->removeGroup(G3);
	cout << *G3 << endl;
	cout << s8->getColorIfGrouped() << endl;

	/*G1->removeGroup(G2);
	cout << " G1 = " << endl;
	cout << *G1 << endl << endl << endl;
	cout << " G2 = " << endl;
	cout << *G2 << endl << endl << endl;

	G2->removeGroup(G3);
	cout << " G2 = " << endl;
	cout << *G2 << endl << endl << endl;
	cout << " G3 = " << endl;
	cout << *G3 << endl << endl << endl;*/

	ShapesManager sm = ShapesManager();
	sm.addGroup(G3);
	sm.addGroup(G1);
	sm.addGroup(G2);

	ShapeManagerVisitor* saveTxt;
	saveTxt = new SaveInText;
	ShapeManagerVisitor* loadTxt;
	loadTxt = new LoadWithText;


	sm.accepte(saveTxt);

	sm.clean();

	sm.accepte(loadTxt);

	cout << endl << sm << endl << endl;

	ServerConnection* client;
	client = ServerConnection::getInstance();
	//client->openConnection();

	ShapeManagerVisitor* drawWithJavaServer;
	drawWithJavaServer = new DrawServerVisitor;


	//cout << sm << endl;
	//sm.accepte(drawWithJavaServer);
}