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

#ifndef CELL_H
#define CELL_H
#include "cellstatus.h"
#include <string>

class Cell
{
    CellStatus m_status;
public:
    Cell(CellStatus status);
    CellStatus getStatus()const {return m_status;}
    void setStatus(CellStatus status);
    ~Cell();
};

#endif // CELL_H
