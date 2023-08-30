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


class Game{
public:
    
    // Create a game with a map
    Game(std::string map_file){
        currentMap = Map(map_file);
        menuMode = 0;
        playerPosition = Position(1, 1);
        dragonPosition = Position(1, 8);
		dragonMPosition = Position(7, 6);
        keepPlaying = true;
    }
    
    // Check if the game is still going or we need to end it.
    bool isGameRunning(){
        return keepPlaying;
    }
    
    // Draw the game map
    void draw(){
        // print a spacer
        std::cout << "\n\n\n\n\n\n\n\n\n\n";
        
        for(int r = 0; r < currentMap.nRows(); r++){
            for(int c = 0; c < currentMap.nCols(); c++){
                Position currentPosition = Position(r, c);
                if(currentPosition.equals(playerPosition)){
                    std::cout << '@';
				}
				else if (currentPosition.equals(dragonPosition)) {
					std::cout << '&';

				}
				else if (currentPosition.equals(dragonMPosition)) {
					std::cout << '%';
                }else{
                    std::cout << currentMap.tileAt(r,c);
                }
            }
            // at the end of all the columns, print a new line
            std::cout << std::endl;
        }
    }
    
    // a default menu
    void printMenuDefault(){
        std::cout << "w: move up" << std::endl;
        std::cout << "a: move left" << std::endl;
        std::cout << "s: move down" << std::endl;
        std::cout << "d: move right" << std::endl;
        std::cout << "!: quit the game" << std::endl;
    }
    
    void printGameOptions(){
        std::cout << "Choose your next move:" << std::endl;
        if(menuMode == 0){
            printMenuDefault();
        }
    }
    
    void playerMoveRight(){
        // check if there is a wall
        if(currentMap.tileAt(playerPosition.neighborRight()) != '#'){
            // update the player's position
            playerPosition = playerPosition.neighborRight();
        }
        processEvents();
		processEventsM();
    }
	void playerMoveLeft() {
		// check if there is a wall
		if (currentMap.tileAt(playerPosition.neighborLeft()) != '#') {
			// update the player's position
			playerPosition = playerPosition.neighborLeft();
		}
		processEvents();
		processEventsM();
	}
		void playerMoveUp() {
			// check if there is a wall
			if (currentMap.tileAt(playerPosition.neighborUp()) != '#') {
				// update the player's position
				playerPosition = playerPosition.neighborUp();
			}
			processEvents();
			processEventsM();
		}
		void playerMoveDown() {
			// check if there is a wall
			if (currentMap.tileAt(playerPosition.neighborDown()) != '#') {
				// update the player's position
				playerPosition = playerPosition.neighborDown();
			}
			processEvents();
			processEventsM();
		}

		
	
    
    void processEvents(){
        if(playerPosition.equals(dragonPosition)){
            std::cout << "You have encountered a dragon!" << std::endl;
			std::cout << "Pet him! (y/n)" << std::endl;
			char choice = 0;
			std::cin >> choice;
			cst::clean_input();
			if (choice == 'y') {
				std::cout << "The dragon adopts you. You are now his child. Happy birthday." << std::endl;
			}
			else if (choice == 'n') {
				std::cout << "You made the dragon sad." << std::endl;
			}
			else {

			}
            cst::pause();
            
        }
    }
	void processEventsM() {
		if (playerPosition.equals(dragonMPosition)) {
			std::cout << "You have encountered a dog!" << std::endl;
			std::cout << "Pet him! (y/n)" << std::endl;
			char choice = 0;
			std::cin >> choice;
			cst::clean_input();
			if (choice == 'y') {
				std::cout << "The dog had recieved your pets. What a good boy." << std::endl;
			}
			else if(choice == 'n') {
				std::cout << "You evil soul." << std::endl;
			}
			else{

			}
			cst::pause();

		}
	}
    void processChoice(char choice){
        // have the game act oneway if the default menu is used
        if(menuMode == 0){
            if(choice == 'd'){
                playerMoveRight();
			}
			else if (choice == 'w') {
				playerMoveUp();
			}
			else if (choice == 'a'){
				playerMoveLeft();  
            }
			else if (choice == 's') {
				playerMoveDown();
			}
			else if(choice == '!'){
                // signal the end of the game
                keepPlaying = false;
            }
        }
    }
    

private:
    Map currentMap;
    int menuMode = 0;
    Position playerPosition;
    Position dragonPosition;
	Position dragonMPosition;
    bool keepPlaying;

};


#endif /* Game_h */
