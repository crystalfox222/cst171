#include <iostream>
#include "complex.h"

using namespace std;

int main() {


	Number numberA(4,3);
	Number numberB(7, -2);
	Number numberC(2, 0);
	
	cout << "Values" << endl;
	numberA.print();
	numberB.print();
	cout << "Values multiplied by Scalar 2" << endl;
	numberA = numberA.foil(numberC);
	numberB = numberB.foil(numberC);
	numberA.print();
	numberB.print();
	cout << "Values squared" << endl;
	numberA = numberA.foil(numberA);
	numberB = numberB.foil(numberB);
	numberA.print();
	numberB.print();

	cin.get();

	return 0;


}