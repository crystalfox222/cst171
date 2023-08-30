#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>

#ifndef ImageAscii_h
#define ImageAscii_h

class ImageAscii {
public:
	ImageAscii() {
		image = std::vector<std::string>();
		maxWidth = 0;
	}


	ImageAscii(std::string filename) {
		// create the map
		image = std::vector<std::string>();

		std::fstream in(filename);

		maxWidth = 0;

		if (in) {
			// use a counter variable for the row.
			int r = 0;
			std::string line;
			while (in.good()) {

				//get the line and add it to the map
				getline(in, line);
				if (line.size() > 0) {
					image.push_back(line);
					if (line.size() > maxWidth) {
						maxWidth = line.size();
					}
					// increase counter variable
					r++;
				}
			}
		}
		else {
			std::cout << "Hmm ... Looks like the file could not be found." << std::endl;
			throw std::exception();
		}
	}

	int getMaxWidth() {
		return maxWidth;
	}

	int getRowHeight() {
		return image.size();
	}

	void draw(int r) {
		std::string line = image.at(r);
		std::cout << line;
		if (line.size() < maxWidth) {
			int diff = maxWidth - line.size();
			for (int i = 0; i < diff; i++) {
				std::cout << " ";
			}
		}
	}

	void drawln(int r) {
		draw(r);
		std::cout << std::endl;
	}

	void draw() {
		for (int r = 0; r < image.size(); r++) {
			drawln(r);
		}
	}

private:
	std::vector<std::string> image;
	int maxWidth;
};
#endif
