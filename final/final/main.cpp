//
//  main.cpp
//  cst171_game
//
//  Created by Paul Bible on 3/13/19.
//  Copyright © 2019 Paul Bible. All rights reserved.
//

#include <iostream>
#include "CST171.hpp"
#include "Map.hpp"
#include "Position.hpp"
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    Game game = Game("map.txt", "map2.txt");
	
    
    char choice;
	game.startGame();
    while(game.isGameRunning()){
		game.draw();
        game.printGameOptions();
        choice = cst::getChar();
        game.processChoice(choice);
    }
	
    
    
    return 0;
}
