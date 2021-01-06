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

	Shape* s1;
	vector<Vector2D> listVector;
	Vector2D v1(1, 1);
	Vector2D v2(2, 3);
	Vector2D v3(3, 3);
	Vector2D v4(1, -2);
	listVector.push_back(v1);
	listVector.push_back(v2);
	listVector.push_back(v3);
	listVector.push_back(v4);
	s1 = new ConvexPolygon("orange", listVector);
	Shape* s2;
	s2 = new Triangle("pink", 1, 2, 3, 0, 5, 9);

	
	Group *s3 = new Group("green");
	
	Shape* s4, * s5;
	s4 = new Segment(1, 4, 8, 9);
	s5 = new Circle("Purple", 4, 9, 8);

	s3->addShape(s4);
	s3->addShape(s5);
	ServerConnection* client;
	client = ServerConnection::getInstance();
	client->openConnection();

	ShapeManagerVisitor* drawWithJavaServer;
	drawWithJavaServer = new DrawServerVisitor;

	ShapesManager * sm;
	sm = new ShapesManager();
	sm->addGroup(s3);
	sm->addShape(s1);
	sm->addShape(s2);
	
	//cout << endl << *sm << endl << endl;
	
	sm->save("save1.txt");

	sm->clean();

	sm->load("save1.txt");

	//cout << endl << *sm << endl << endl;

	sm->accepte(drawWithJavaServer);


	//client->closeConnection(); commenté pour eviter que le serveur java ecoute en boucle le port utilisé 

}