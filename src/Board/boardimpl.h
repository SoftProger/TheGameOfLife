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
