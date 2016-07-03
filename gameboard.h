#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "player.h"

class GameBoard
{
public:
    GameBoard();
    void printBoard();
    bool setSpot(int x, int y, char c);
    void setAxis(int &x, char c);
    void nextTurn();
    bool winner();
    bool checkWinner(int x, int y, Player *p);
    void checkTie();
    Player *getWinner();
    void setPlayer1(Player *p);
    void setPlayer2(Player *p);
    Player *nextPlayer();
private:
    char boardSpots[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    Player *winPlayer = nullptr;
    bool rowMatch(int r);
    bool colMatch(int c);
    bool diagMatch();
    Player *p1 = nullptr;
    Player *p2 = nullptr;
    Player *next = nullptr;
};

#endif // GAMEBOARD_H
