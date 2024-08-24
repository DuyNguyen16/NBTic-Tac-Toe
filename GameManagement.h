#ifndef GameManagement_H_
#define GameManagement_H_

#include <iostream>
using namespace std;

struct GameManagement {
    void startGame();
    int gameStatus(TicTacToe *board);
    int displayWinner(int playerNumber);
    int checkRows(TicTacToe *board);
};

void GameManagement::startGame() {

    cout << " -------------------------------------------\n";
	cout << "        Nine Board Tic Tac Toe Game\n";
	cout << " -------------------------------------------\n";

}

int GameManagement::gameStatus(TicTacToe *board) {
    // check if board is full
	if (board->getNoOfMoves() >= 9) {
		return 2;
    }
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

	return 0;
}

int GameManagement::checkRows(TicTacToe *board) {
        // Check first row
    if (board->getBoard()[0] == board->getBoard()[1] && board->getBoard()[1] == board->getBoard()[2]) {
        if (board->getBoard()[0] == 1) {
            return 1;
        } else if (board->getBoard()[0] == -1) {
            return -1;
        }
    }

    // check second row
        if (board->getBoard()[3] == board->getBoard()[4] && board->getBoard()[4] == board->getBoard()[5]) {
        if (board->getBoard()[3] == 1) {
            return 1;
        } else if (board->getBoard()[0] == -1) {
            return -1;
        }
    }

    // check third row 
        if (board->getBoard()[6] == board->getBoard()[7] && board->getBoard()[7] == board->getBoard()[8]) {
        if (board->getBoard()[6] == 1) {
            return 1;
        } else if (board->getBoard()[0] == -1) {
            return -1;
        }
    }
    
    return 0;
};

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

#endif