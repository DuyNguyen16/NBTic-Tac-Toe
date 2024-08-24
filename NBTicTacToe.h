#ifndef NBTicTacToe_H_
#define NBTicTacToe_H_

#include "TicTacToe.h"
#include "Coordinate.h"

// Nine Tic Tac Toe class
class NBTicTacToe
{
public:
	NBTicTacToe();


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


private:
	TicTacToe grid[3][3]; // nine TicTacToe board
	Coordinate currentBoard;
	int totalNoOfMoves = 0;
};

NBTicTacToe::NBTicTacToe () {
	currentBoard.x = 0;
	currentBoard.y = 0;
}







#endif