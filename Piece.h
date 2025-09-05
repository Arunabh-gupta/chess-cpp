#ifndef PIECE_H
#define PIECE_H

#include "utility"
#include <string>
using namespace std;
class Piece{
    public: 
    Piece(char name, bool is_white, int x, int y) :name(name), is_white(is_white), position_({x, y}) {};


    // destructor is not yet added just to see what happens if it's not present
    virtual bool canMove(int startx, int starty, int endx, int endy) = 0;
    virtual char getSymbol() = 0;
    virtual bool getIsWhite() = 0;
    protected:
    pair<int, int> position_;
    bool is_white;
    char name;
};

#endif