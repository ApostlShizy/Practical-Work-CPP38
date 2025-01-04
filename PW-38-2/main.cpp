#include "htmleditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HTMLEditor w;
    w.show();
    return a.exec();
}
