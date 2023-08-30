//
//  Game.h
//  cst171_game
//
//  Created by Paul Bible on 3/26/19.
//  Copyright © 2019 Paul Bible. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <iostream>
#include "Map.hpp"
#include "Position.hpp"
#include "Player.hpp"
#include "ImageAscii.hpp"
#include "ChurchImage.h"

class Game {
public:
	// Create a game with a map
	Game(std::string map_file, std::string map_filetwo) {
		currentMap = Map(map_file);
		mapTwo = Map(map_filetwo);
		church = Church();
		player = Player(cst::getText());
		player.setPosition(Position(1, 1));
		churchPosition = Position(7, 12);
		dragonPosition = Position(1, 8);
		exitPosition = Position(1, 1);
		// http://ascii.co.uk/art
		dragonImage = ImageAscii("dragon.txt");
		keepPlaying = true;
	}

	// Check if the game is still going or we need to end it.
	bool isGameRunning() {
		return keepPlaying;
	}

	void printSpacer() {
		std::cout << "\n\n\n\n\n\n\n\n\n\n";
	}

	void printSpacer(int n) {
		for (int i = 0; i < n; i++) {
			std::cout << "\n";
		}
	}

	void printName(Player()) {


	}
	//starting the game off with info
	void startGame() {
		std::string n;
		std::cout << "hello! What is your name?" << std::endl;
		std::cin >> n;
		player.setName(n);
		std::cout << "Hello " << player.getName() << std::endl;
		std::cout << "Let me help you start the game with money!" << std::endl;
		player.setMoney(50);
		std::cout << "You have $" << player.getMoney() << std::endl;
	}

	// Draw the game map
	void draw() {
		if (gameMode == Mode::normal) {
			// print a spacer
			printSpacer();

			for (int r = 0; r < currentMap.nRows(); r++) {
				for (int c = 0; c < currentMap.nCols(); c++) {
					Position currentPosition = Position(r, c);
					if (currentPosition.equals(player.getPosition())) {
						std::cout << '@';
					}
					else if (currentPosition.equals(dragonPosition)) {
						std::cout << '&';
					}
					else if (currentPosition.equals(churchPosition)) {
						std::cout << '$';
					}
					else {
						std::cout << currentMap.tileAt(r, c);
					}
				}
				// at the end of all the columns, print a new line
				std::cout << std::endl;
			}
		}

		else if (gameMode == Mode::dragon) {
			printSpacer();
			dragonImage.draw();
		}
		// same map code but with new symbols
		else if (gameMode == Mode::church) {
			printSpacer();
			church.printImage();
			for (int r = 0; r < mapTwo.nRows(); r++) {
				for (int c = 0; c < mapTwo.nCols(); c++) {
					Position currentPosition = Position(r, c);
					if (currentPosition.equals(player.getPosition())) {
						std::cout << '@';
					}
					else if (currentPosition.equals(exitPosition)) {
						std::cout << '$';
					}
					else {
						std::cout << mapTwo.tileAt(r, c);
					}
				}
				// at the end of all the columns, print a new line
				std::cout << std::endl;
			}
		}

	}





	// a default menu
	void printMenuDefault() {
		std::cout << "w: move up" << std::endl;
		std::cout << "a: move left" << std::endl;
		std::cout << "s: move down" << std::endl;
		std::cout << "d: move right" << std::endl;
		std::cout << "!: quit the game" << std::endl;
	}

	void printMenuDragon() {
		std::cout << "Hello " << player.getName() << std::endl;
		std::cout << "The drogon flips a coin and asks you to choose:" << std::endl;
		std::cout << "h: Choose heads" << std::endl;
		std::cout << "t: Choose tails" << std::endl;
	}
	//menu
	void printMenuChurch() {
		std::cout << "Whoa, a church!" << std::endl;
		std::cout << "Lets go!" << std::endl;
		printMenuDefault();

	}

	void printGameOptions() {
		if (gameMode == Mode::normal) {
			//additions to menu
			std::cout << "Choose your next move:" << std::endl;
			std::cout << "Money: $" << player.getMoney() << std::endl;
			std::cout << "Name: " << player.getName() << std::endl;
			printMenuDefault();
		}
		else if (gameMode == Mode::dragon) {
			printMenuDragon();
		}
		//new menue
		else if (gameMode == Mode::church) {
			printMenuChurch();
		}

	}

	void startDragonEncounter() {
		gameMode = Mode::dragon;
		std::cout << "You have encountered a dragon!" << std::endl;
		cst::pause();
	}

	void processEvents() {
		if (player.getPosition().equals(dragonPosition)) {
			startDragonEncounter();
		}
	}

	//heckin leave
	int exit() {
		gameMode = Mode::exit;
		std::cout << "You win! Would you like to exit? y/n" << std::endl;
		char choice = 0;
		if (choice == 'y') {
			return 0;
		}
		else if (choice == 'n') {


		}
	}
	//so the player can heckin leave
	int processEventsE() {
		if (player.getPosition().equals(exitPosition)) {
			gameMode = Mode::exit;
			exit();
			return 0;
		}
	}
	//another event
	void processEventsC() {
		if (player.getPosition().equals(churchPosition)) {
			churchEvent();
		}
	}
	//it does the event
	void churchEvent() {
		gameMode = Mode::church;
		std::cout << "whoa" << std::endl;
	}
    
	void processChoice(char choice) {
		// have the game act oneway if the default menu is used
		if (gameMode == Mode::normal) {
			switch (choice) {
			case 'd':
				player.moveRight(currentMap);
				break;
			case 'a':
				player.moveLeft(currentMap);
				break;
			case 'w':
				player.moveUp(currentMap);
				break;
			case 's':
				player.moveDown(currentMap);
				break;
			case '!':
				keepPlaying = false;
				break;
			}
			// finally process any events
			processEvents();
			processEventsC();
		}
		else if (gameMode == Mode::dragon) {
			int flip = rand() % 2;
			switch (choice) {
			case 'h':
				if (flip == 0) {
					std::cout << "You guessed correctly! I will not eat you." << std::endl;
				}
				else {
					std::cout << "Incorrect! I will let you live ... for a small fee of $50" << std::endl;
					player.subMoney(50);
				}
				cst::pause();
				break;
			case 't':
				if (flip == 1) {
					std::cout << "You guessed correctly! I will not eat you." << std::endl;
				}
				else {
					std::cout << "Incorrect! I will let you live ... for a small fee of $50" << std::endl;
					player.subMoney(50);
				}
				cst::pause();
				break;
			}
			//set game mode back to normal.
			gameMode = Mode::normal;
		}
		// all the moves on a different map
		else if (gameMode == Mode::church) {
			switch (choice) {
			case 'd':
				player.moveRight(mapTwo);
				break;
			case 'a':
				player.moveLeft(mapTwo);
				break;
			case 'w':
				player.moveUp(mapTwo);
				break;
			case 's':
				player.moveDown(mapTwo);
				break;
			case '!':
				keepPlaying = false;
				break;
			}
			// finally process any events
			processEventsE();
		}
		//user exit
		else if (gameMode == Mode::exit) {
			processEventsE();
		}

	}

private:
	enum class Mode{normal, dragon, church, exit};
    Map currentMap;
	Map mapTwo;
	Mode gameMode = Mode::normal;
	Player player;
	Church church;
    Position playerPosition;
    Position dragonPosition;
	Position churchPosition;
	Position exitPosition;
	ImageAscii dragonImage;
	ImageAscii churchImage;
    bool keepPlaying;
};

#endif /* Game_h */
