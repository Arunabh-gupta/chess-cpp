#ifndef BOARD_H
#define BOARD_H

#include "Rook.h"
#include "Bishop.h"
#include <iostream>
using namespace std;

class Board {
    private: 
    bool isPathClear(int startx, int starty, int endx, int endy, const Piece* piece);
    public:
    Piece* board[8][8];
    Board(){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                board[i][j] = nullptr;
            }
        }
        // placing all the rooks
        board[0][0] = new Rook(true, 0, 0);
        board[0][7] = new Rook(true, 0, 7);
        board[7][0] = new Rook(false, 7, 0);
        board[7][7] = new Rook(false, 7, 7);

        // placing the bishops
        board[0][2] = new Bishop(true, 0, 2);
        board[0][5] = new Bishop(true, 0, 5);
        board[7][2] = new Bishop(false, 7, 2);
        board[7][5] = new Bishop(false, 7, 5);
    }

    ~Board() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete board[i][j];
            }
        }
    }

void displayBoard() {
    // Print column labels
    std::cout << "  A B C D E F G H" << std::endl;
    std::cout << " +-----------------+" << std::endl;

    for (int i = 0; i < 8; i++) {
        // Print row label (8 down to 1)
        std::cout << 8 - i << "|";

        for (int j = 0; j < 8; j++) {
            // Check if a piece exists at the current position
            if (board[i][j] != nullptr) {
                // Get the symbol from the piece object
                std::cout << board[i][j]->getSymbol() << " ";
            } else {
                // If the square is empty, print a placeholder
                std::cout << ". ";
            }
        }
        // Print row label again for easy viewing
        std::cout << "| " << 8 - i << std::endl;
    }
    std::cout << " +-----------------+" << std::endl;
    std::cout << "  A B C D E F G H" << std::endl;
}
    
bool makeMove(int startx, int starty, int endx, int endy, bool turn){
        if(startx<0 || startx>7 || starty<0 || starty>7 || endx<0 || endx>7 || endy<0 || endy>7){
            cout<<"Invalid Coordinates, please try again"<<"\n";
            return false; 
        }
        Piece* piece = board[startx][starty];
        if(piece == nullptr){
            cout<<"Empty square was selected, try some other square"<<"\n";
            return false;
        }
        if(turn != piece->getIsWhite()){
            cout<<"It's "<<(turn ? "White's" : "Black's")<<" move"<<endl;
            return false;
        }
        if(!piece->canMove(startx, starty, endx, endy)){
            cout<<"Current piece cannot move at the destination"<<"\n";
            return false;
        }

        if(!isPathClear(startx, starty, endx, endy, piece)){
            cout<<"That's an illegal move"<<endl;
            return false;
        }
        board[endx][endy] = piece;
        board[startx][starty] = nullptr;
        return true;
    }
};

bool Board::isPathClear(int startx, int starty, int endx, int endy, const Piece* piece){
    if(dynamic_cast<const Rook*>(piece)){
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
    }
    else if(dynamic_cast<const Bishop*>(piece)){
        
        int dx = endx > startx ? 1 : -1;
        int dy = endy > starty ? 1 : -1;

        int currx = startx+dx;
        int curry = starty+dy;
        while(currx != endx && curry != endy){
            if(board[currx][curry] != nullptr) return false;
            currx += dx;
            curry += dy;
        }
    }

    return true;
}
#endif