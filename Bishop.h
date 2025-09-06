#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
    public:
    Bishop(bool is_white, int x, int y) : Piece(is_white, x, y) {}
    bool canMove (int startx, int starty, int endx, int endy){
        int diffx = abs(endx-startx);
        int diffy = abs(endy-starty);
        return diffx == diffy;
    }
    char getSymbol(){
        return is_white ? 'B' : 'b';
    }
};
#endif