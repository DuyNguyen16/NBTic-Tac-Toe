#ifndef GetMove_H_
#define GetMove_H_

#include "TicTacToe.h"

class GetMove
{
private:
    
public:
    GetMove();
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
			return false;
		}
	}
	else
	{
		return false;
	}
};






#endif