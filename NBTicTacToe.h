#ifndef NBTicTacToe_H_
#define NBTicTacToe_H_

#include "TicTacToe.h"
#include "Coordinate.h"

// Nine Tic Tac Toe class
class NBTicTacToe
{
public:
	NBTicTacToe() {
		currentBoard.x = 0;
		currentBoard.y = 0;
	}


	// update the total number of moves
	void incrementTotalNoOfMoves()
	{
		totalNoOfMoves++;
	}

	int getTotalNumberOfMoves()
	{
		return totalNoOfMoves;
	}



    TicTacToe* getGrid() {
        return &grid[0][0]; // Pointer to the first TicTacToe board
    }

	void getFocusBoard(int &x, int &y );

	int checkIfBoardAvailable(int checkX, int checkY);

private:
	TicTacToe grid[3][3]; // nine TicTacToe board
	Coordinate currentBoard;
	int totalNoOfMoves = 0;
};



void NBTicTacToe::getFocusBoard(int &x, int &y) {
		do
	{
		srand(time(nullptr));
		x = rand() % 3;
		y = rand() % 3;
	} while (checkIfBoardAvailable(x, y) == 1);
}

int NBTicTacToe::checkIfBoardAvailable(int checkX, int checkY)
{
	if (grid[checkX][checkY].getNoOfMoves() >= 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



#endif