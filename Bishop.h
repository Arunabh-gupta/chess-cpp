#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
    public:
    Bishop(bool is_white, int x, int y) : Piece(is_white, x, y) {}
    bool canMove (int startx, int starty, int endx, int endy){
        return (startx == endx) ^ (starty == endy);
    }
    char getSymbol(){
        return is_white ? 'B' : 'b';
    }
};
#endif