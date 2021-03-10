#define _USE_MATH_DEFINES // to get the constante M_PI with the <math.h> include
#include <math.h>

#include "Vector2D.h"

int main() {
	
	Vector2D v1(5, 2), v2(4, 1);
	cout << "v1 + v2 = " << v1 + v2 << endl; // (9,3)
	cout << "v1 - v2 = " << v1 - v2 << endl; // (1,1)

	Vector2D v3, v4;
	v3 = 0.5 * v1; 
	v4 = v1 * 0.5; 
	cout << "v3 = " << v3 << endl; // (2.5,1)
	cout << "v4 = " << v4 << endl; // (2.5,1)

	Vector2D v5;
	v5 = v2 / 2; 
	cout << "v5 = " << v5 << endl; // (2,0.5)

	Vector2D v6(5, 2);
	if (v6 == v1)
		cout << "v6 == v1" << endl;
	if (v6 != v2)
		cout << "v6 != v2" << endl;

	Vector2D v7 = -v6;
	cout << "v7 = " << v7 << endl;

	cout << "det v1 = " << v1.det(v2) << endl; // -3

	Vector2D v1T = v1.translation(v2);
	cout << "v1T = " << v1T << endl; // (9,3)

	Vector2D v1H = v1.homothety(-3,v2); // (1,-2)
	cout << "v1H = " << v1H << endl;

	Vector2D v1R = v1.rotation(M_PI / 2, v2); //(3,2)
	cout << "v1R = " << v1R << endl;

	return 0;
}