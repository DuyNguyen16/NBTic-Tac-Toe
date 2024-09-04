#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

#include "Player.h"

class RandomPlayer : public Player {
public:
    RandomPlayer(int x) : Player(x) {};
    int getMove(int &x, int &y, TicTacToe *board, int playerNumber) override;
    bool isValidMove(int x, int y, TicTacToe *board) override;


};


int RandomPlayer::getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber)
{

    if (board->getNoOfMoves() >= 9)
    {
        return 1;
    }

    do
    {
        srand(time(0));
		smallBoardX = rand() % 3;
		smallBoardY = rand() % 3;

    } while (!isValidMove(smallBoardX, smallBoardY, board));
    // Enter move on current board
    smallBoardX = smallBoardX;
    smallBoardY = smallBoardY;
    return 0;
};


// check if the move on a Tic Tac Toe is valid
bool RandomPlayer::isValidMove(int x, int y, TicTacToe *board)
{ // Add your code to complete the program
    // check if  the position is n the board
    int currentPos = (3 * x) + y;
    if (0 <= currentPos && currentPos <= 8)
    {
        // check if the position on board is taken
        if (board->getBoard()[currentPos] == 0)
        {
            board->incrementNoOfMoves();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
};

#endif