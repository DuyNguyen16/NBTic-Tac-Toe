#ifndef PLAYER_H_
#define PLAYER_H_

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
    virtual int getMove(int &x, int &y, TicTacToe *board, int playerNumber, NBTicTacToe *grid) = 0;

    virtual bool isValidMove(int x, int y, TicTacToe *board) = 0;

    void displayTurn();

    int getPlayerNumber() {return playerNumber;}

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