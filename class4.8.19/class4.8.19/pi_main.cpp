#include <iostream>
#include "Point.hpp"
#include "CST171.hpp"
#include <climits>
#include <cstdlib>

using namespace std;

Point randPoint() {
	float x = static_cast<float>(rand()) / RAND_MAX;
	float y = static_cast<float>(rand()) / RAND_MAX;
	return Point{ x, y };
}

int main() {

	int successes = 0;
	int tries = 0;
	Point origin{ 0, 0 };
	float pi = 0.0;
	
	while (tries < 10000) {
		//1 = r
		if (origin.distanceTo(randPoint()) <= 1.0) {
			successes++;
		}
		tries++;
	}
	float successesA = successes;
	float triesA = tries;
	pi = (successesA /(triesA/2))*2;

	
	//pi = some formula invovling successes and tries.
	cout << "final " << pi << endl;
	cst::pause();
}