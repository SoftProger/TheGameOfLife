/*
    Copyright (C) 2015 Andrey Puzankov
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
