#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <iomanip>
#include "Board/board.h"

class Game
{
    Board board;
    Board prevGeneration;
    std::string cellMarker;
public:
    Game();
    void makeBoard(int width, int height, std::string cell);
    void printBoard();
    void clearBoard();
    void makeGeneration();
    bool isOver();
    ~Game();
};

#endif // GAME_H
