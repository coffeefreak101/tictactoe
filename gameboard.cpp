#include "gameboard.h"
#include <iostream>

using namespace std;

GameBoard::GameBoard()
{

}

void GameBoard::printBoard()
{
    int nums[] = {2, 1, 0};
    cout << endl;
    for (auto i : nums) {
        cout << i+1 << " " << this->boardSpots[0][i] << " | " << this->boardSpots[1][i] << " | " << this->boardSpots[2][i] << endl;
        if (i > 0) {
            cout << "  ---------" << endl;
        } else {
            cout << "  1   2   3" << endl;
            cout << endl;
        }
    }
}

bool GameBoard::setSpot(int x, int y, char c)
{
    char &spot = this->boardSpots[x][y];
    if (spot != ' ') {
        return false;
    }
    spot = c;
    return true;
}

void GameBoard::setAxis(int &x, char c)
{
    while (true) {
        cout << "Select a space (" << c << "): ";
        cin >> x;
        if (x > 0 && x < 4) {
            --x;
            break;
        } else {
            cout << "Invalid option, try again." << endl;
        }
    }
}

void GameBoard::nextTurn()
{
    Player *p = this->nextPlayer();
    int x = 0;
    int y = 0;

    this->printBoard();
    cout << p->getNameSymbol() << endl;
    while (true) {
        this->setAxis(x, 'x');
        this->setAxis(y, 'y');
        if (this->setSpot(x, y, p->getSymbol())) {
            break;
        } else {
            cout << "That spot is already taken!" << endl;
        }
    }
    if (!this->checkWinner(x, y, p)) {
        this->checkTie();
    }
}

bool GameBoard::winner()
{
    if (this->winPlayer) {
        return true;
    }
    return false;
}

bool GameBoard::checkWinner(int x, int y, Player *p)
{
    if (this->rowMatch(x) || this->colMatch(y) || this->diagMatch()) {
        this->winPlayer = p;
        return true;
    }
    return false;
}

void GameBoard::checkTie()
{
    int nums[] = {0, 1, 2};
    for (auto y : nums) {
        for (auto x : nums) {
            if (this->boardSpots[x][y] == ' ') {
                return;
            }
        }
    }
    cout << "Tie game. Resetting board" << endl;
    for (auto y : nums) {
        for (auto x : nums) {
            this->boardSpots[x][y] = ' ';
        }
    }
}

Player *GameBoard::getWinner()
{
    return this->winPlayer;
}

void GameBoard::setPlayer1(Player *p)
{
    this->p1 = p;
}

void GameBoard::setPlayer2(Player *p)
{
    this->p2 = p;
}

Player *GameBoard::nextPlayer()
{
    Player *next = nullptr;
    if (!this->next) {
        next = this->p1;
        this->next = this->p2;
    } else {
        next = this->next;
        next->getSymbol() == this->p1->getSymbol()? this->next = this->p2 : this->next = this->p1;
    }
    return next;

}

bool GameBoard::rowMatch(int r)
{
    if (this->boardSpots[r][0] == this->boardSpots[r][1] && this->boardSpots[r][0] == this->boardSpots[r][2]) {
        return true;
    }
    return false;
}

bool GameBoard::colMatch(int c)
{
    if (this->boardSpots[0][c] == this->boardSpots[1][c] && this->boardSpots[0][c] == this->boardSpots[2][c]) {
        return true;
    }
    return false;
}

bool GameBoard::diagMatch()
{
    if (this->boardSpots[1][1] == ' ') {
        return false;
    } else if (this->boardSpots[0][2] == this->boardSpots[1][1] && this->boardSpots[0][2] == this->boardSpots[2][0]) {
        return true;
    } else if (this->boardSpots[0][0] == this->boardSpots[1][1] && this->boardSpots[0][0] == this->boardSpots[2][2]) {
        return true;
    }
    return false;
}
