#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Player.h"

class ComputerPlayer : public Player
{
private:
public:
    ComputerPlayer(int x) : Player(x) {};
};

#endif