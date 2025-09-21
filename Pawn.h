#ifndef PAWN_H
#define PAWN_H
#include "Piece.h" 

class Pawn : public Piece{
    public:
    Pawn(bool is_white, int x, int y) : Piece(is_white, x, y){};

    bool canMove(int startx, int starty, int endx, int endy){
        if(is_white && endy-starty == 1) return true;
        if(!is_white && starty-endy == 1) return true;

        if(endy-starty == 2 && starty == 1) return true;
        if(starty-endy == 2 && starty == 6) return true;

        int diffx = endx-startx;
        int diffy = endy-starty;
        if(is_white){
            if(abs(diffx) == 1 && diffy > 0) return true;
        }
        else{
            if(abs(diffx) == 1 && diffy < 0) return true;
        }
        return false;
    }
    char getSymbol(){
        return is_white ? 'P' : 'p';
    }
};

#endif