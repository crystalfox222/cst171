#pragma once
#include <iostream>

using namespace std;


class Number {
public:

	Number(float v, float c) {

		value = v;
		complex = c;
	}

	 Number() {
		value = 0;
		complex = 0;
	}
	void print() {
		cout << value << " " << complex<< i <<  endl;
	}
	
	Number add(Number a) {
		 
		float c = a.value + value;
		float d = a.complex + complex;
		return Number(c, d);
	}

	Number sub(Number a) {
		float c = a.value - value;
		float d = a.complex - complex;
		return Number(c, d);
	}

	Number foil(Number a) {
		float f = a.value*value;
		float b = a.value*complex;
		float c = a.complex*complex;
		float d = a.complex*value;
		float e = b + d;
		c = c * -1;
		float z = c + f;
		return Number(z, e);
	}

private:
	float value;
	float complex;
	char i = i;
};