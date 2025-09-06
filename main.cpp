#include <iostream>
#include <new>
#include "Board.h"
using namespace std;


int main(){
    cout<<"Welcome to chess"<<endl;
    bool current_user_color;
    cout<<"Choose your piece, 1 for White and 0 for Black"<<endl;
    cin>>current_user_color;
    bool current_turn_is_white = true; // 1st move always for white
    Board* board = new Board();
    board->displayBoard();
    while(true){
        string player_color = current_turn_is_white ? "White" : "Black";
        cout<<player_color<<"'s turn to move"<<endl;
        cout<<"Please enter your move. (example: a2->a3, e2->e4, etc.)"<<endl;
        string moveInput;
        cin>>moveInput;
        if(moveInput.length() != 6){
            cout<<"this is an invalid move. Please try again."<<endl;
            continue;
        }
        int start_col = std::tolower(moveInput[0]) - 'a';
        int start_row = 7 - (moveInput[1] - '0' - 1);
        int end_col = std::tolower(moveInput[4]) - 'a';
        int end_row = 7 - (moveInput[5] - '0' - 1);
        if(board->makeMove(start_row, start_col, end_row, end_col, current_turn_is_white)){
            cout<<"That's an illegal move. Please try again"<<endl;
            cout<<"Move successfull"<<endl;
            current_turn_is_white = !current_turn_is_white;
        }   
        board->displayBoard();
    }

    cout<<endl;
    delete board;
    return 0;
}