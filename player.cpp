#include "player.h"
#include <iostream>

using namespace std;

Player::Player()
{

}

void Player::setName()
{
    cout << "Enter your name: ";
    getline(cin, this->name);
}

string Player::getName()
{
    return this->name;
}

bool Player::setSymbol()
{
    string temp;
    cout << "What's your symbol?: ";
    getline(cin, temp);
    if (temp[0] != ' ') {
        this->symbol = temp[0];
        return true;
    }
    return false;
}

char Player::getSymbol()
{
    return this->symbol;
}

string Player::getNameSymbol()
{
    return this->name + " (" + this->symbol + ")";
}
