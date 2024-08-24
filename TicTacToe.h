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
	bool isValidMove(int, int);
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
};


// initialise all value to 0 with (constructor)
TicTacToe::TicTacToe()
{ // How to call this funavailablection?
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = 0;

	noOfMoves = 0;
};


// check if the move on a Tic Tac Toe is valid
bool TicTacToe::isValidMove(int x, int y)
{ // Add your code to complete the program
	// check if  the position is n the board
	if (0 <= x && x <= 2 && 0 <= y && y <= 2)
	{
		// check if the position on board is taken
		if (board[x][y] == 0)
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