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

#include "boardimpl.h"

BoardImpl::BoardImpl(int wdth, int hght):width(wdth), height(hght)
{
    cells.resize(width*height);
    for(int i=0;i<height; i++)
        for (int j=0; j<width;j++)
        {
            cells[i*width+j] = new Cell(rand()%2?ALIVE:DEAD);
        }
}

Cell *BoardImpl::at(int x, int y)const
{
    return cells[x*width+y];
}

BoardImpl::~BoardImpl()
{
    for(int i=0;i<height; i++)
        for (int j=0; j<width;j++)
            delete at(i, j);
}

