#include "board.h"

Board::Board()
{
}

void Board::initialize(int width, int height)
{
    if (d!=nullptr)
    {
        delete d;
    }
    d = new BoardImpl(width, height);
    initialized = true;
}

void Board::initialize(const Board &board)
{
    if (d!=nullptr)
    {
        delete d;
    }
    d = new BoardImpl(board.width(), board.height());
    for(int i=0;i<board.height(); i++)
    {
        for (int j=0; j<board.width();j++)
        {
            at(i,j)->setStatus(board.at(i,j)->getStatus());
        }
    }
    initialized = true;
}

Cell *Board::at(int x, int y) const
{
    return d->at(x, y);
}

bool Board::operator!=(const Board &right)
{
    {
        if (this->isInitialized())
        {
            for(int i=0;i<right.height(); i++)
            {
                for (int j=0; j<right.width();j++)
                {
                    if(at(i,j)->getStatus()!= right.at(i,j)->getStatus())
                        return true;
                }
            }
        }
        else if (!this->isInitialized())
            return true;
        return false;
    }
}

Board::~Board()
{
    delete d;
    d = nullptr;
    initialized = false;
}

