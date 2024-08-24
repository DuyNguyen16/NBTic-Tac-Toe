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
    nineBoard.getRandomFocusBoard(x, y);
    displayBoards.displayBoards(x,y);

    // cout << board0->getNoOfMoves();
    // player turn
    int playerTurn = 1;

    while (true) {
        // player moves
        int playerMoveX;
        int playerMoveY;

        // display the player turn
        if (playerTurn == 1 ) {
            computerPlayer.displayTurn();
        } else {
            humanPlayer.displayTurn();
        }

        // calculate the current board position
        int boardPosition = (3 * nineBoard.getCurrentMoveX()) + nineBoard.getCurrentMoveY();

        // get the board
        TicTacToe* board = &nineBoard.getGrid()[boardPosition];
        
        // get the player move
        if (playerTurn == 1) {
            // get computer move and add it to board
            computerPlayer.findBestMove(board);
            playerMoveX = computerPlayer.getBestMoveX();
            playerMoveY = computerPlayer.getBestMoveY();
            board->addMove(playerMoveX, playerMoveY, computerPlayer.getPlayerNumber());
        } else {
            // get Human move and add it to board
            humanPlayer.getMove(playerMoveX, playerMoveY, board);
            board->addMove(playerMoveX, playerMoveY, humanPlayer.getPlayerNumber());
        }
        
        // increment the total moves of all boards
        nineBoard.incrementTotalNoOfMoves();

        // check if the board is available
        int checkBoard = nineBoard.checkIfBoardAvailable(playerMoveX, playerMoveY);
        
        // check if the board is available
        if (checkBoard == 1) {
            // get random board
            nineBoard.getRandomFocusBoard(x, y);
        } else {
            // refocus the grid board to the player selected position on a board
            nineBoard.updateFocus(playerMoveX, playerMoveY);
        }

        // Display the new board 
        displayBoards.displayBoards(nineBoard.getCurrentMoveX(), nineBoard.getCurrentMoveY());

        // check the game status
        int gameStats = gameManagement.gameStatus(board);


        // exit the game if true
        if (gameStats != 0 || nineBoard.getTotalNumberOfMoves() >= 81) {
            return 0;
        }
        
        // swap the player turn
		if (playerTurn == 1)
			playerTurn = -1;
		else
		{
			playerTurn = 1;
		}
    }
    return 0;
};


#endif