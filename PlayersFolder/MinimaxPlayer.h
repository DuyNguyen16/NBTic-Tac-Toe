#ifndef MINIMIXPLAYER_H_
#define MINIMIXPLAYER_H_

#include "Player.h"
#include "../TicTacToeBoards/TicTacToe.h"
#include "Move.h"

class MinimaxPlayer : public Player
{
private:
    Move move;

public:
    MinimaxPlayer(int x) : Player(x) {};

    bool isValidMove(int x, int y, TicTacToe *board) override
    {
        cout << "yes";
        return true;
    };

    int getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board) override;
    int minValue(TicTacToe *board);
    int maxValue(TicTacToe *board);
    int gameStatus(TicTacToe *board);
};

// Get the player Move
int MinimaxPlayer::getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board)
{
    int biggestValue = -100000;

    // check if the current board is empty
    if (board->getNoOfMoves() == 0)
    {
        // randomised select a cell on a board
        srand(time(NULL));
        int x = rand() % 3;
        int y = rand() % 3;

        smallBoardX = x;
        smallBoardY = y;
    }
    else
    {
        // Loop through each cells in the board
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                int cal = (3 * row) + col;

                // check for empty cell
                if (board->getBoard()[cal] == 0)
                {
                    board->addMove(row, col, 1);

                    // get the value of the move
                    int tempValue = minValue(board);

                    // restore the board
                    board->addMove(row, col, 0);

                    // check if tempValue is bigger (maximising)
                    if (tempValue > biggestValue)
                    {
                        biggestValue = tempValue;
                        smallBoardX = row;
                        smallBoardY = col;
                    }
                }
            }
        }
    }

    board->incrementNoOfMoves();
    return 0;
}

// Maximising Player
int MinimaxPlayer::maxValue(TicTacToe *board)
{
    int biggestValue = -100000;

    // check for the current board game status
    int status = gameStatus(board);
    if (status != 2)
    {
        return (1 + (9 - board->getNoOfMoves())) * status;
    }

    // Loop through each cells in the board
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

                // get the value of the move
                int tempValue = minValue(board);

                board->decrementNoOfMoves();
                board->addMove(row, col, 0);

                // maximising the value
                if (tempValue > biggestValue)
                {
                    biggestValue = tempValue;
                }
            }
        }
    }

    return biggestValue;
}

// Minimising player
int MinimaxPlayer::minValue(TicTacToe *board)
{
    int smallestValue = 100000;

    // check for current board game status
    int status = gameStatus(board);
    if (status != 2)
    {
        return (1 + (9 - board->getNoOfMoves())) * status;
    }

    // Loop through each cell in the board
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

                // get the value of the move
                int tempValue = maxValue(board);

                board->decrementNoOfMoves();
                board->addMove(row, col, 0);

                // Minimising the value
                if (tempValue < smallestValue)
                {
                    smallestValue = tempValue;
                }
            }
        }
    }

    return smallestValue;
}

// check the game status
int MinimaxPlayer::gameStatus(TicTacToe *board)
{
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