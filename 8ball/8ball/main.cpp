#include <iostream>
#include "CST171.hpp"
#include "dice.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

void printPrompt() {
	cout << "Options" << endl;
	cout << "a. " << "Traditional 8ball" << endl;
	cout << "b. " << "Wack 8ball" << endl;
	cout << "c." << "exit" << endl;
	char choice = cst::getChar();

}

char choice;


void print8ballMessage() {
	dice d6 = dice();
	cout << d6.roll() << endl;
	int inRoll = d6.roll();
	dice die6 = dice();
	int roll = die6.roll();

	switch (roll) {

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

	default:
		cout << "bug" << endl;
		break;
	}
	
}

void printDef8ballMessage() {
	dice d6 = dice();
	cout << d6.roll() << endl;
	int inRoll = d6.roll();
	dice die6 = dice();
	int roll = die6.roll();

	switch (roll) {

	case 1:
		cout << "your parents hate you" << endl;
		break;
	case 2:
		cout << "you're not adopted" << endl;
		break;
	case 3:
		cout << "nah" << endl;
		break;
	case 4:
		cout << "yuh" << endl;
		break;
	case 5:
		cout << "not possible" << endl;
		break;
	case 6:
		cout << "not unlikely" << endl;
		break;

	default:
		cout << "bug" << endl;
		break;
	}
}

	int main(){
		srand(time(0));
		bool keepPlaying = true;
		while (keepPlaying) {
			printPrompt();

			while (choice != 'a' && choice != 'b'&& choice != 'c') {
				cout << "Invalid" << endl;
				printPromt();
				char choice;
			}


			if (choice == 'a') {
				print8ballMessage();

			}
			if(choice == 'b') {
				printDef8ballMessage();
			}
			else {
				return 0;
			}
			cst::pause();

		}

		cst::pause();

	
	return 0;
}