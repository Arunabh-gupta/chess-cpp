#include <iostream>
#include <new>
#include "Board.h"
using namespace std;


int main(){
    Board* board = new Board();
    board->displayBoard();
    // while(true){
    // }

    cout<<endl;
    delete board;
    return 0;
}