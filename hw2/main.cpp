/*
	CST 171
	A program to illustrate chaotic behavior (logistic map)
*/
#include <iostream>
#include "CST171.hpp"

// allow use of cout, cin, and endl
using namespace std;

// The Main Function
int main() {
	
	//declare a variable for use later.
	float x;
	float y;

	//promt the user to enter a value and get it from cin
	cout << "Enter a value between 0 and 1:" << endl;
	cin >> x;
	// clean the input, get rid of the extra '\n' in the input stream.
	cst::clean_input();

	//promt the user to enter a value and get it from cin
	cout << "Enter a value between 0 and 1:" << endl;
	cin >> y;
	// clean the input, get rid of the extra '\n' in the input stream.
	cst::clean_input();

	// add some text boarder to make the output clearer.   
	cout << "_____x____"; 
	cout << "_____y____" << endl;
	// Use a loop to repeat a piece of code 10 times.
	for (int i = 0; i < 10; i++) { 
	
		// calculate the value of x then output it.
		x = 3.9 * x * (1 - x);
		y = 3.9 * y * (1 - y);
		cout << i << " " << x << ' ';
		cout << " " << y << endl;

	}
	


	// hold the window until the user presses enter.
	cst::pause();
	return 0;
}
