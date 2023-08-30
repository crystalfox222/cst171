#pragma once
#include <cstdlib>

using namespace std;


class dice {
public:

	dice() {
		sides = 6;
	}
	dice(unsigned int s) {
		sides = s;

	}

	int roll() {

		return (rand() % sides) + 1;

	}

	void caseFunction(){
		switch (sides) {

		case 1:
			cout << "your parents love you" << endl;
			break;
		case 2:
			cout << "you're adopted" << endl;
			break;
		case 3:
			cout << " yes" << endl;
			break;
		case 4:
			cout << "no" << endl;
			break;
		case 5:
			cout << "possibly" << endl;
			break;
		case 6:
			cout << "unlikely" << endl;
			break;

		}

}

	void setSides(unsigned int s) {
		sides = s;


	}

	int getSides() {
		return sides;
	}

private:
	unsigned int sides;
};