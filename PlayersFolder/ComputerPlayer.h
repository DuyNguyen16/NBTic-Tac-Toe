#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Player.h"
#include "../GameManagement.h"
#include "../TicTacToe.h"
#include "../Move.h"

class ComputerPlayer : public Player
{
private:
    GameManagement gameMangement;
    Move move;

public:
    ComputerPlayer(int x) : Player(x) {};
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
};

// Minimax algorithm
int ComputerPlayer::minimax(bool isMaxiTurn, TicTacToe *board)
{
    int score = gameMangement.gameStatus(board);

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
        for (int i = 0; i < 9; i++)
        {
            if (board->getBoard()[i] == 0)
            {
                board->getBoard()[i] = 1;

                // Call minimax recursively
                bestValue = max(bestValue, minimax(!isMaxiTurn, board));

                board->getBoard()[i] = 0;
            }
        }
        return bestValue;
    }

    //  if the current minimax is O
    else
    {
        int bestValue = 100000;

        //  Loop throug all cells
        for (int i = 0; i < 9; i++)
        {
            if (board->getBoard()[i] == 0)
            {
                board->getBoard()[i] = -1;

                // Call minimax recursively
                bestValue = min(bestValue, minimax(!isMaxiTurn, board));

                board->getBoard()[i] = 0;
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
    for (int i = 0; i < 9; i++)
    {
        if (board->getBoard()[i] == 0)
        {
            board->getBoard()[i] = 1;

            int moveValue = minimax(false, board);

            board->getBoard()[i] = 0;

            if (moveValue > bestValue)
            {
                switch (i)
                {
                case 0:
                    setBestMoves(0, 0);
                    bestValue = moveValue;
                case 1:
                    setBestMoves(0, 1);
                    bestValue = moveValue;
                case 2:
                    setBestMoves(0, 2);
                    bestValue = moveValue;
                case 3:
                    setBestMoves(1, 0);
                    bestValue = moveValue;
                case 4:
                    setBestMoves(1, 1);
                    bestValue = moveValue;
                case 5:
                    setBestMoves(1, 2);
                    bestValue = moveValue;
                case 6:
                    setBestMoves(2, 0);
                    bestValue = moveValue;
                case 7:
                    setBestMoves(2, 1);
                    bestValue = moveValue;
                case 8:
                    setBestMoves(2, 2);
                    bestValue = moveValue;
                }
            }
        }
    }

    // check if it is the first move on a board
    if (getBestMoveX() == 0 && getBestMoveY() == 0 && board->getNoOfMoves() == 0)
    {
        // randomised select a cell on a board
        srand(time(nullptr));
        int x = rand() % 3;
        int y = rand() % 3;

        setBestMoves(x, y);
    }
}

#endif