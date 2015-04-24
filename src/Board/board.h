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
