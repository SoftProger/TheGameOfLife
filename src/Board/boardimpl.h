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

#ifndef BOARDIMPL_H
#define BOARDIMPL_H
#include <QVector>
#include "cell.h"

class BoardImpl
{
    friend class Board;
    int width;
    int height;
    QVector<Cell* > cells;
    Cell *at(int x, int y) const;
public:
    BoardImpl(int wdth, int hght);
    ~BoardImpl();
};

#endif // BOARDIMPL_H
