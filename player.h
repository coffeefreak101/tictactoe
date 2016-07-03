#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player
{
public:
    Player();
    void setName();
    std::string getName();
    bool setSymbol();
    char getSymbol();
    std::string getNameSymbol();
private:
    std::string name;
    char symbol;
};

#endif // PLAYER_H
