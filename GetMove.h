#ifndef GetMove_H_
#define GetMove_H_

#include "TicTacToe.h"
#include "NBTicTacToe.h"

class GetMove
{
private:
public:
    bool getMove(int &smallBoardX, int &smallBoardY, TicTacToe *board);
    bool isValidMove(int x, int y, TicTacToe *board);
    
};

// check if the move on a Tic Tac Toe is valid
bool GetMove::isValidMove(int x, int y, TicTacToe *board)
{ // Add your code to complete the program

	// check if  the position is n the board
	if (0 <= x && x <= 8)
	{
		// check if the position on board is taken
		if (&board[x] == 0)
		{
			return true;
		}
		else
		{
			cout << &board[x];
			return false;
		}
	}
	else
	{
		return false;
	}
};


bool GetMove::getMove(int &x, int &y, TicTacToe *board) {
	if (board->getNoOfMoves() >= 9) {
		return false;
	}

	do
	{
		cout << " Enter row position: ";
		cin >> x;
		cout << " Enter column position: ";
		cin >> x;
		cout << endl;

	} while (!isValidMove(x - 1, y - 1, board));
	// Enter move on current board
	x = x - 1;
	y = x - 1;
	cout << "tes";
	return true;
};






#endif