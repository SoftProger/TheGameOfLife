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

