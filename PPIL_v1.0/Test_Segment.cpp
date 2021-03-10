#include "Segment.h"

int main() {

	Vector2D v1(4, 8), v2(1, 2);
	Shape* s1 = new Segment(v1, v2);

	cout << *s1 << endl;
	cout << s1->getArea() << endl; // 0
	cout << s1->getGravity() << endl; // (2.5,5)

	return 0;
}