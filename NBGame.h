#ifndef NBGame_H_
#define NBGame_H_

#include "TicTacToeBoards/NBTicTacToe.h"
#include "TicTacToeBoards/TicTacToe.h"
#include "TicTacToeBoards/DisplayBoards.h"
#include "GameManagement.h"
#include "PlayersFolder/Player.h" 
#include "PlayersFolder/HumanPlayer.h"
#include "PlayersFolder/ComputerPlayer.h"
#include "PlayersFolder/RandomPlayer.h"
#include "PlayersFolder/MinimaxPlayer.h"



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

    players[0] = new HumanPlayer(-1); // Player 1 is a human player
    players[1] = new RandomPlayer(1); // Player 2 is a computer player

    MinimaxPlayer computerPlayer(1);


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
            players[1]->displayTurn();
        } else {
            players[0]->displayTurn();
        }

        // calculate the current board position
        int boardPosition = (3 * nineBoard.getCurrentMoveX()) + nineBoard.getCurrentMoveY();

        // get the board
        TicTacToe* board = &nineBoard.getGrid()[boardPosition];
        
        // get the player move
        if (playerTurn == 1) {
            
            computerPlayer.minimax(board);
            playerMoveX = computerPlayer.getBestMoveX();
            playerMoveY = computerPlayer.getBestMoveY();
            board->addMove(playerMoveX, playerMoveY, computerPlayer.getPlayerNumber());
            // players[1]->getMove(playerMoveX, playerMoveY, board);
            // board->addMove(playerMoveX, playerMoveY, players[1]->getPlayerNumber());
        } else {
            // players[1]->getMove(playerMoveX, playerMoveY, board);
            // board->addMove(playerMoveX, playerMoveY, players[1]->getPlayerNumber());
            // get Human move and add it to board
            players[0]->getMove(playerMoveX, playerMoveY, board);
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
        int gameStats = gameManagement.gameStatus(board);


        // exit the game if true
        if (gameStats != 0 || nineBoard.getTotalNumberOfMoves() >= 81) {
            return 0;
        }
        
        // swap the player turn
        gameManagement.swapPlayer(playerTurn);
    }
    return 0;
};


#endif