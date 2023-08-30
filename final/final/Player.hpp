#include <iostream>
#include <string>
#include "Position.hpp"
#include "Map.hpp"
#include "CST171.hpp"

class Player {
public:
	Player() {
		pos = Position(0, 0);
	}
	
	Player(std::string name){
		playerName = name;
	}

	void moveRight(Map &map) {
		// check if there is a wall
		if (map.tileAt(pos.neighborRight()) != '#') {
			// update the player's position
			setPosition(pos.neighborRight());
		}
	}

	void moveLeft(Map &map) {
		// check if there is a wall
		if (map.tileAt(pos.neighborLeft()) != '#') {
			// update the player's position
			setPosition(pos.neighborLeft());
		}
	}

	void moveUp(Map &map) {
		// check if there is a wall
		if (map.tileAt(pos.neighborUp()) != '#') {
			// update the player's position
			setPosition(pos.neighborUp());
		}
	}

	void moveDown(Map &map) {
		// check if there is a wall
		if (map.tileAt(pos.neighborDown()) != '#') {
			// update the player's position
			setPosition(pos.neighborDown());
		}
	}


	std::string getName() {
		return playerName;
	}

	void setName(std::string name) {
		playerName = name;
	}

	Position getPosition() {
		return pos;
	}

	void setPosition(Position newPosition) {
		pos = newPosition;
	}
	//monies
	void setMoney(float M) {
		Money = 0;
		Money = M;
	}
	//retrieve monies
	float getMoney() {
		return Money;
	}
	//for the fee
	float subMoney(float z) {
		Money = Money - z;
		return Money;
	}


private:
	std::string playerName;
	Position pos;
	//new player feature
	float Money;
};
