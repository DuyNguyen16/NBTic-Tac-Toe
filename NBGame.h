#ifndef NBGame_H_
#define NBGame_H_

#include "NBTicTacToe.h"
#include "TicTacToe.h"
#include "DisplayBoards.h"
#include "GameManagement.h"
#include "PlayersFolder/Player.h" 
#include "PlayersFolder/HumanPlayer.h"
#include "PlayersFolder/ComputerPlayer.h"


using namespace std;


class NBGame
{
private:
    NBTicTacToe nineBoard;
    GameManagement gameManagement;
public:
    int play();

};


int NBGame::play() {
    DisplayBoards displayBoards(&nineBoard);
    
    HumanPlayer humanPlayer(-1);
    ComputerPlayer computerPlayer(1);
    

    // cout << (board->getBoard()[0]);

    int x, y;
    // playerX.getMove(x, y, board0);
    // board0->addMove(x,y, 1);
    gameManagement.startGame();
    nineBoard.getFocusBoard(x, y);
    displayBoards.displayBoards(x,y);

    // cout << board0->getNoOfMoves();
    int turn = 1;
    int done = 0;
    while (done == 0) {
        int playerMoveX;
        int playerMoveY;

        if (turn == 1 ) {
            humanPlayer.displayTurn(1);
        } else {
            computerPlayer.displayTurn(-1);
        }


        int calCurrentPos = (3 * nineBoard.getCurrentMoveX()) + nineBoard.getCurrentMoveY();

        TicTacToe* board = &nineBoard.getGrid()[calCurrentPos];

        if (turn == 1) {
            humanPlayer.getMove(playerMoveX, playerMoveY, board);
            board->addMove(playerMoveX, playerMoveY, 1);
        } else {
            computerPlayer.getMove(playerMoveX, playerMoveY, board);
            board->addMove(playerMoveX, playerMoveY, -1);
        }
        
        nineBoard.incrementTotalNoOfMoves();
        nineBoard.updateFocus(playerMoveX, playerMoveY);

        displayBoards.displayBoards(nineBoard.getCurrentMoveX(), nineBoard.getCurrentMoveY());

        int gameStats = gameManagement.gameStatus(board);
        

        if (gameStats != 0 || nineBoard.getTotalNumberOfMoves() >= 81) {
            return 0;
        }


        
		if (turn == 1)
			turn = -1;
		else
		{
			turn = 1;
		}
    }
    
    
    
    




    return 0;
};


#endif