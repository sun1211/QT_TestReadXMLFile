#include "readxml.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReadXML w;
    w.show();

    return a.exec();
}
