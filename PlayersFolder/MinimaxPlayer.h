#ifndef MINIMIXPLAYER_H_
#define MINIMIXPLAYER_H_

#include "Player.h"
#include "../TicTacToeBoards/TicTacToe.h"
#include "../TicTacToeBoards/NBTicTacToe.h"
#include "Move.h"

class MinimaxPlayer : public Player
{
private:
    Move move;

public:
    MinimaxPlayer(int x) : Player(x) {};

    bool isValidMove(int x, int y, TicTacToe *board) override
    {
        return true;
    };

    int getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber, NBTicTacToe *grid) override;
    void minimax(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber, NBTicTacToe *grid);
    int minimum(TicTacToe *board);
    int maximum(TicTacToe *board);
    int gameStatus(TicTacToe *board);
    int checkNextBoard(TicTacToe *nextBoard, int playerNumber);
    void removeCell(int availableCells[], int &size, int cell);
};


int MinimaxPlayer::getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber, NBTicTacToe *grid)
{
    // check if any mobe is made on the board
    if (board->getNoOfMoves() != 0)
    {
        minimax(smallBoardX, smallBoardY, board, playerNumber, grid);
    }
    else
    {
        int availableCells[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        int size = 9;

        int cell;

        while (true)
        {
            // randomised select a cell on a board

            srand(time(NULL));
            cell = rand() % size;

            TicTacToe *nextBoard = &grid->getGrid()[cell];

            // check if the current player is X
            if (playerNumber == 1)
            {
                // get the game status of next board
                int CheckWinnerNextBoard = checkNextBoard(nextBoard, -1);

                // Check if the oponent next move will win if X make this move
                if (CheckWinnerNextBoard == -1)
                {
                    removeCell(availableCells, size, cell);
                }
                else
                {
                    break;
                }
            }
            else
            {
                // get the game status of next board
                int CheckWinnerNextBoard = checkNextBoard(nextBoard, 1);

                // Check if the oponent next move will win if O make this move
                if (CheckWinnerNextBoard == 1)
                {
                    removeCell(availableCells, size, cell);
                }
                else
                {
                    break;
                }
            }
        }
        // change the x and y value for the to the next board
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                int cal = (3 * row) + col;
                if (cal == cell)
                {
                    smallBoardX = row;
                    smallBoardY = col;
                }
            }
        }
    }

    return 0;
}


// Get the player Move (Minimax)
void MinimaxPlayer::minimax(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber, NBTicTacToe *grid)
{
    int bestValue;
    if (playerNumber == 1)
    {
        bestValue = -100000;
    }
    else
    {
        bestValue = 100000;
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
                int tempValue;

                board->addMove(row, col, playerNumber);
                // get the value of the move

                if (playerNumber == 1)
                {
                    tempValue = minimum(board);
                }
                else
                {
                    tempValue = maximum(board);
                }

                // restore the board
                board->addMove(row, col, 0);

                if (playerNumber == 1)
                {
                    // check if tempValue is bigger (maximising)
                    if (tempValue > bestValue)
                    {
                        // calculate the current board position on the grid
                        int boardPositionOnGrid = (3 * row) + col;
                        TicTacToe *nextBoard = &grid->getGrid()[boardPositionOnGrid];

                        // check if this move is made will the next player on the next board win
                        int CheckWinnerNextBoard = checkNextBoard(nextBoard, -1);

                        // check if the next board is the same as this board
                        if (board == nextBoard)
                        {
                            bestValue = tempValue;
                            smallBoardX = row;
                            smallBoardY = col;
                        }
                        else
                        {
                            // only change the value if the next board winner is not the opponent
                            if (CheckWinnerNextBoard != -1)
                            {
                                bestValue = tempValue;
                                smallBoardX = row;
                                smallBoardY = col;
                            }
                        }
                    }
                }
                else
                {
                    // check if tempValue is smaller (minimising)
                    if (tempValue < bestValue)
                    {
                        // calculate the current board position on the grid
                        int boardPositionOnGrid = (3 * row) + col;
                        TicTacToe *nextBoard = &grid->getGrid()[boardPositionOnGrid];

                        // check if this move is made will the next player on the next board win
                        int CheckWinnerNextBoard = checkNextBoard(nextBoard, 1);

                        // check if the next board is the same as this board
                        if (board == nextBoard)
                        {
                            bestValue = tempValue;
                            smallBoardX = row;
                            smallBoardY = col;
                        }
                        else
                        {
                            // only change the value if the next board winner is not the opponent
                            if (CheckWinnerNextBoard != -1)
                            {
                                bestValue = tempValue;
                                smallBoardX = row;
                                smallBoardY = col;
                            }
                        }
                    }
                }
            }
        }
    }

    board->incrementNoOfMoves();
}

// Maximising Player
int MinimaxPlayer::maximum(TicTacToe *board)
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
                int tempValue = minimum(board);

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
int MinimaxPlayer::minimum(TicTacToe *board)
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
                int tempValue = maximum(board);

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

int MinimaxPlayer::checkNextBoard(TicTacToe *nextBoard, int playerNumber)
{
    int check = 2;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            int cal = (3 * row) + col;
            if (nextBoard->getBoard()[cal] == 0)
            {
                int tempCheck;
                nextBoard->addMove(row, col, playerNumber);
                tempCheck = gameStatus(nextBoard);
                nextBoard->addMove(row, col, 0);
                if (tempCheck == playerNumber)
                {
                    check = tempCheck;
                }
            }
        }
    }

    return check;
}


void MinimaxPlayer::removeCell(int availableCells[], int &size, int cell)
{
    for (int i = 0; i < size; i++)
    {
        if (availableCells[i] == cell)
        {
            for (int j = i; j < size - 1; j++)
            {
                availableCells[j] = availableCells[j + 1];
            }
            // Reduce the effective size of the array
            size--;
            break;
        }
    }
};



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