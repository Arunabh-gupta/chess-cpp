#ifndef PIECE_H
#define PIECE_H

#include "utility"
#include <string>
using namespace std;
class Piece{
    public: 
    Piece(bool is_white, int x, int y) : is_white(is_white), position_({x, y}) {};

    // destructor is not yet added just to see what happens if it's not present

    // canMove checks if it's a legal move for this piece or not
    virtual bool canMove(int startx, int starty, int endx, int endy) = 0;
    virtual char getSymbol() = 0;
    bool getIsWhite(){
        return is_white;
    }
    protected:
    pair<int, int> position_;
    bool is_white;
};

#endif