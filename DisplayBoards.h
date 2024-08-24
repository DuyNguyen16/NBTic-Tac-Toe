#ifndef DisplayBoards_H_
#define DisplayBoards_H_

#include "TicTacToe.h"
#include "NBTicTacToe.h"

class DisplayBoards
{
private:
    NBTicTacToe* nb;
public:
    DisplayBoards(NBTicTacToe* grid) : nb(grid) {}
    void displayBoardsRow(int, int, int);

	// display the nine Tic Tac Toe Board
	void displayBoards(int, int);
};


// Display the one row of the main board
void DisplayBoards::displayBoardsRow(int boardRowNumber, int x, int y)
{
	for (int col = 0; col < 3; col++)
	{
		// top of board lines
		if (col == 0)
		{
			// display the top line of the Tic Tac Toe board
			for (int top = 0; top < 3; top++)
			{
				// check for the current focus board
				if (boardRowNumber == x && top == y)
				{
					cout << " *--*--*--*--* ";
				}
				else
				{
					cout << " ------------- ";
				}
			}
			cout << endl;
		}

		//  Print each row rows
        if (boardRowNumber == 0) {
            for (int j = 0; j < 3; j++)
            {
                TicTacToe* board = &nb->getGrid()[j];
                board->printOneBoardRow(col);
            }
        } else if (boardRowNumber == 1) {
            for (int j = 3; j < 6; j++)
            {
                TicTacToe* board = &nb->getGrid()[j];
                board->printOneBoardRow(col);
            }
        } else if (boardRowNumber == 2) {
            for (int j = 6; j < 9; j++)
            {
                TicTacToe* board = &nb->getGrid()[j];
                board->printOneBoardRow(col);
            }
        }

		cout << endl;

		// middle of board lines
		if (col == 0 || col == 1)
		{
			// display the middle line of the Tic Tac Toe board
			for (int middle = 0; middle < 3; middle++)
			{
				// check for the current focus board
				if (boardRowNumber == x && middle == y)
				{
					cout << " *___|___|___* ";
				}
				else
				{
					cout << " |___|___|___| ";
				}
			}
			cout << endl;
		}

		// bottom of board lines
		if (col == 2)
		{
			// display the bottom line of the Tic Tac Toe board
			for (int bottom = 0; bottom < 3; bottom++)
			{
				// check for the current focus board
				if (boardRowNumber == x && bottom == y)
				{
					cout << " *--*--*--*--* ";
				}
				else
				{
					cout << " ------------- ";
				}
			}
		}
	};
}


// Display the whole nine Tic Tac Toe Board
void DisplayBoards::displayBoards(int x, int y)
{
	// Display all the rows of NB Tic Tac Toe
	for (int i = 0; i < 3; i++)
	{
		// Display the Nine Tac Tac Toe row
		displayBoardsRow(i, x, y);
		cout << endl;
	}
};




#endif