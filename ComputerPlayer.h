#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Player.h"

class ComputerPlayer : public Player
{
public:
    void displayTurn();
};

void ComputerPlayer::displayTurn()
{
    cout << " -------------------------------------------\n";
    cout << " Computer turn:\n";
    cout << " -------------------------------------------\n";
}

#endif