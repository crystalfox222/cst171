#pragma once

class point {

public:
	//constructor 
	point(float inx, float iny) {
		x = inx;
		y = iny;
 }


	//accessor
	float getx() {
		return x;
	}

	float gety() {
		return y;
	}


	// squareroot or distance
	float distanceTo(point destination) {
		float d = std::sqrt(pow(destination.getx() - y,2) + pow(destination.gety()-y,2));

		return d;
	}



private :
	float x;
	float y;

	

};