#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include "Position.hpp"
#include "Game.hpp"
#include "ImageAscii.hpp"
#include "CST171.hpp"

class Church {

public:
	Church() {
		
	}
	//simple class just for this image
	void printImage() {
		ImageAscii churchImage = ImageAscii("church.txt");
		churchImage.draw();
	}


private:
	float church;
};