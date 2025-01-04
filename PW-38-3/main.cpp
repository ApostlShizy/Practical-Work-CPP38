#include "blurmaker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlurMaker w;
    w.show();
    return a.exec();
}
