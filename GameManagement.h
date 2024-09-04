#ifndef GameManagement_H_
#define GameManagement_H_

#include <iostream>
using namespace std;

struct GameManagement {
    int startGame();
    int gameStatus(TicTacToe *board);
    int displayWinner(int playerNumber);
    void swapPlayer(int &playerTurn);
};

int GameManagement::startGame() {

    int mode = 0;
    while (true) {
        cout << " -------------------------------------------\n";
        cout << "        Nine Board Tic Tac Toe Game\n";
        cout << " -------------------------------------------\n";
        cout << "Select Game Mode: " << endl;
        cout << " -------------------------------------------\n";
        cout << "1. Human vs Human." << endl;
        cout << "2. Human vs Bot (Minimax)." << endl;
        cout << "3. Human vs Bot (Random)." << endl;
        cout << "4. Bot (Minimax) vs Bot (Random)." << endl;
        cout << " -------------------------------------------\n";
        cout << "Game Mode Number: ";
        cin >> mode;
        if (mode > 0 && mode < 5) {
            break;
        }
    }

    return mode;
}

int GameManagement::gameStatus(TicTacToe *board) {
    // check if board is full

    // cout << board->getBoard()[0];
    // Check first row
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

    if (board->getNoOfMoves() >= 9) {
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