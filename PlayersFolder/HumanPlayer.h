#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(int x) : Player(x) {};
    int getMove(int &x, int &y, TicTacToe *board, int playerNumber) override;
    bool isValidMove(int x, int y, TicTacToe *board) override;
};

int HumanPlayer::getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board, int playerNumber)
{

    if (board->getNoOfMoves() >= 9)
    {
        return 1;
    }

    do
    {
        cout << " Enter row position: ";
        cin >> smallBoardX;
        cout << " Enter column position: ";
        cin >> smallBoardY;
        cout << endl;

    } while (!isValidMove(smallBoardX - 1, smallBoardY - 1, board));
    // Enter move on current board
    smallBoardX = smallBoardX - 1;
    smallBoardY = smallBoardY - 1;
    return 0;
};


// check if the move on a Tic Tac Toe is valid
bool HumanPlayer::isValidMove(int x, int y, TicTacToe *board)
{ // Add your code to complete the program
    // check if  the position is n the board
    int currentPos = (3 * x) + y;
    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
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
    } else {
        return false;
    }
};

#endif