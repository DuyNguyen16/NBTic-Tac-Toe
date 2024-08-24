#ifndef Player_H_
#define Player_H_

#include "TicTacToe.h"

class Player {
private:
    char player;
public:
    Player(int x) {
        player = x;
    }
    bool getMove(int &x, int &y, TicTacToe *board);
    bool isValidMove(int x, int y, TicTacToe *board);
};


bool Player::getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board)
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


// check if the move on a Tic Tac Toe is valid
bool Player::isValidMove(int x, int y, TicTacToe *board)
{ // Add your code to complete the program
	// check if  the position is n the board
	if (0 <= x && x <= 8)
	{
		// check if the position on board is taken
		if (board->getBoard()[x] == 0)
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

#endif