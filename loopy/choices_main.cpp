/*
	CST 171
	Choices with nested if-statements
*/
#include <iostream>
#include <string>
#include "CST171.hpp"

using namespace std;

/*
	A function to greet someone.
*/
void greet(string inputName) {
	cout << "Welcome " << inputName << ", to your own adventure!" << endl;
	cout << endl;
}

/*
	A function to display text. This function prints the first part of a story.
*/
void printSceneSetup() {
	// break the lines up to make it easier to read.
	cout << "You have been walking for hours searching for your friend";
	cout << " on an Indianapolis street." << endl;
	cout << "To escape the freezing weather and rest your exhausted feet,";
	cout << " you duck into a small shop." << endl;
	// use the escape character to display quotes and apostrophes apostrophes
	cout << "The sign on the storefront reads \"Dr. Bible\'s Mysterious Objects\"." << endl;
	cout << "The shop is quaint and dusty." << endl;
}


/*
	The main function. The logic of your program should be here.
*/
int main() {

	// Have the user enter their name.
	string name = cst::getText("Please enter your name.");

	// Output a little visible separator
	cout << endl;
	cout << "__________" << endl;

	// Call the greet function to greet the user.
	greet(name);

	// Display some text to set the mood.
	printSceneSetup();

	// Prompt the user to take some action.
	cout << ">>What do you do?" << endl;
	cout << "Choose an action by typing a letter, then press enter." << endl;
	cout << "x) Explore the shop." << endl;
	cout << "l) Look for the shop owner." << endl;
	cout << "e) Exit the shop" << endl;
	// create a variable to store your choice.
	char choice;
	// get the user's choice
	choice = cst::getChar();

	if (choice == 'x') {
		cout << "You explore the shop and find a mysterious box." << endl;
		cout << "A sign on top that says \"Do not open!\"." << endl;
		cout << ">>What do you do?" << endl;
		cout << "Choose an action by typing a letter, then press enter." << endl;
		cout << "o) Open the box." << endl;
		cout << "l) Look for the shop owner. Ignore the box." << endl;


		// write the next branches of the story.
		choice = cst::getChar();
	}
		//TAG-1
		// if ...
		if (choice == 'o') {
			cout << "You open the box only to see what looks like a giant salt shaker. The heck?" << endl;
			cout << "all the sudden you hear is softly whisper 'exterminate' " << endl;
			cout << "You don't have time to react as a giant Dalek emerges from the box" << endl;
			cout << "Nice going dude. Shouldn't have opened the box" << endl;
			cout << "  " << endl;
			cout << "since you're dead, might as well explain. The dalek was one of Bible's projects." << endl;
			cout << "He was working on re-coding this particular dalek to exterminate rodents rather than humans." << endl;
			cout << "You probably wouldn't have died if you weren't such a pest." << endl;

			cst::pause();
			choice = cst::getChar();

		}

		if (choice == 'l') {
			cout << "You look through curtains of code, only to never find a strange man " << endl;
			cout << "He is wiring a strange salt shaker using... rust? "<< endl;
			cout << "Not just any rust. The language!" << endl;
			cout << "He explains to you that he is teaching this robot called a Dalek to kill bugs" << endl;
			cout << "he got the idea from their famous catch phrase 'exterminate'" << endl;

			//TAG-2
			// what happens when the shop owner is found?
			
			choice = cst::getChar();
			return 0;

		}
		else if (choice == 'e') {
			cout << "You exit the shop." << endl;
			cout << "Well, that was boring, and you are still cold." << endl;

			// this is a story end point. Pause and then exit .
			cst::pause();
			// returning from main exits the program.
			return 0;
		}
		//TAG-3, add a new piece to the story
		else {
			cout << "You rub your eyes and slowly realize you are at home in your bed." << endl;
			cout << "Or are you? This isn't your bed. It's a top bunk and you dont have bunks." << endl;
			cout << "You step out of bed only to find never ending amounts of hallways and rooms." << endl;
			cout << "all the sudden you walk into a funny man holding a..." << endl;
			cout << "SONIC SCREWDRIVER??? And you're in a tardis????" << endl;
			cout << "plot twist: Dr. Bible is the 67th doctor even though timelords have 13 lives." << endl;
			cout << "I guess sometimes you have to ignore logic when rehashing a new season every year makes bank." << endl;
		}

		cst::pause();
		return 0;
	
}
