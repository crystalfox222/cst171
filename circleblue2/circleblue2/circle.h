#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Circle {
public:
	Circle(float r) {
		radius = r;
		pi = 3.14159;
	}
	Circle() {
		radius = 1;
		pi = 3.14159;
	}
	float calcArea() {
		float a = pi*radius*radius;
		return a;
	}
	float calcCirc() {
		float b = 2*pi*radius;
		return b;
	}
	void printR() {
		cout << "Circle with radius " << radius<< endl;
	}
	void printA() {
		cout << "Circle with Area " << calcArea() << endl;
	}
	void printC() {
		cout << "Circle with circumference " << calcCirc() << endl;
	}
	float getR() {
		return radius;
	}
	float setR(float r) {
		r = radius;
	}
	void printPrompt() {
		cout << "Options" << endl;
		cout << "a. " << "Continue circle values" << endl;
		cout << "b. " << "Exit" << endl;
		char choice;
		
		
	}
private:
	float radius;
	float pi;
};