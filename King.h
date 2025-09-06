#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
    public:
    King(bool is_white, int x, int y) : Piece(is_white, x, y){}

    bool canMove(int startx, int starty, int endx, int endy){
        return abs(startx-endx) == 1 || abs(starty-endy) == 1;
    }
    char getSymbol(){
        return is_white ? 'K' : 'k';
    }
};
#endif