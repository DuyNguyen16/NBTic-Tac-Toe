#ifndef TicTacToe_H_
#define TicTacToe_H_

#include "Move.h"

#include <iostream>
using namespace std;

const int BOARDSIZE = 3;

// Tic Tac Toe class
class TicTacToe
{
private:
	int board[BOARDSIZE][BOARDSIZE];
	int noOfMoves;
	Move move;

public:
	TicTacToe();
	void addMove(int, int, int);

	void printOneBoardRow(int row);


	int getNoOfMoves()
	{
		return noOfMoves;
	};

	void incrementNoOfMoves()
	{
		noOfMoves += 1;
	};

	int *getBoard() {
		return &board[0][0]; // return a pointer pointed at the first element of the board
	};
};


// initialise all value to 0 with (constructor)
TicTacToe::TicTacToe()
{ // How to call this funavailablection?
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
};



// Add player move to the board
void TicTacToe::addMove(int x, int y, int player)
{ // What is this function for?
	board[x][y] = player;
}

// Print one row of the Tic Tac Toe board
void TicTacToe::printOneBoardRow(int row)
{
	for (int i = 0; i < 3; i++)
	{
		char playerSymbol = ' ';
		// display spot
		if (board[row][i] == 1)
		{
			cout << " | " << 'X';
		}
		else if (board[row][i] == -1)
		{
			cout << " | " << 'O';
		}
		else
		{
			cout << " | " << ' ';
		}
	}
	cout << " | ";
};

#endif