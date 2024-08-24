#ifndef GameManagement_H_
#define GameManagement_H_

#include <iostream>
using namespace std;

struct GameManagement {
    void startGame();
};

void GameManagement::startGame() {

    cout << " -------------------------------------------\n";
	cout << "        Nine Board Tic Tac Toe Game\n";
	cout << " -------------------------------------------\n";

}

#endif