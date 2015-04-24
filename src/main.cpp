#include <QCoreApplication>
//#include "time.h"
//#include <cstdlib>
#include "application.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QCoreApplication a(argc, argv);
    Application app;
    app.exec();
    return a.exec();
}
