#ifndef GameStatus_H_
#define GameStatus_H_

#include "TicTacToe.h"



// class GameStatus {
// public:
//     int gameStatus(TicTacToe *board);
// };


// int GameStatus::gameStatus(TicTacToe *board) {
//     	// Check rows for a win
// 	for (int row = 0; row < 3; row++)
// 	{
// 		if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != 0)
// 		{
// 			if (board[row][0] == 1)
// 			{
// 				return 1;
// 			}
// 			else
// 			{
// 				return -1;
// 			}
// 		}
// 	}

// 	// Check columns for a win
// 	for (int col = 0; col < 3; col++)
// 	{
// 		if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != 0)
// 		{
// 			if (board[0][col] == 1)
// 			{
// 				return 1;
// 			}
// 			else
// 			{
// 				return -1;
// 			}
// 		}
// 	}

// 	// Check diagonals for a win
// 	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
// 	{
// 		if (board[0][0] == 1)
// 		{
// 			return 1;
// 		}
// 		else
// 		{
// 			return -1;
// 		}
// 	}
// 	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
// 	{
// 		if (board[0][2] == 1)
// 		{
// 			return 1;
// 		}
// 		else
// 		{
// 			return -1;
// 		}
// 	}

// 	// check if board is full
// 	if (noOfMoves >= 9)
// 		return 2;

// 	return 0;
// }


#endif