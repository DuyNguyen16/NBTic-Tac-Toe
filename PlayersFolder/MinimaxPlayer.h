#ifndef MINIMIXPLAYER_H_
#define MINIMIXPLAYER_H_

#include "Player.h"
#include "../TicTacToeBoards/TicTacToe.h"
#include "Move.h"

class MinimaxPlayer
{
private:
    int playerNumber;
    Move move;

public:
    MinimaxPlayer(int x)
    {
        playerNumber = x;
    }

    void setBestMoves(int i, int j)
    {
        move.row = i;
        move.col = j;
    };

    int minimax(TicTacToe *board);
    int minValue(TicTacToe *board, int &depth);
    int maxValue(TicTacToe *board, int &depth);
    int gameStatus(TicTacToe *board);

    int getBestMoveX()
    {
        return move.row;
    };
    int getBestMoveY()
    {
        return move.col;
    };

    int getPlayerNumber()
    {
        return playerNumber;
    }
};

int MinimaxPlayer::minimax(TicTacToe *board)
{

    int bestVal = -100000;
    int bestDepth = 0;

    if (board->getNoOfMoves() == 0)
    {
        // randomised select a cell on a board
        srand(time(NULL));
        int x = rand() % 3;
        int y = rand() % 3;

        setBestMoves(x, y);
    }
    else
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                int cal = (3 * row) + col;

                // check for empty cell
                if (board->getBoard()[cal] == 0)
                {
                    int tempDepth = 0;   
                    board->addMove(row, col, 1);

                    int value = minValue(board, tempDepth);

                    board->addMove(row, col, 0);

                    if (tempDepth > bestDepth)
                    {
                        bestDepth = tempDepth;
                        setBestMoves(row, col);
                    }
                }
            }
        }
    }

    board->incrementNoOfMoves();
    return 0;
}

//  X player
int MinimaxPlayer::maxValue(TicTacToe *board, int &depth)
{
    int bestMinvalue = -100000;

    int status = gameStatus(board);
    if (status != 2) {
        depth = status * (1 + (9 - board->getNoOfMoves()));
        return status;
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            int cal = (3 * row) + col;
            // check for empty cell
            if (board->getBoard()[cal] == 0)
            {
                board->addMove(row, col, 1);
                board->incrementNoOfMoves();

                int value = minValue(board, depth);

                board->decrementNoOfMoves();
                board->addMove(row, col, 0);

                if (value > bestMinvalue)
                {
                    bestMinvalue = value;
                }
            }
        }
    }

    return bestMinvalue;
}

// O player
int MinimaxPlayer::minValue(TicTacToe *board, int &depth)
{
    int bestMinvalue = 100000;

    int status = gameStatus(board);
    if (status != 2) {
        depth = status * (1 + (9 - board->getNoOfMoves()));
        return status;
    }

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            int cal = (3 * row) + col;
            // check for empty cell
            if (board->getBoard()[cal] == 0)
            {
                board->addMove(row, col, -1);

                board->incrementNoOfMoves();
                int value = maxValue(board, depth);

                board->decrementNoOfMoves();
                board->addMove(row, col, 0);

                if (value < bestMinvalue)
                {
                    bestMinvalue = value;
                }
            }
        }
    }

    return bestMinvalue;
}

int MinimaxPlayer::gameStatus(TicTacToe *board)
{
    // cout << board->getBoard()[0];
    // Check first row
    if (board->getBoard()[0] == board->getBoard()[1] && board->getBoard()[1] == board->getBoard()[2])
    {
        if (board->getBoard()[0] == 1)
        {

            return 1;
        }
        else if (board->getBoard()[0] == -1)
        {

            return -1;
        }
    }

    // check second row
    if (board->getBoard()[3] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[5])
    {
        if (board->getBoard()[3] == 1)
        {

            return 1;
        }
        else if (board->getBoard()[3] == -1)
        {

            return -1;
        }
    }

    // check third row
    if (board->getBoard()[6] == board->getBoard()[7] && board->getBoard()[7] == board->getBoard()[8])
    {
        if (board->getBoard()[6] == 1)
        {

            return 1;
        }
        else if (board->getBoard()[6] == -1)
        {

            return -1;
        }
    }

    // Check first column
    if (board->getBoard()[0] == board->getBoard()[3] && board->getBoard()[3] == board->getBoard()[6])
    {
        if (board->getBoard()[0] == 1)
        {

            return 1;
        }
        else if (board->getBoard()[0] == -1)
        {

            return -1;
        }
    }

    // Check second column
    if (board->getBoard()[1] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[7])
    {
        if (board->getBoard()[1] == 1)
        {

            return 1;
        }
        else if (board->getBoard()[1] == -1)
        {

            return -1;
        }
    }

    // Check third column
    if (board->getBoard()[2] == board->getBoard()[5] && board->getBoard()[5] == board->getBoard()[8])
    {
        if (board->getBoard()[2] == 1)
        {

            return 1;
        }
        else if (board->getBoard()[2] == -1)
        {

            return -1;
        }
    }

    // check diag
    if (board->getBoard()[0] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[8])
    {
        if (board->getBoard()[0] == 1)
        {

            return 1;
        }
        else if (board->getBoard()[0] == -1)
        {

            return -1;
        }
    }

    if (board->getBoard()[2] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[6])
    {
        if (board->getBoard()[2] == 1)
        {

            return 1;
        }
        else if (board->getBoard()[2] == -1)
        {

            return -1;
        }
    }

    // check if board is full
    if (board->getNoOfMoves() >= 9)
    {
        return 0;
    }

    return 2;
}

#endif