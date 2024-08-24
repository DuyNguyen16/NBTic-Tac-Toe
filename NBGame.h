#ifndef NBGame_H_
#define NBGame_H_

#include "NBTicTacToe.h"
#include "TicTacToe.h"
#include "DisplayBoards.h"
#include "GameManagement.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "GameStatus.h"


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
    GameStatus gameStatus;


    Player playerX(1);
    Player playerO(-1);

    // cout << (board->getBoard()[0]);

    int x, y;
    // playerX.getMove(x, y, board0);
    // board0->addMove(x,y, 1);
    game.startGame();
    nb.getFocusBoard(x, y);
    db.displayBoards(x,y);

    // cout << board0->getNoOfMoves();
    int turn = 1;
    int done = 0;
    while (done == 0) {
        int playerMoveX;
        int playerMoveY;

        if (turn == 1 ) {
            playerX.displayTurn(1);
        } else {
            playerO.displayTurn(-1);
        }


        int calCurrentPos = (3 * nb.getCurrentMoveX()) + nb.getCurrentMoveY();

        TicTacToe* board = &nb.getGrid()[calCurrentPos];

        if (turn == 1) {
            playerX.getMove(playerMoveX, playerMoveY, board);
            board->addMove(playerMoveX, playerMoveY, 1);
        } else {
            playerO.getMove(playerMoveX, playerMoveY, board);
            board->addMove(playerMoveX, playerMoveY, -1);
        }
        
        nb.incrementTotalNoOfMoves();
        nb.updateFocus(playerMoveX, playerMoveY);

        db.displayBoards(nb.getCurrentMoveX(), nb.getCurrentMoveY());

        int gameStats = gameStatus.gameStatus(board);
        

        if (gameStats != 0 || nb.getTotalNumberOfMoves() >= 81) {
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