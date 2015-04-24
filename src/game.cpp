#include "game.h"

using namespace std;

Game::Game()
{

}

void Game::makeBoard(int width, int height, std::string cell)
{
    board.initialize(width, height);
    cellMarker = cell;
}

void Game::printBoard()
{
    if (board.isInitialized())
    {   
        //cout<<setw(board.width()*2)<<setfill('-')<<"-"<<endl;
        for(int i=0;i<board.height(); i++)
        {
            for (int j=0; j<board.width();j++)
            {
                //cout<<board.at(i,j)->cell();//<<"|";
                cout<<((board.at(i,j)->getStatus())?cellMarker:" ");
            }
            cout<<endl;
            //cout<<endl<<setw(board.width()*2)<<setfill('-')<<"-"<<endl;
        }
    }
    else
        cout<<"Board hasn't been initialized!"<<endl;
}

void Game::clearBoard()
{
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system ("clear");
#endif
}

void Game::makeGeneration()
{
    int ki;
    int kj;
    int newWidth;
    int newHeight;
    int aliveCounter=0;
    //int deadCounter = 8;
    prevGeneration.initialize(board);
    for(int i=0;i<board.height(); i++)
    {
        for (int j=0; j<board.width();j++)
        {

            ki=i-1;
            kj=j-1;
            if (ki>=0 && kj>=0)
            {
                //для клеток, начиная с {2,2} ну т.е с 1,1
                if (board.width()-j>1)
                    newWidth=kj+3;
                else
                    newWidth=kj+2;
                if (board.height()-i>1)
                    newHeight = ki+3;
                else
                    newHeight = ki+2;
                for (int k = ki;k<newHeight;k++)
                    for (int k2 = kj;k2<newWidth;k2++)
                    {
                        if (board.at(k, k2)->getStatus()==ALIVE && (k!=i || k2!=j) )
                            aliveCounter++;
                    }
            }
            else
            {
                //смотрим границы поля
                if (ki==-1 && kj==-1)
                {
                    ki++;
                    kj++;
                    newHeight=ki+2;
                    newWidth = kj+2;
                }
                else if (ki==-1 && kj>=0)
                {
                    ki++;
                    newHeight=ki+2;
                    newWidth=kj+3;
                    //if (board.height()-i>1)
                        //newHeight=ki+1;
                    if (board.width()-j<=1)
                        newWidth = kj+2;

                }
                else if(kj==-1 && ki>=0)
                {
                    kj++;
                    newHeight=ki+3;
                    newWidth=kj+2;
                    if (board.height()-i<=1)
                        newHeight = ki+2;

                }
                for (int k=ki;k<newHeight;k++)
                    for(int k2=kj;k2<newWidth;k2++)
                        if (board.at(k, k2)->getStatus()==ALIVE && (k!=i || k2!=j) )
                            aliveCounter++;

            }
            //deadCounter-=aliveCounter;
            //cout<<aliveCounter<<endl;
            if (board.at(i,j)->getStatus()==ALIVE && (aliveCounter>3 || aliveCounter<2))
                board.at(i,j)->setStatus(DEAD);
            else if(board.at(i,j)->getStatus()==DEAD && aliveCounter==3)
                board.at(i,j)->setStatus(ALIVE);
            aliveCounter = 0;
            //deadCounter=8;
        }
    }
}

bool Game::isOver()
{
    if(!(prevGeneration!=board))
        return true;

    for(int i=0;i<board.height(); i++)
    {
        for (int j=0; j<board.width();j++)
        {
            if (board.at(i,j)->getStatus()==ALIVE)
                return false;
        }
    }
    return true;
}

Game::~Game()
{

}

