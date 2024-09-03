#ifndef Player_H_
#define Player_H_

#include "../TicTacToeBoards/TicTacToe.h"

class Player
{
private:
    int playerNumber;

public:
    Player(int x)
    {
        playerNumber = x;
    }
    virtual bool getMove(int &x, int &y, TicTacToe *board) = 0;
    bool isValidMove(int x, int y, TicTacToe *board);

    void displayTurn();

    int getPlayerNumber() {return playerNumber;}
};



// check if the move on a Tic Tac Toe is valid
bool Player::isValidMove(int x, int y, TicTacToe *board)
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

void Player::displayTurn()
{
    if (playerNumber == 1)
    {
        cout << " -------------------------------------------\n";
        cout << " Player X turn:\n";
        cout << " -------------------------------------------\n";
    }
    else
    {
        cout << " -------------------------------------------\n";
        cout << " Player O turn:\n";
        cout << " -------------------------------------------\n";
    }
};

#endif