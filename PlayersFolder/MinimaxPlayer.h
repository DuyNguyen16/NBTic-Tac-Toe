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
    void minimax(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber, NBTicTacToe *grid);
    int minimum(TicTacToe *board);
    int maximum(TicTacToe *board);
    int gameStatus(TicTacToe *board);
    int checkNextBoard(TicTacToe *nextBoard, int playerNumber);
    void removeCell(int availableCells[], int &size, int cell);
public:
    MinimaxPlayer(int x) : Player(x) {};

    bool isValidMove(int x, int y, TicTacToe *board) override
    {
        return true;
    };

    int getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber, NBTicTacToe *grid) override;
};

// minimax bot get move
int MinimaxPlayer::getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber, NBTicTacToe *grid)
{
    // check if the current board is empty
    if (board->getNoOfMoves() == 0)
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
                // get the game status of next board if the move is made
                int CheckWinnerNextBoard = checkNextBoard(nextBoard, -1);

                // Check if the oponent next move will win if X make this move
                if (CheckWinnerNextBoard == -1)
                {
                    // remove the cell from the array
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
        // increment the moves made
        board->incrementNoOfMoves();
    }
    else
    {
        minimax(smallBoardX, smallBoardY, board, playerNumber, grid);
    }

    return 0;
}


// Get the player Move (Minimax)
void MinimaxPlayer::minimax(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber, NBTicTacToe *grid)
{
    // check if x or o player
    int bestValue;
    if (playerNumber == 1)
    {
        bestValue = -100000;
    }
    else
    {
        bestValue = 100000;
    }

    // tempory x and y just incase the optimal moves are not selected
    int bestMovesCount = 0;
    int tempX;
    int tempY;

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

                // make the move and increment the number of moves made
                board->addMove(row, col, playerNumber);
                board->incrementNoOfMoves();

                // check which player it is to start the minimax recursion
                if (playerNumber == 1)
                {
                    // get the value of the move
                    tempValue = minimum(board);
                }
                else
                {
                    // get the value of the move
                    tempValue = maximum(board);
                }

                // restore the board and the number of moves made
                board->addMove(row, col, 0);
                board->decrementNoOfMoves();

                // Check which player turn it is
                if (playerNumber == 1)
                {
                    // check if tempValue is bigger (maximising)
                    if (tempValue > bestValue)
                    {
                        // back up value just incase if their is no optimal move (next board)
                        tempX = row;
                        tempY = col;
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
                            bestMovesCount += 1;
                        }
                        else
                        {
                            // only change the values if the next board winner is not the opponent
                            if (CheckWinnerNextBoard != -1)
                            {
                                bestValue = tempValue;
                                smallBoardX = row;
                                smallBoardY = col;
                                bestMovesCount += 1;
                            } else {
                                // prioritise if the move made will result in an instant winning
                                board->addMove(row, col, 1);
                                if (gameStatus(board) == 1) {
                                    bestValue = tempValue;
                                    smallBoardX = row;
                                    smallBoardY = col;
                                    bestMovesCount += 1;
                                }
                                board->addMove(row, col, 0);
                            }
                        }
                    }
                }
                else
                {
                    // check if tempValue is smaller (minimising)
                    if (tempValue < bestValue)
                    {
                        // back up value just incase if their is no optimal move (next board)
                        tempX = row;
                        tempY = col;
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
                            bestMovesCount += 1;
                        }
                        else
                        {
                            // only change the values if the next board winner is not the opponent
                            if (CheckWinnerNextBoard != 1)
                            {
                                bestValue = tempValue;
                                smallBoardX = row;
                                smallBoardY = col;
                                bestMovesCount += 1;
                            } else {
                                // prioritise if the move made will result in an instant winning
                                board->addMove(row, col, -1);
                                if (gameStatus(board) == -1) {
                                    bestValue = tempValue;
                                    smallBoardX = row;
                                    smallBoardY = col;
                                    bestMovesCount += 1;
                                }
                                board->addMove(row, col, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    // check if no best move was selected
    if (bestMovesCount == 0) {
        smallBoardX = tempX;
        smallBoardY = tempY;
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
                // make the move of the current player and increment the number of moves made
                board->addMove(row, col, 1);
                board->incrementNoOfMoves();

                // get the value of the move
                int tempValue = minimum(board);
                // restore the move of the current player and decrement the number of moves made
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

// check if next board will have a winner
int MinimaxPlayer::checkNextBoard(TicTacToe *nextBoard, int playerNumber)
{
    int check = 2;
    // loop through each row on board
    for (int row = 0; row < 3; row++)
    {
        // loop through each column on board
        for (int col = 0; col < 3; col++)
        {
            // calculate the position
            int cal = (3 * row) + col;
            // check if the cell is empty
            if (nextBoard->getBoard()[cal] == 0)
            {
                int tempCheck;
                // make the move to the board
                nextBoard->addMove(row, col, playerNumber);
                // get the game status of the board
                tempCheck = gameStatus(nextBoard);
                // restore the board
                nextBoard->addMove(row, col, 0);
                // check if gameStatus return the same value as playerNumber wanted to check
                if (tempCheck == playerNumber)
                {
                    check = tempCheck;
                }
            }
        }
    }
    return check;
}

// remove value from array for randomise
void MinimaxPlayer::removeCell(int availableCells[], int &size, int cell)
{
    // for each element in the array
    for (int i = 0; i < size; i++)
    {
        // check if the array element is the same as the cell
        if (availableCells[i] == cell)
        {
            // move every elements to the left
            for (int j = i; j < size - 1; j++)
            {
                availableCells[j] = availableCells[j + 1];
            }
            // Reduce size of the array
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