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
