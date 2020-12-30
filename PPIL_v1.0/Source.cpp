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
	

	Group World("Blue");
	World.addShape(s1);
	World.addShape(s2);

	Group s3("green");
	Shape* s4, * s5;
	s4 = new Segment(1, 4, 8, 9);
	s5 = new Circle("Purple", 4, 9, 8);

	s3.addShape(s4);
	s3.addShape(s5);

	World.addGroup(s3);
	//cout << World << endl;

	ServerConnection* client;
	client = new  ServerConnection();
	client->openConnection();

	World.draw(client);

	//client->closeConnection(); en commentaire car sinon le serveur java tourne en boucle sur le port d'écoute 

}