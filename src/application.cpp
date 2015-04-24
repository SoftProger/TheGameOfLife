#include "application.h"
//#include <QThread>

using namespace std;

Application::Application()
{
}

void Application::exec()
{
    //input
    int w=0, h=0;
    string in;
    cout<<setw(47)<<"The Game of Life!"<<endl;
    cout<<setw(47)<<"By Andrew Puzankov"<<endl;
    cout<<"RULES:"<<endl;
    cout<<"1.Any live cell with fewer than two live neighbours dies, as if caused by under-population."<<endl
            <<"2.Any live cell with two or three live neighbours lives on to the next generation."<<endl
            <<"3.Any live cell with more than three live neighbours dies, as if by overcrowding."<<endl
            <<"4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction."<<
              endl<<endl;
    cout<<"Enter width of field from 3 to 76:(best values from 10 to 50)"<<endl<<">>";
    cin>>in;
    while( !(w=atoi(in.data())) || (w<=2 || w>76))
    {
        cout<<"Input error!"<<endl;
        cout<<"Enter width of field from 3 to 76:(best values from 10 to 50)"<<endl<<">>";
        cin>>in;
    }
    cout<<"Enter height of field from 3 to 56:(best values from 10 to 24)"<<endl<<">>";
    cin>>in;
    while(!(h=atoi(in.data())) || h<=2 || h>56)
    {
        cout<<"Input error!"<<endl;
        cout<<"Enter height of field from 3 to 56:(best values from 10 to 24)"<<endl<<">>";
        cin>>in;
    }
    //-------------------------------

    game.makeBoard(w, h, "X");
    game.printBoard();
    while (!game.isOver())
    {
        //QThread::msleep(20);
        game.clearBoard();
        game.makeGeneration();
        game.printBoard();
    }
    cout<<setw(45)<<"Game over! xD"<<endl<<lifeQuotes[rand()%18];
}

Application::~Application()
{

}

