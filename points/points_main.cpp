#include <iostream>
#include <cmath>
#include "CST171.hpp"
#include "Point.hpp"

using namespace std;

// the Main Function
int main() {

	// create points for MU's facilities 
	point marianHall{ 3.4,5.6 };
	point library{ 3.17,3.15 };
	point fountain{ 2.78,4.32 };
	point evansCenter{ 3.4, 1.38 };
	point alumniHall{ 3.29, 3.65 };
	point footballField{ 1.16,1.4 };
	point baseballField{ 1.04,3.85 };
	point pysEd{1.23,5.82};
	point claireHall{ 2.06,5.55 };
	

	// Give some output text describing what is happening.
	// Marian Hall
	cout << "Marian university is a large campus with several facilities. " << endl;
	cout << "You can use this program to navigate campus from the fountain." << endl;
	// The library, output a different way (breaking up the output).


	cout << "The distance between Marian Hall and the Library is: ";
	//Calculate distance, and output
	//
	float d = marianHall.distanceTo(library);
	cout << d << endl;

	// Give the user a choice, to calculate a different distance
	char choice;
	// add some space, output a new line (endl).
	cout << endl;
	cout << "Choose (a) or (b)" << endl;
	cout << "(a) Go to Marian Hall." << endl;
	cout << "(b) Go to the Library ." << endl;
	choice = cst::getChar();

	// Use an if-statement to make a choice for what code to execute.
	if (choice == 'a') {
		cout << "The distance from the Fountain to Marian Hall is ";
		// calculate distance, Marian Hall (3.4, 5.6)
		//
		//distance = 
		float d = fountain.distanceTo(marianHall);
		cout << d << endl;
	
	}
	else if (choice == 'b') {
		cout << "The distance from the Fountain to the Library is ";
		// calculate distance, Library (3.17, 3.15)
		//
		float a = fountain.distanceTo(library);
		cout << a << endl;
	
	}
	else {
		cout << "You chose to stay put. Lazy." << endl;

		


	}

	//this makes it look cleaner
	cout << " " << endl;
	cout << "The perimeter of Marian University is: ";
	//Calculate distance several times, and output
	// a ton of calculations 

	float r = marianHall.distanceTo(alumniHall);
	float b = alumniHall.distanceTo(library);
	float c = library.distanceTo(evansCenter);
	float j = evansCenter.distanceTo(footballField);
	float e = footballField.distanceTo(baseballField);
	float f = baseballField.distanceTo(pysEd);
	float g = pysEd.distanceTo(claireHall);
	float h = claireHall.distanceTo(marianHall);

	//old calculations 
     // a = sqrt(pow(ahX - mhX, 2) + pow(ahY - mhY, 2));
	  //b = sqrt(pow(ahX - libX, 2) + pow(ahY - libY, 2));
	  //c = sqrt(pow(evaX - libX, 2) + pow(evaY - libY, 2));
	  //d = sqrt(pow(evaX - fbfX, 2) + pow(evaY - fbfY, 2));
	  //e = sqrt(pow(bbfX - fbfX, 2) + pow(bbfY - fbfY, 2));
	  //f = sqrt(pow(bbfX - pecX, 2) + pow(bbfY - pecY, 2));
	  //g = sqrt(pow(chX - pecX, 2) + pow(chY - pecY, 2));
	  //h = sqrt(pow(chX - mhX, 2) + pow(chY - mhY, 2));
	
	//final output
	float distance;
	distance = r + b + c + j + e + f + g + h;

	cout << distance << endl;




	// Pause the program. 
	cst::pause();
	return 0;

}