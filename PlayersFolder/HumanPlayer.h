#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(int x) : Player(x) {};
    bool getMove(int &x, int &y, TicTacToe *board) override;
};

bool HumanPlayer::getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board)
{

    if (board->getNoOfMoves() >= 9)
    {
        return false;
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
    return true;
};

#endif