#include <iostream>
#include "circle.h"
#include <cstdlib>


using namespace std;

int main() {


	Circle CircleA(7);
	char choice = 0;
	

	while (choice != 'a') {
		CircleA.printPrompt();
		cin >> choice;

		if (choice == 'a') {
			
		}
		else if (choice == 'b') {
			exit(0);
			
		}
		else {
			
			CircleA.printPrompt();
		}
	}

	CircleA.calcCirc();

	CircleA.calcArea();

	CircleA.printR();
	CircleA.printA();
	CircleA.printC();

	getchar();
	getchar();

	return 0;

}