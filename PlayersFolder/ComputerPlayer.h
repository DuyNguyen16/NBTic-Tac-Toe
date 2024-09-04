#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Player.h"
#include "../GameManagement.h"
#include "../TicTacToeBoards/TicTacToe.h"
#include "Move.h"

class ComputerPlayer
{
private:
    GameManagement gameMangement;
    Move move;
    int playerNumber;
public:
        ComputerPlayer(int x)
    {
        playerNumber = x;
    }

    int getPlayerNumber() {
        return playerNumber;
    }

    void findBestMove(TicTacToe *board);
    int minimax(bool isMaxiTurn, TicTacToe *board);

    void setBestMoves(int i, int k)
    {
        move.row = i;
        move.col = k;
    };

    int getBestMoveX()
    {
        return move.row;
    };
    int getBestMoveY()
    {
        return move.col;
    };

    int gameStatus(TicTacToe *board);

    bool isValidMove(int x, int y, TicTacToe *board);
};

// check if the move on a Tic Tac Toe is valid
bool ComputerPlayer::isValidMove(int x, int y, TicTacToe *board)
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


// Minimax algorithm
int ComputerPlayer::minimax(bool isMaxiTurn, TicTacToe *board)
{
    int score = gameStatus(board);

    if (score == 1)
    {
        return score;
    }

    if (score == -1)
    {
        return score;
    }

    // check if board is full
    if (board->getNoOfMoves() >= 9)
    {
        return 0;
    }

    // If current minimax is X
    if (isMaxiTurn)
    {
        int bestValue = -100000;

        //  Loop throug all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                int cal = (3 * i) + j;
                if (board->getBoard()[cal] == 0)
                {
                    board->addMove(i, j, 1);

                    // Call minimax recursively
                    bestValue = max(bestValue, minimax(!isMaxiTurn, board));

                    // return back to the board state previously
                    board->addMove(i, j, 0);
                }
            }
        }
        return bestValue;
    }

    //  if the current minimax is O
    else
    {
        int bestValue = 100000;

        // loop through every cells on the board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                int cal = (3 * i) + j;
                if (board->getBoard()[cal] == 0)
                {
                    board->addMove(i, j, -1);

                    // Call minimax recursively
                    bestValue = min(bestValue, minimax(!isMaxiTurn, board));

                    // return back to the board state previously
                    board->addMove(i, j, 0);
                }
            }
        }
        return bestValue;
    }
}

void ComputerPlayer::findBestMove(TicTacToe *board)
{
    int bestValue = -100000;
    setBestMoves(-1, -1);

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Check if cell is empty
            int cal = (3 * i) + j;
            if (board->getBoard()[cal] == 0)
            {
                // Make the move
                board->addMove(i, j, 1);

                // compute evaluation function for this
                // move.
                int moveValue = minimax(false, board);
                

                // Undo the move
                board->addMove(i, j, 0);


                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveValue > bestValue)
                {
                    setBestMoves(i, j);
                    bestValue = moveValue;
                }
            }
        }
    }

    // check if it is the first move on a board
    if (getBestMoveX() == 0 && getBestMoveY() == 0 && board->getNoOfMoves() == 0)
    {
        // randomised select a cell on a board
        srand(time(0));
        int x = rand() % 3;
        int y = rand() % 3;

        setBestMoves(x, y);
    }

    board->incrementNoOfMoves();
}


int ComputerPlayer::gameStatus(TicTacToe *board) {
    // cout << board->getBoard()[0];
    // Check first row
    if (board->getBoard()[0] == board->getBoard()[1] && board->getBoard()[1] == board->getBoard()[2]) {
        if (board->getBoard()[0] == 1) {
            
            return 1;
        } else if (board->getBoard()[0] == -1) {
            
            return -1;
        }
    }

    // check second row
    if (board->getBoard()[3] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[5]) {
        if (board->getBoard()[3] == 1) {
            
            return 1;
        } else if (board->getBoard()[3] == -1) {
            
            return -1;
        }
    }

    // check third row 
    if (board->getBoard()[6] == board->getBoard()[7] && board->getBoard()[7] == board->getBoard()[8]) {
        if (board->getBoard()[6] == 1) {
            
            return 1;
        } else if (board->getBoard()[6] == -1) {
            
            return -1;
        }
    }

    
    // Check first column
    if (board->getBoard()[0] == board->getBoard()[3] && board->getBoard()[3] == board->getBoard()[6]) {
        if (board->getBoard()[0] == 1) {
            
            return 1;
        } else if (board->getBoard()[0] == -1) {
            
            return -1;
        }
    }

    // Check second column
    if (board->getBoard()[1] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[7]) {
        if (board->getBoard()[1] == 1) {
            
            return 1;
        } else if (board->getBoard()[1] == -1) {
            
            return -1;
        }
    }

    // Check third column
    if (board->getBoard()[2] == board->getBoard()[5] && board->getBoard()[5] == board->getBoard()[8]) {
        if (board->getBoard()[2] == 1) {
            
            return 1;
        } else if (board->getBoard()[2] == -1) {
            
            return -1;
        }
    }



    // check diag
    if (board->getBoard()[0] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[8]) {
        if (board->getBoard()[0] == 1) {
            
            return 1;
        } else if (board->getBoard()[0] == -1) {
            
            return -1;
        }
    }
    
    if (board->getBoard()[2] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[6]) {
        if (board->getBoard()[2] == 1) {
            
            return 1;
        } else if (board->getBoard()[2] == -1) {
            
            return -1;
        }
    }

        // check if board is full
	if (board->getNoOfMoves() >= 9) {
		return 0;
    }

	return 2;
}

#endif