#ifndef NBGame_H_
#define NBGame_H_

#include "NBTicTacToe.h"
#include "TicTacToe.h"
#include "DisplayBoards.h"
#include "GetMove.h"
#include "GameManagement.h"
#include "Player.h"


using namespace std;


class NBGame
{
private:
    NBTicTacToe nb;
public:
    int play();

};


int NBGame::play() {
    // db.displayBoards(0,0); // Initial board
    // show(); // update the move
    // db.displayBoardsRow(0, 0, 0);

    DisplayBoards db(&nb);
    GameManagement game;

    TicTacToe* board = &nb.getGrid()[-1];
    TicTacToe* board0 = &nb.getGrid()[0];
    TicTacToe* board1 = &nb.getGrid()[1];
    TicTacToe* board2 = &nb.getGrid()[2];
    TicTacToe* board3 = &nb.getGrid()[3];
    TicTacToe* board4 = &nb.getGrid()[4];
    TicTacToe* board5 = &nb.getGrid()[5];
    TicTacToe* board6 = &nb.getGrid()[6];
    TicTacToe* board7 = &nb.getGrid()[7];
    TicTacToe* board8 = &nb.getGrid()[8];


    Player playerX(1);
    Player playerO(-1);


    db.displayBoards(0,0);
    // cout << (board->getBoard()[0]);

    
    int x, y;
    playerX.getMove(x, y, board0);
    board0->addMove(x,y, 1);


    cout << board0->getNoOfMoves();


    

    
    
    
    




    return 0;
};


#endif