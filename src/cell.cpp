#include "cell.h"

Cell::Cell(CellStatus status):m_status(status)
{
}

void Cell::setStatus(CellStatus status)
{
    m_status=status;
}

Cell::~Cell()
{

}

