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

#include "application.h"
#include <QThread>

using namespace std;

Application::Application()
{
}

void Application::exec()
{
    //input
    int w=0, h=0, msecSleep=0;
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
    w=atoi(in.data());
    while(w<=2 || w>76)
    {
        cout<<"Input error!"<<endl;
        cout<<"Enter width of field from 3 to 76:(best values from 10 to 50)"<<endl<<">>";
        cin>>in;
        w=atoi(in.data());
    }
    cout<<"Enter height of field from 3 to 56:(best values from 10 to 24)"<<endl<<">>";
    cin>>in;
    h=atoi(in.data());
    while(h<=2 || h>56)
    {
        cout<<"Input error!"<<endl;
        cout<<"Enter height of field from 3 to 56:(best values from 10 to 24)"<<endl<<">>";
        cin>>in;
        w=atoi(in.data());
    }

    cout<<"Enter sleep time between iterations from 1 to 100 (msec):(best values from 1 to 40)"<<endl<<">>";
    cin>>in;
    char *pEnd;
    msecSleep=strtol(in.data(),&pEnd,10);
    while(msecSleep <1 || msecSleep>100)
    {
        cout<<"Input error!"<<endl;
        cout<<"Enter sleep time between iterations from 1 to 100 (msec):(best values from 1 to 40)"<<endl<<">>";
        cin>>in;
        msecSleep=strtol(in.data(),&pEnd,10);
    }
    //-------------------------------

    game.makeBoard(w, h, 'X');
    game.clearBoard();
    game.printBoard();
    while (!game.isOver())
    {
#ifndef _WIN32
        game.clearBoard();
#endif
        game.makeGeneration();
#ifndef _WIN32
        game.printBoard();
#endif
        QThread::msleep(msecSleep);
    }
#ifdef _WIN32
    game.clearBoard();
    game.printBoard();
#endif
    cout<<setw(45)<<"Game over! xD"<<endl<<lifeQuotes[rand()%22];
}

Application::~Application()
{

}
