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

#ifndef BOARD_H
#define BOARD_H
#include "boardimpl.h"

class Board
{
    //class BoardImpl;
    BoardImpl *d = nullptr;
    bool initialized = false;
public:
    Board();
    void initialize(int width, int height);
    void initialize(const Board &board);
    Cell *at(int x, int y)const;
    int width()const {return d->width;}
    int height()const {return d->height;}
    bool isInitialized() {return initialized;}
    bool operator!=(const Board& right);

    ~Board();
};

#endif // BOARD_H
