#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece{
    public:
    Rook(char name, bool is_white, int x, int y) : Piece(name, is_white, x, y) {}

    bool canMove (int startx, int starty, int endx, int endy){
        return (startx == endx) ^ (starty == endy);
    }
    char getSymbol(){
        return name;
    }
    bool getIsWhite(){
        return is_white;
    }
};
#endif