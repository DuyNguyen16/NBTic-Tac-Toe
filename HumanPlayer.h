#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "Player.h"

class HumanPlayer : public Player
{
public:
    void displayTurn();
};

void HumanPlayer::displayTurn()
{
    cout << " -------------------------------------------\n";
    cout << " Player " << "X" << " turn:\n";
    cout << " -------------------------------------------\n";
}

#endif