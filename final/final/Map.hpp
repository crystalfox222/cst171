//
//  Map.hpp
//  cst171_game
//
//  Created by Paul Bible on 3/13/19.
//  Copyright © 2019 Paul Bible. All rights reserved.
//
#ifndef Map_h
#define Map_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include "Position.hpp"


class Map{
public:
    // default constructor
    Map(){
        numR = 30;
        numC = 50;
        
        // create the map
        map_data = std::vector<std::string>();
        
        // create a simple open map
        for(int i = 0; i < numR; i++){
            std::string s(numC,' ');
            for(int j = 0; j < numC; j++){
                // draw '#'-walls around the edges
                if(i == 0 || j == 0 || j == numC - 1 || i == numR - 1){
                    s[j] = '#';
                }
            }
            map_data.push_back(s);
        }
    }
    
    // Map file constructor
    Map(std::string filename){
        // create the map
        map_data = std::vector<std::string>();
        
        std::fstream in(filename);
        
        if(in){
            // use a counter variable for the row.
            int r = 0;
            std::string line;
            while(in.good()){
                
                //get the line and add it to the map
                getline(in, line);
				if (line.size() > 0) {
					map_data.push_back(line);
					// increase counter variable
					r++;
				}
            }
            // Rows = number of lines added
            numR = static_cast<int>(map_data.size());
            // Cols = length of first line
            numC = static_cast<int>(map_data[0].size());
        }else{
            std::cout << "Hmm ... Looks like the file could not be found." << std::endl;
            throw std::exception();
        }
    }
    
    void print(){
        for(int i = 0; i < numR; i++){
            std::cout << map_data.at(i) << std::endl;
        }
    }
    
    char tileAt(int r, int c){
        return map_data[r][c];
    }
    
    char tileAt(Position p){
        return tileAt(p.getRow(), p.getCol());
    }
    
    int nRows(){
        return numR;
    }
    
    int nCols(){
        return numC;
    }
    
private:
    std::vector<std::string> map_data;
    int numR;
    int numC;
};
#endif /* Map_h */

























