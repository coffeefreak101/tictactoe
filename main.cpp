#include <iostream>
#include "gameboard.h"
#include "player.h"

using namespace std;

int main()
{
    Player p1;
    Player p2;
    GameBoard game;

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "First Player: " << endl;
    p1.setName();
    while (!p1.setSymbol()) {
        cout << "Invalid symbol" << endl;
    }

    cout << "Second Player: " << endl;
    p2.setName();
    while (!p2.setSymbol() || p2.getSymbol() == p1.getSymbol()) {
        cout << "Invalid symbol" << endl;
    }

    game.setPlayer1(&p1);
    game.setPlayer2(&p2);

    while (!game.winner()) {
        game.nextTurn();
    }
    game.printBoard();
    cout << game.getWinner()->getName() << " is the winner!" << endl;

    return 0;
}
