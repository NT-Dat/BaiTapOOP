#include "player.h"

Player::Player()
{

}

string Player::GetName()
{
    return _name;
}

void Player::SetName(string value)
{
    _name = value;
}

void Player::Input()
{
    //cin.ignore();
    getline(cin, _name);
}

void Player::IncreStep()
{
    _step++;
}

int Player::GetStep()
{
    return _step;
}
