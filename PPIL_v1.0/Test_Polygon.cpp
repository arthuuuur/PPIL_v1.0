#include "Triangle.h"

int main() {
	
	Vector2D v1(1, 1), v2(-1, 5), v3(3, 9), v4(4, 10), v5(14, 3), v6(6, -5);
	vector<Vector2D> listeV;
	listeV.push_back(v1);
	listeV.push_back(v2);
	listeV.push_back(v3);
	listeV.push_back(v4);
	listeV.push_back(v5);
	listeV.push_back(v6);
	Shape* s1 = new ConvexPolygon(Color::YELLOW, listeV);
	cout << *s1 << endl;
	cout << s1->getArea() << endl; // 114.5 find with geogebra
	cout << s1->getGravity() << endl; // (5.93, 2.83) find with geogebra

	// Triangle
	Vector2D v7(-10, 5), v8(-1, -3), v9(-5, -2);
	Shape* s2 = new Triangle(v7, v8, v9);
	cout << *s2 << endl;
	cout << s2->getArea() << endl; // 11.5 find with geogebra
	cout << s2->getGravity() << endl; // (-5.33, 0) find with geogebra
}

