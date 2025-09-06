#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
class Queen : public Piece{
    public:
    Queen(bool is_white, int x, int y) : Piece(is_white, x, y){}
    bool canMove(int startx, int starty, int endx, int endy){
        int diffx = abs(endx-startx);
        int diffy = abs(endy-starty);

        return ((startx == endx) ^ (starty == endy)) || (diffx == diffy);
    }
    char getSymbol(){
        return is_white ? 'Q' : 'q';
    }
};
#endif