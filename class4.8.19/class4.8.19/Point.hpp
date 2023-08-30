#include <cmath>

class Point {
public:
	// constructor
	Point(float inX, float inY){
		x = inX;
		y = inY;
	}

	// accessor
	float getX() {
		return x;
	}

	float getY() {
		return y;
	}

	//square root or distance
	float distanceTo(Point destination) {
		float d = std::sqrt( std::pow(destination.getX() - x,2) 
			               + std::pow(destination.getY() - y,2));
		return d;
	}

private:
	float x;
	float y;
};
