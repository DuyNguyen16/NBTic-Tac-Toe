#ifndef NBGame_H_
#define NBGame_H_

#include "NBTicTacToe.h"
#include "TicTacToe.h"
#include "DisplayBoards.h"


using namespace std;


class NBGame
{
private:
    NBTicTacToe nb;
    DisplayBoards db;
    
public:
    int play();
    void show();

};

// Implementation of the show function
void NBGame::show() {
    // Access grid[0][0]
    TicTacToe* firstBoard = &nb.getGrid()[0]; // Access the first TicTacToe board
    TicTacToe* forthboard = &nb.getGrid()[4]; // Access the first TicTacToe board

    // Update the position [0][0] on this board to 1
    firstBoard->addMove(0, 0, 1);
    forthboard->addMove(0,0, -1);
};



int NBGame::play() {
    db.displayBoards(0,0); // Initial board
    show(); // update the move
    db.displayBoardsRow(0, 0, 0);
    

    return 0;
};


#endif