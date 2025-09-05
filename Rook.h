#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece{
    public:
    Rook(bool is_white, int x, int y) : Piece(is_white, x, y) {}

    bool canMove (int startx, int starty, int endx, int endy){
        return (startx == endx) ^ (starty == endy);
    }
    char getSymbol(){
        return is_white ? 'R' : 'r';
    }
};
#endif