#ifndef BOARD_H
#define BOARD_H

#include "Rook.h"
#include "Bishop.h"
#include <iostream>
using namespace std;

class Board {
    public:
    Piece* board[8][8];
    Board(){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                board[i][j] = nullptr;
            }
        }
        // placing all the rooks
        board[0][0] = new Rook('R',true, 0, 0);
        board[0][7] = new Rook('R',true, 0, 7);
        board[7][0] = new Rook('R',false, 7, 0);
        board[7][7] = new Rook('R',false, 7, 7);
        board[0][2] = new Bishop('B', true, 0, 2);
        board[0][2] = new Bishop('B', true, 0, 5);
        board[0][2] = new Bishop('B', false, 7, 2);
        board[0][2] = new Bishop('B', false, 7, 5);
    }

    ~Board() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete board[i][j];
            }
        }
    }
    void displayBoard(){
        // char displayBoard[8][8];
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j] != nullptr){
                    if(board[i][j]->getIsWhite()) cout<<'W';
                    else cout<<'B';
                    cout<<board[i][j]->getSymbol();
                }
                else{
                    cout<<'.';
                }
            }
            cout<<"\n";
        }
    }
    bool makeMove(int startx, int starty, int endx, int endy){
        if(startx<0 || startx>7 || starty<0 || starty>7 || endx<0 || endx>7 || endy<0 || endy>7){
            cout<<"Invalid Coordinates, please try again"<<"\n";
            return false; 
        }
        Piece* piece = board[startx][starty];
        if(piece == nullptr){
            cout<<"Empty square was selected, try some other square"<<"\n";
            return false;
        }
        if(!piece->canMove(startx, starty, endx, endy)){
            cout<<"Current piece cannot move at the destination"<<"\n";
            return false;
        }

        if(startx == endx){
            int start = min(starty, endy)+1;
            int end = min(starty, endy);
            for(int i=start; i<=end; i++){
                if(board[startx][i] != nullptr){
                    cout<<"Path is blocked"<<"\n";
                    return false;
                }
            }
        }else{
            int start = min(startx, endx)+1;
            int end = min(startx, endx);
            for(int i=start; i<=end; i++){
                if(board[i][starty] != nullptr){
                    cout<<"Path is blocked"<<"\n";
                    return false;
                }
            }
        }

        board[endx][endy] = piece;
        board[startx][starty] = nullptr;
        return true;
    }
};

#endif