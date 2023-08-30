//
//  Position.hpp
//  cst171_game
//
//  Created by Paul Bible on 3/26/19.
//  Copyright © 2019 Paul Bible. All rights reserved.
//

#ifndef Position_h
#define Position_h

#include <iostream>

class Position{
public:
    
    Position(){
        row = 0;
        col = 0;
    }
    
    Position(int r, int c){
        row = r;
        col = c;
    }
    
    int getRow(){
        return row;
    }
    
    int getCol(){
        return col;
    }
    
    bool equals(Position p){
        return p.getCol() == col && p.getRow() == row;
    }
    
    Position neighborUp(){
        return Position(row - 1, col);
    }
    
    Position neighborDown(){
        return Position(row + 1, col);
    }
    
    Position neighborLeft(){
        return Position(row, col - 1);
    }
    
    Position neighborRight(){
        return Position(row, col + 1);
    }
    
    void print(){
        std::cout << "[" << row << ", " << col << "]";
    }
    
    void println(){
        print();
        std::cout << std::endl;
    }
    
private:
    int row;
    int col;
};

#endif /* Position_h */
