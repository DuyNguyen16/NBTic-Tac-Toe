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
public:
    int play();
    void show();

};

// Implementation of the show function
// void NBGame::show() {
//     // Access grid[0][0]
//     TicTacToe* firstBoard = &nb.getGrid()[0]; // Access the first TicTacToe board
//     TicTacToe* forthboard = &nb.getGrid()[4]; // Access the first TicTacToe board

//     // Update the position [0][0] on this board to 1
//     firstBoard->addMove(0, 0, 1);
//     forthboard->addMove(0,0, -1);
// };



int NBGame::play() {
    // db.displayBoards(0,0); // Initial board
    // show(); // update the move
    // db.displayBoardsRow(0, 0, 0);

    DisplayBoards db(&nb);

    TicTacToe* board0 = &nb.getGrid()[0];
    TicTacToe* board1 = &nb.getGrid()[1];
    TicTacToe* board2 = &nb.getGrid()[2];
    TicTacToe* board3 = &nb.getGrid()[3];
    TicTacToe* board4 = &nb.getGrid()[4];
    TicTacToe* board5 = &nb.getGrid()[5];
    TicTacToe* board6 = &nb.getGrid()[6];
    TicTacToe* board7 = &nb.getGrid()[7];
    TicTacToe* board8 = &nb.getGrid()[8];

    board0->addMove(0, 0, 1);
    board1->addMove(1, 1, -1);
    board2->addMove(0, 1, 1);
    board3->addMove(2, 2, 1);
    board4->addMove(1, 1, 1);
    board5->addMove(0, 0, -1);

    board6->addMove(2, 0, -1);
    board7->addMove(2, 1, 1);
    board8->addMove(1, 2, -1);

    db.displayBoards(0,0);




    return 0;
};


#endif