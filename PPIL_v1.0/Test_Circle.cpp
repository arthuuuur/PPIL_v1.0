#include "Circle.h"
#include "Vector2D.h"
#include "Shape.h"

int main() {

	Vector2D v1(3, 9);
	Shape * s1 = new Circle(Color::BLUE, v1, 4.5);
	cout << *s1 << endl;
	cout << s1->getGravity() << endl; // (3,9)
	cout << s1->getArea() << endl; // 63.62 find with geogebra
}