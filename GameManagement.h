#ifndef GameManagement_H_
#define GameManagement_H_

#include <iostream>
#include "PlayersFolder/HumanPlayer.h"
#include "PlayersFolder/RandomPlayer.h"
#include "PlayersFolder/MinimaxPlayer.h"
#include "PlayersFolder/Player.h"
using namespace std;

struct GameManagement {
    int startGame();
    int wholeGameStatus(TicTacToe *board, int totalNumberOfMoves);
    int displayWinner(int playerNumber);
    void swapPlayer(int &playerTurn);
    void selectMode(Player *players[], int mode);
};

void GameManagement::selectMode(Player *players[], int mode) {
    switch (mode) {
        case 1:
            // Player 1 is a human player
            players[0] = new HumanPlayer(-1);
            // Player 1 is a human player
            players[1] = new HumanPlayer(1);
            break;
        case 2:
            // Player 1 is a human player
            players[0] = new HumanPlayer(-1);
            // Player 2 is a computer player
            players[1] = new MinimaxPlayer(1);
            break;
        case 3:
            // Player 1 is a human player
            players[0] = new HumanPlayer(-1);
            // Player 2 is a computer player
            players[1] = new RandomPlayer(1);
            break;
        case 4:
            // Player 1 is a computer player
            players[0] = new RandomPlayer(-1);
            // Player 2 is a computer player
            players[1] = new MinimaxPlayer(1);
            break;
        case 5:
            // Player 1 is a computer player
            players[0] = new MinimaxPlayer(-1);
            // Player 2 is a computer player
            players[1] = new MinimaxPlayer(1);
    }
}

int GameManagement::startGame() {

    int mode = 0;
    while (true) {
        cout << " -------------------------------------------\n";
        cout << "        Nine Board Tic Tac Toe Game\n";
        cout << " -------------------------------------------\n";
        cout << "Select Game Mode: " << endl;
        cout << " -------------------------------------------\n";
        cout << "1. Human vs Human." << endl;
        cout << "2. Human vs AI (Minimax)." << endl;
        cout << "3. Human vs Bot (Random)." << endl;
        cout << "4. AI (Minimax) vs Bot (Random)." << endl;
        cout << "5. AI (Minimax) vs AI (Minimax)." << endl;
        cout << " -------------------------------------------\n";
        cout << "Game Mode Number: ";
        cin >> mode;
        if (mode > 0 && mode < 6) {
            break;
        }
    }

    return mode;
}

int GameManagement::wholeGameStatus(TicTacToe *board, int totalNumberOfMoves) {
    if (board->getBoard()[0] == board->getBoard()[1] && board->getBoard()[1] == board->getBoard()[2]) {
        if (board->getBoard()[0] == 1) {
            displayWinner(1);
            return 1;
        } else if (board->getBoard()[0] == -1) {
            displayWinner(-1);
            return -1;
        }
    }

    // check second row
    if (board->getBoard()[3] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[5]) {
        if (board->getBoard()[3] == 1) {
            displayWinner(1);
            return 1;
        } else if (board->getBoard()[3] == -1) {
            displayWinner(-1);
            return -1;
        }
    }

    // check third row 
    if (board->getBoard()[6] == board->getBoard()[7] && board->getBoard()[7] == board->getBoard()[8]) {
        if (board->getBoard()[6] == 1) {
            displayWinner(1);
            return 1;
        } else if (board->getBoard()[6] == -1) {
            displayWinner(-1);
            return -1;
        }
    }

    
    // Check first column
    if (board->getBoard()[0] == board->getBoard()[3] && board->getBoard()[3] == board->getBoard()[6]) {
        if (board->getBoard()[0] == 1) {
            displayWinner(1);
            return 1;
        } else if (board->getBoard()[0] == -1) {
            displayWinner(-1);
            return -1;
        }
    }

    // Check second column
    if (board->getBoard()[1] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[7]) {
        if (board->getBoard()[1] == 1) {
            displayWinner(1);
            return 1;
        } else if (board->getBoard()[1] == -1) {
            displayWinner(-1);
            return -1;
        }
    }

    // Check third column
    if (board->getBoard()[2] == board->getBoard()[5] && board->getBoard()[5] == board->getBoard()[8]) {
        if (board->getBoard()[2] == 1) {
            displayWinner(1);
            return 1;
        } else if (board->getBoard()[2] == -1) {
            displayWinner(-1);
            return -1;
        }
    }

    // check diag
    if (board->getBoard()[0] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[8]) {
        if (board->getBoard()[0] == 1) {
            displayWinner(1);
            return 1;
        } else if (board->getBoard()[0] == -1) {
            displayWinner(-1);
            return -1;
        }
    }
    
    if (board->getBoard()[2] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[6]) {
        if (board->getBoard()[2] == 1) {
            displayWinner(1);
            return 1;
        } else if (board->getBoard()[2] == -1) {
            displayWinner(-1);
            return -1;
        }
    }

    if (totalNumberOfMoves >= 81) {
        displayWinner(2);
		return 2;
    }

	return 0;
}

int GameManagement::displayWinner(int playerNumber) {
    if (playerNumber == 1)
		{
			cout << " -------------------------------------------\n";
			cout << " Player X wins!" << endl;
			cout << " -------------------------------------------\n";
			return 1;
		}
		else if (playerNumber == -1)
		{
			cout << " -------------------------------------------\n";
			cout << " Player O wins!" << endl;
			cout << " -------------------------------------------\n";
			return -1;
		}
		else if (playerNumber == 2)
		{
			cout << " -------------------------------------------\n";
			cout << " Draw game!" << endl;
			cout << " -------------------------------------------\n";
			return 0;
		}

	return 0;
}

    void GameManagement::swapPlayer(int &playerTurn) {
    if (playerTurn == 1)
			playerTurn = -1;
		else
		{
			playerTurn = 1;
		}
    };


#endif