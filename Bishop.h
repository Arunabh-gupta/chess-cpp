#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
    public:
    Bishop(char name, bool is_white, int x, int y) : Piece(name, is_white, x, y) {}
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