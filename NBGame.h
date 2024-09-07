#ifndef NBGame_H_
#define NBGame_H_

#include "TicTacToeBoards/NBTicTacToe.h"
#include "TicTacToeBoards/TicTacToe.h"
#include "TicTacToeBoards/DisplayBoards.h"
#include "GameManagement.h"
#include "PlayersFolder/Player.h" 
#include "PlayersFolder/HumanPlayer.h"
#include "PlayersFolder/MinimaxPlayer.h"
#include "PlayersFolder/RandomPlayer.h"


using namespace std;


class NBGame
{
private:
    NBTicTacToe nineBoard;
    GameManagement gameManagement;
    Player* players[2];
public:
    
    int play();

};


int NBGame::play() {
    DisplayBoards displayBoards(&nineBoard);

    int x, y;

    int mode = gameManagement.startGame();

    gameManagement.selectMode(players, mode);

    nineBoard.getRandomFocusBoard(x, y);
    displayBoards.displayBoards(x,y);

    // player turn
    int playerTurn = 1;

    while (true) {
        // player moves
        int playerMoveX;
        int playerMoveY;
        
        if (mode == 5 || mode == 4) {
            this_thread::sleep_for(chrono::milliseconds(1000)); // Sleep for 1000 milliseconds (1 second)
        }
        // calculate the current board position on the grid
        int boardPositionOnGrid = (3 * nineBoard.getCurrentMoveX()) + nineBoard.getCurrentMoveY();

        // get the board
        TicTacToe* board = &nineBoard.getGrid()[boardPositionOnGrid];
        
        // checkk which player turn it is
        if (playerTurn == 1) {
            // get the player move and add it to the board
            players[1]->displayTurn();
            players[1]->getMove(playerMoveX, playerMoveY, board, players[1]->getPlayerNumber(), &nineBoard);
            board->addMove(playerMoveX, playerMoveY, players[1]->getPlayerNumber());
        } else {
            // get the player move and add it to the board
            players[0]->displayTurn();
            players[0]->getMove(playerMoveX, playerMoveY, board, players[0]->getPlayerNumber(), &nineBoard);
            board->addMove(playerMoveX, playerMoveY, players[0]->getPlayerNumber());
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
        int gameStats = gameManagement.wholeGameStatus(board, nineBoard.getTotalNumberOfMoves());


        // exit the game if true
        if (gameStats == 1 || gameStats == 0 || gameStats == -1) {
            gameManagement.displayWinner(gameStats);
            delete players[0];
            delete players[1];
            return 0;
        }
        
        // swap the player turn
        gameManagement.swapPlayer(playerTurn);
    }
    return 0;
};


#endif