#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
class Knight : public Piece{
    public:
    Knight(bool is_white, int x, int y) : Piece(is_white, x, y){}
    bool canMove(int startx, int starty, int endx, int endy){
        int diffx = abs(startx-endx);
        int diffy = abs(starty-endy);
        return (diffx == 2 && diffy == 1) || (diffx == 1 && diffy == 2);
    }
    char getSymbol(){
        return is_white ? 'K' : 'k';
    }
};  
#endif