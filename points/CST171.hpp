/** 
* CST171.hpp
* This header file collects some useful functions for C++.
*/
#pragma once
#include <iostream>
#include <string>
#include <limits>

/** The cst namespace. Make it obvious these are special functions.
*/
namespace cst {

	/** A function to get a single character from the user.
	*    This avoids the problem of having an extra '\n' in the input.
	*/
	char getChar() {
		std::string line;
		std::getline(std::cin, line);
		if (line.size() > 0) {
			return line[0];
		}
		else {
			return '\0';
		}
	}

	/** Output a message to the screen before getting a character.
	*/
	char getChar(std::string message) {
		std::cout << message << std::endl;
		return getChar();
	}

	/** A function line of text from the user.
	*    This avoids the problem of white space delimiters in cin.
	*/
	std::string getText() {
		std::string line;
		std::getline(std::cin, line);
		return line;
	}

	/** Output a message to the screen before getting text from the user.
	*/
	std::string getText(std::string message){
		std::cout << message << std::endl;
		return getText();
	}

	/** Clean the input, remove the extra newline.
	*/
	void clean_input() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/** This code was modified from the stack overflow answer
	*    https://stackoverflow.com/a/1909160
	*    Pause the execution of the program until Enter is pressed.
	*/
	void pause() {
		std::cout << "Press Enter to continue..." << std::endl;
		clean_input();
	}

	/** This code was modified from the stack overflow answer
	*    https://stackoverflow.com/a/1909160
	*    Pause the execution of the program until Enter is pressed.
	*/
	void pause(std::string message) {
		std::cout << message << std::endl;
		pause();
	}
}